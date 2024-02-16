#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> NUMBERS;




long long findLargestProduct(const std::vector<int>& numbers) {
    long long maxProduct = 0;

    for (size_t i = 0; i < numbers.size() - 12; ++i) {
        long long product = 1;
        for (int j = 0; j < 13; ++j) {
            product *= numbers[i + j];
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }

    return maxProduct;
}





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
            }
        }
        inputFile.close();
    }

    long long maxProduct = findLargestProduct(NUMBERS);
    std::cout << "Max product of 13 consecutive numbers is: " << maxProduct << std::endl;

    return 0;
}

