/**
 * @file
 * logger_old.cpp
 * Implementation of Logger Functions
 *
 *	Created on: 18 January, 2025
 *		Author: Riken
 */

#include "logger.h"

LogBuffer_c logBuffer(BUFFER_CAPACITY);

bool LogBuffer_c::push(const LogEntry_t& entry) {
    std::lock_guard<std::mutex> lock(mutex);
    if ((writeIndex + 1) % capacity == readIndex) {  // Buffer is full
        return false;
    }
    buffer[writeIndex] = entry;
    writeIndex = (writeIndex + 1) % capacity;
    return true;
}

bool LogBuffer_c::pop(LogEntry_t& entry) {
    std::lock_guard<std::mutex> lock(mutex);
    if (writeIndex == readIndex) {  // Buffer is empty
        return false;
    }
    entry = buffer[readIndex];
    readIndex = (readIndex + 1) % capacity;
    return true;
}

bool LogBuffer_c::isEmpty() {
    std::lock_guard<std::mutex> lock(mutex);
    return writeIndex == readIndex;
}

void LogBuffer_c::app_log_hexdump(LogLevel_e level, uint8_t *data, uint16_t size) {
    std::ostringstream oss;
    oss << std::hex << std::uppercase << std::setfill('0');  // Set hex format and uppercase
    oss << std::endl;
    for(int i = 0; i < size; i++)
    {
        if(i % 16 == 0 && i != 0)
            oss << std::endl;

        oss << "0x" << std::setw(2) << static_cast<int>(data[i]) << " ";
    }
    oss << std::endl;

    LogEntry_t entry = {level, oss.str(), std::chrono::system_clock::now()};

    // Try to push the log entry into the buffer
    while (!push(entry)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Buffer is full, retry
        std::cout << "Not able to push" << std::endl;
    }
    cv.notify_one();  // Notify the log writer thread
}

void logFlushTask() {
    std::mutex localMutex; // Mutex for the condition variable
    std::ofstream logFile(LOG_FILE_PATH);

    while (true) {
        LogEntry_t entry;

        // Wait for the log buffer to have entries
        std::unique_lock<std::mutex> lock(localMutex);
        logBuffer.cv.wait(lock, [] { return !logBuffer.isEmpty(); });


        // Consume log entries from the buffer and write to the file
        while (!logBuffer.isEmpty()) {
            logBuffer.pop(entry);
            lock.unlock();
            std::ostringstream oss;
            auto timestamp = std::chrono::system_clock::to_time_t(entry.timestamp);
            std::string timeStr = std::ctime(&timestamp);  // Convert to string
            timeStr.pop_back();

            oss << "[" << timeStr << "] ";
            oss << "[" << logLevelStr[entry.level] << "] ";
            oss << entry.message;

            logFile << oss.str() << std::endl;
            std::cout << oss.str() << std::endl;
            lock.lock();
        }

    }

    logFile.close();
    std::cout << "Logging complete!" << std::endl;
}

void logFlushTaskInit() {
    // Create the log writer thread
    std::thread logger(logFlushTask);
    logger.detach();
}

