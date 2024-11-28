#include <iostream>

long long largestPrimeFactor(long long n) {
    long long largestFactor = -1;

    // Divide by 2 until n is odd
    while (n % 2 == 0) {
        largestFactor = 2;
        n /= 2;
    }

    // n must be odd
    // Start checking odd factors from 3
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        largestFactor = n;
    }

    return largestFactor;
}

int main() {
    long long number = 600851475143;
    std::cout << "The largest prime factor of " << number << " is " << largestPrimeFactor(number) << std::endl;
    return 0;
}
