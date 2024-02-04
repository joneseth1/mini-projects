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


int main() {
    int n = 20;
    std::cout << "The smallest positive number evenly divisible by all numbers from 1 to " << n << " is: ";
    std::cout << smallestDivisible(n) << std::endl;
    return 0;
}
