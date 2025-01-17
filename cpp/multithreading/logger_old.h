#include <iostream>
#include <ostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>

#define BUFFER_CAPACITY 10

// Define log levels
typedef enum {
    INFO,
    WARNING,
    ERROR
}LogLevel_e;

// Log entry structure
typedef struct {
    LogLevel_e level;
    std::string message;
    std::chrono::system_clock::time_point timestamp;
}LogEntry_t;

extern std::condition_variable cv;

// Ring Buffer for log entries
class LogBuffer_c {
public:
    LogBuffer_c(size_t capacity) : capacity(capacity), writeIndex(0), readIndex(0), buffer(capacity) {}

    bool push(const LogEntry_t& entry) {
        std::lock_guard<std::mutex> lock(mutex);
        if ((writeIndex + 1) % capacity == readIndex) {  // Buffer is full
            return false;
        }
        buffer[writeIndex] = entry;
        writeIndex = (writeIndex + 1) % capacity;
        return true;
    }

    bool pop(LogEntry_t& entry) {
        std::lock_guard<std::mutex> lock(mutex);
        if (writeIndex == readIndex) {  // Buffer is empty
            return false;
        }
        entry = buffer[readIndex];
        readIndex = (readIndex + 1) % capacity;
        return true;
    }

    bool isEmpty() {
        std::lock_guard<std::mutex> lock(mutex);
        return writeIndex == readIndex;
    }

    //Task1 Tommorow
    //Implement app_log_stringf() which can be called from any thread like std::cout << message;
    template <typename... Args>
    void app_log_stringf(LogLevel_e level, Args&&... args) {
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

private:
    size_t capacity;
    size_t writeIndex;
    size_t readIndex;
    std::vector<LogEntry_t> buffer;
    std::mutex mutex;
    //std::condition_variable cv;
};

extern LogBuffer_c logBuffer;
