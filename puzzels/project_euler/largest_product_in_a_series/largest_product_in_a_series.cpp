#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> NUMBERS;

int main() {
    std::string filePath = "digit.txt";
    
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "ERROR opening the file" << std::endl;
        return 1;
    } else { 
        char digit; 
        while (inputFile.get(digit)) { // Read characters one by one
            if (isdigit(digit)) {
                int num = digit - '0'; // Convert char to int
                NUMBERS.push_back(num);
                std::cout << "YES" << std::endl;
            }
        }
        inputFile.close();
    }

    return 0;
}
