#include <iostream>
#include <cmath>

int PRIME_SUM = 0;

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
    for (int i = 0; i < 2000000; i++) {
        if (isPrime(i)) {
            PRIME_SUM += i;
        }
    }

    std::cout << PRIME_SUM << std::endl;
    return 0;
}
