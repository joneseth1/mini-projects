#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <regex>

namespace fs = std::filesystem;

int searchFile(const fs::path& filename, const std::string& pattern, bool caseInsensitive) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open file " + filename.string());
    }

    std::string line;
    int lineNumber = 0;
    int matchCount = 0;

    while (std::getline(file, line)) {
        lineNumber++;

        std::string lineCopy = line;
        std::string patternCopy = pattern;

        if (caseInsensitive) {
            std::transform(lineCopy.begin(), lineCopy.end(), lineCopy.begin(), ::tolower);
            std::transform(patternCopy.begin(), patternCopy.end(), patternCopy.begin(), ::tolower);
        }

        size_t found = lineCopy.find(patternCopy);
        if (found != std::string::npos) {
            matchCount++;
        }
    }

    file.close();
    return matchCount;
}

int searchDirectory(const fs::path& path, const std::string& pattern) {
    int totalMatchCount = 0;

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            totalMatchCount += searchDirectory(entry.path(), pattern);
        } else if (entry.is_regular_file()) {
            try {
                totalMatchCount += searchFile(entry.path(), pattern, false);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    return totalMatchCount;
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " <path> <pattern> [case-insensitive]" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    std::string pattern = argv[2];
    bool caseInsensitive = false;

    if (argc == 4 && std::string(argv[3]) == "case-insensitive") {
        caseInsensitive = true;
    }

    try {
        int totalMatchCount = 0;

        if (fs::is_directory(path)) {
            totalMatchCount = searchDirectory(path, pattern);
        } else {
            totalMatchCount = searchFile(path, pattern, caseInsensitive);
        }

        std::cout << "Total matches found: " << totalMatchCount << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "Search complete.\n";
    return 0;
    //TEST
}