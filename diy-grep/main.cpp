#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void searchFile(const fs::path& filename, const std::string& pattern) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Couldn't open file " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        size_t found = line.find(pattern);
        if (found != std::string::npos) {
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
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path> <pattern>" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    std::string pattern = argv[2];

    if (fs::is_directory(path)) {
        searchDirectory(path, pattern);
    } else {
        searchFile(path, pattern);
    }

    return 0;
}
