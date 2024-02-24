#include <iostream>

// Function to calculate the number of divisors
int countDivisors(long long n) {
    int divisors = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors += (i * i == n) ? 1 : 2;
        }
    }
    return divisors;
}

int main() {
    long long triangular_number = 0;
    int i = 1;

    while (true) {
        triangular_number += i;
        int divisors = countDivisors(triangular_number);
        if (divisors > 500) {
            std::cout << "The first triangular number with over 500 divisors is: " << triangular_number << std::endl;
            break;
        }
        ++i;
    }

    return 0;
}


