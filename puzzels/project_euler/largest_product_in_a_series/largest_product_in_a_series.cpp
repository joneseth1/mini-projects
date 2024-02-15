#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem> // Include the filesystem library for path handling

std::vector<int> NUMBERS;

int main() {
    std::string filePath = "C:\\programs\\random-fun\\mini-projects\\puzzels\\project_euler\\largest_product_in_a_series\\digit.txt";
    std::cout << "File path: " << filePath << std::endl; // Print the file path
    
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "ERROR opening the file" << std::endl;
        return 1;
    } else { 
        int num; 
        while (inputFile >> num) {
            NUMBERS.push_back(num);
            std::cout << "YES" << std::endl;
        }
        inputFile.close();
    }

    for (int i = 0; i < NUMBERS.size(); ++i) {
        std::cout << NUMBERS[i] << std::endl;
    }

    return 0;
}
