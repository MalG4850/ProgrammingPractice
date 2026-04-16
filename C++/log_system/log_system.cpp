#include <iostream>
#include <fstream>
#include <string>

void writeLog(std::string message) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (!logFile) { throw std::string("Error: Could not open log.txt\n\n"); }
    logFile << message << std::endl;
    logFile.close();
}

int main(void) {
    try {
        writeLog("Testing logfile system...");
        std::cout << "Log written successfully!";
    }
    catch (std::string& error) {
        std::cout << "Couldn't write log.\n\n";
        std::cout << error << "\n\n";
    }

    return 0;
}
