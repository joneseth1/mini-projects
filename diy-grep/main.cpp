#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


namespace fs = std::filesystem;


void searchFile(const fs::path& filename, const std::string& pattern) {
	// Opens the file 
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Couldn't open file " << filename << std::endl;
        return;
    }

    // Read the file line by line
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        
        // Search for the pattern in the line 
        size_t found = line.find(pattern);
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
	// Makes sure there is the correct number of args 
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path> <pattern>" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    std::string pattern = argv[2];


    // Logic to determine if the arg is a file or subdir 
    if (fs::is_directory(path)) {
        searchDirectory(path, pattern);
    } else {
        searchFile(path, pattern);
    }

    return 0;
}
