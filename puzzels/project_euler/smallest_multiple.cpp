#include <iostream>

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to find the smallest positive number evenly divisible by all numbers from 1 to n
int smallestDivisible(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = lcm(result, i);
    }
    return result;
}

int main() {
    int n = 19;
    std::cout << "The smallest positive number evenly divisible by all numbers from 1 to 20" << " is: ";
    std::cout << smallestDivisible(n) << std::endl;
    return 0;
}
