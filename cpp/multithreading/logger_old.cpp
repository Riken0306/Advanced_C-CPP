#include "logger_old.h"

LogBuffer_c logBuffer(BUFFER_CAPACITY);

// Simulated logging function to generate log entries
void logGenerator(int id) {
    std::string logMessages[] = {
        "Application started.",
        "Warning: Low memory.",
        "Error: File not found.",
        "Info: Task completed successfully.",
        "Error: Invalid input."
    };

    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        logBuffer.app_log_stringf(SYSLOG_LEVEL_TYPE_ERROR, "RIKEN ", logMessages[i % 5]);
    }
}

void logWriter() {
    std::mutex localMutex; // Mutex for the condition variable
    std::ofstream logFile("log.txt");
    //std::ofstream logFile("log.txt", std::ios::app); //To append in File

    while (true) {
        LogEntry_t entry;

        // Wait for the log buffer to have entries
        std::unique_lock<std::mutex> lock(localMutex);
        logBuffer.cv.wait(lock, [] { return !logBuffer.isEmpty(); });


        // Consume log entries from the buffer and write to the file
        // Task2 - Implement multiple poping upon one notify
        while (logBuffer.pop(entry)) {
            std::ostringstream oss;
            auto timestamp = std::chrono::system_clock::to_time_t(entry.timestamp);
            std::string timeStr = std::ctime(&timestamp);  // Convert to string
            timeStr.pop_back();

            oss << "[" << timeStr << "] ";
            oss << "[" << logLevelStr[entry.level] << "] ";
            oss << entry.message;

            logFile << oss.str();
            std::cout << oss.str();
        }
    }

    logFile.close();
    std::cout << "Logging complete!" << std::endl;
}

int main() {

    int numGenerators = 3; // Number of log-generating threads
    std::vector<std::thread> logGenerators;

    // Create worker threads for log generation
    for (int i = 0; i < numGenerators; ++i) {
        logGenerators.push_back(std::thread(logGenerator, i));
    }

    // Create the log writer thread
    std::thread logger(logWriter);

    // Join the log generator threads
    for (auto& generator : logGenerators) {
        generator.join();
    }

    while (true)
    {
        //FSM
    }

    //Will never be called
    //Put this in SIGTERM so on Ctrl-c this will execute
    // After all log generators are done, signal the logger to finish
    //done = true;
    //cv.notify_all(); // Notify the logger to process remaining messages

    // Join the log writer thread
    logger.join();

    return 0;
}
