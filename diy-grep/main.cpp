#include <iostream>
#include <fstream>
#include <string>

void grep(const std::string& filename, const std::string& pattern) {
    std::ifstream file(filename);
    std::string line;
    int line_number = 1;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        if (line.find(pattern) != std::string::npos) {
            std::cout << filename << ":" << line_number << ": " << line << std::endl;
        }
        line_number++;
    }

    file.close();
}


int main(int argc, char* argv[]) {

	std::cout << "Test12" << std::endl;
	return 0;
}