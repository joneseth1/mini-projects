#include <iostream>

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to calculate the LCM of numbers from 1 to n
int lcmOfRange(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = lcm(result, i);
    }
    return result;
}

int main() {
    int n = 20;
    std::cout << "The smallest positive number evenly divisible by all numbers from 1 to " << n << " is: ";
    std::cout << lcmOfRange(n) << std::endl;
    return 0;
}
