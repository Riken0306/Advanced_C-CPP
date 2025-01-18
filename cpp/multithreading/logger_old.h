/**
 * @file
 * logger_old.h
 * Prototypes, structures and Classes for the logger module.
 *
 *	Created on: 18 January, 2025
 *		Author: Riken
 */

#ifndef LOGGER_OLD_H
#define LOGGER_OLD_H

#include <iostream>
#include <ostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#define BUFFER_CAPACITY 10
#define LOG_FILE_PATH   "log.txt"

// Define log levels
#define SYSLOG_LEVELS \
    X(SYSLOG_LEVEL_TYPE_ERROR,      "ERROR")    \
    X(SYSLOG_LEVEL_TYPE_EXCEP,      "EXCEP")    \
    X(SYSLOG_LEVEL_TYPE_WARNING,    "WARNING")  \
    X(SYSLOG_LEVEL_TYPE_INFO,       "INFO")     \
    X(SYSLOG_LEVEL_TYPE_DEBUG,      "DEBUG")    \
    X(SYSLOG_LEVEL_TYPE_ENTER,      "ENTER")    \

typedef enum {
    #define X(name, str) name,
    SYSLOG_LEVELS
    #undef X
    SYSLOG_LEVEL_TYPE_MAX = 0xFF  // Used as a boundary
} LogLevel_e;

static const char *logLevelStr[] = {
    #define X(name, str) str,
    SYSLOG_LEVELS
    #undef X
};

#define LOG_LEVEL_TO_STRING(level) \
    (((level) <= SYSLOG_LEVEL_TYPE_ENTER) ? logLevelStr[(level)] : "UNKNOWN")

// Log entry structure
typedef struct {
    LogLevel_e level;
    std::string message;
    std::chrono::system_clock::time_point timestamp;
}LogEntry_t;

// Log Buffer Class for Managing Log Entries
class LogBuffer_c {
public:
    LogBuffer_c(size_t capacity) : capacity(capacity), writeIndex(0), readIndex(0), buffer(capacity) {}

    //Templated cannot be defined in .cpp
    //Templates are not functions in the traditional sense;
    //they are blueprints that generate functions at compile-time
    template <typename... Args>
    void app_log_stringf(LogLevel_e level, Args&&... args)
    {
        std::ostringstream oss;
        (oss<<...<<args);

        LogEntry_t entry = {level, oss.str(), std::chrono::system_clock::now()};

        // Try to push the log entry into the buffer
        while (!push(entry)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Buffer is full, retry
            std::cout << "Not able to push" << std::endl;
        }
        cv.notify_one();  // Notify the log writer thread
    }

    void app_log_hexdump(LogLevel_e level, uint8_t *data, uint16_t size);

    friend void logFlushTask();

private:
    size_t capacity;
    size_t writeIndex;
    size_t readIndex;
    std::vector<LogEntry_t> buffer;
    std::mutex mutex;
    std::condition_variable cv;

    bool push(const LogEntry_t& entry);
    bool pop(LogEntry_t& entry);
    bool isEmpty();
};

extern LogBuffer_c logBuffer;
#define APP_LOG_STRINGF(level, ...) logBuffer.app_log_stringf(level, __VA_ARGS__)
#define APP_LOG_HEXDUMP(level, data, size) logBuffer.app_log_hexdump(level, data, size)

void logFlushTaskInit();

#endif
