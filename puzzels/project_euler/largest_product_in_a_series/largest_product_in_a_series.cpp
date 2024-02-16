#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> NUMBERS;






void findLargestProduct(std::vector<int> numbers) {

	std::vector<int> lucky13; 
	int j = 0; 
	for (int i = 0; i < numbers.size(); ++i) {
		if (j <= 13) {
			lucky13.push_back(i);
			j++; 
		} else {
			for (int num : lucky13) {
				if (i > num) {
					lucky13.push_back(i);
				}
			}
		} 
	}
	for (int num : lucky13) {
		std::cout << num << std::endl; 
	}
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

    // int maxProduct = findLargestProduct(NUMBERS);
    // std::cout << "Max is: " << maxProduct << std::endl;


    return 0;
}
