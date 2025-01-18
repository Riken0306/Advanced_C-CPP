#include <iostream>

#include "logger_old.h"

using namespace std;

// Simulated logging function to generate log entries
void logProducerTask(int id) {
    std::string logMessages[] = {
        "Application started.",
        "Warning: Low memory.",
        "Error: File not found.",
        "Info: Task completed successfully.",
        "Error: Invalid input."
    };

    uint8_t data[] ={   0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x11, 0x22, 0x33, 0x44, 0x55,
                        0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x11, 0x22, 0x33, 0x44, 0x55,
                        0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x11, 0x22, 0x33, 0x44, 0x55,
                        0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x11, 0x22, 0x33, 0x44, 0x55,
                    };

    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate work
        APP_LOG_STRINGF(SYSLOG_LEVEL_TYPE_ERROR, "RIKEN ", logMessages[i % 5]);
        APP_LOG_HEXDUMP(SYSLOG_LEVEL_TYPE_DEBUG, data, sizeof(data));
    }
}

int main()
{
    int numGenerators = 3; // Number of log-generating threads
    std::vector<std::thread> logGenerators;

    // Create worker threads for log generation
    for (int i = 0; i < numGenerators; ++i) {
        logGenerators.push_back(std::thread(logProducerTask, i));
    }

    logFlushTaskInit();

    // Join the log generator threads
    for (auto& generator : logGenerators) {
        generator.join();
    }

    while (true)
    {
        //FSM
    }

    return 0;

}
