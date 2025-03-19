#include <iostream>

int main() {
    const int targetSum = 1000;

    for (int a = 1; a < targetSum; ++a) {
        for (int b = a + 1; b < targetSum; ++b) {
            int c = targetSum - a - b;
            if (a * a + b * b == c * c) {
                std::cout << "Pythagorean triplet: " << a << ", " << b << ", " << c << std::endl;
                std::cout << "Sum: " << a + b + c << std::endl;
                return 0; 
            }
        }
    }

    std::cout << "No Pythagorean triplet found for the sum " << targetSum << std::endl;
    return 0;
}
