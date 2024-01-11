#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <regex>

namespace fs = std::filesystem;

void searchFile(const fs::path& filename, const std::string& pattern, bool caseInsensitive) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open file " + filename.string());
    }

    std::string line;
    int lineNumber = 0;

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
            // Print colorized output (for demonstration purposes)
            std::cout << "\033[1;31mFound at line " << lineNumber << " in file " << filename << ": " << line << "\033[0m\n";
        }
    }

    file.close();
}

void searchDirectory(const fs::path& path, const std::string& pattern) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            searchDirectory(entry.path(), pattern);
        } else if (entry.is_regular_file()) {
            try {
                searchFile(entry.path(), pattern, false); // Disable case-insensitivity for directories
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
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
        if (fs::is_directory(path)) {
            searchDirectory(path, pattern);
        } else {
            searchFile(path, pattern, caseInsensitive);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "Search complete.\n";
    return 0;
}
