#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


namespace fs = std::filesystem;


// Searches file for key word that is needed to be searched 
void searchFile(const fs::path& filename, const std::string& pattern, bool caseInsensitive) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Couldn't open file " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;

        std::string lineCopy = line;
        std::string patternCopy = pattern;

        if (caseInsensitive) {
            // Convert both the line and pattern to lowercase (or uppercase)
            std::transform(lineCopy.begin(), lineCopy.end(), lineCopy.begin(), ::tolower);
            std::transform(patternCopy.begin(), patternCopy.end(), patternCopy.begin(), ::tolower);
        }

        // Search for the pattern in the line
        size_t found = lineCopy.find(patternCopy);
        if (found != std::string::npos) {
            // Print the line if the pattern is found
            std::cout << "Found at line " << lineNumber << " in file " << filename << ": " << line << std::endl;
        }
    }

    file.close();
}

void searchDirectory(const fs::path& path, const std::string& pattern) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            searchDirectory(entry.path(), pattern);  // Recursively search subdirectories
        } else if (entry.is_regular_file()) {
            searchFile(entry.path(), pattern);
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

    if (fs::is_directory(path)) {
        searchDirectory(path, pattern, caseInsensitive);
    } else {
        searchFile(path, pattern, caseInsensitive);
    }

    return 0;
}