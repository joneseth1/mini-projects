#include <iostream>
#include <vector>
#include <cmath>

int main() {
    const int MAX_NUMBER = 200;
    std::vector<std::vector<int>> divisors(MAX_NUMBER + 1);

    for (int i = 1; i <= MAX_NUMBER; ++i) {
        int limit = std::sqrt(i);
        for (int j = 1; j <= limit; ++j) {
            if (i % j == 0) {
                divisors[i].push_back(j);
                if (j != i / j) {
                    divisors[i].push_back(i / j);
                }
            }
        }
    }

    // Displaying the divisors
    for (int i = 1; i <= MAX_NUMBER; ++i) {
        std::cout << "Divisors of " << i << ": ";
        for (int divisor : divisors[i]) {
            std::cout << divisor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
