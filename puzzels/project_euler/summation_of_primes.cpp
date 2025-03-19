#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long PRIME_SUM = 0; // Use long long to handle larger sums

    for (int i = 2; i < 2000000; i++) { // Start from 2, as 0 and 1 are not prime
        if (isPrime(i)) {
            PRIME_SUM += i;
        }
    }

    std::cout << PRIME_SUM << std::endl;

    return 0;
}
