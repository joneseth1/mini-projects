#include <iostream>

// Linear Congruential Generator
class CustomPseudoRandom {
private:
    unsigned int seed;
    const unsigned int a = 1664525;
    const unsigned int c = 1013904223;
    const unsigned int m = 4294967295;  

public:
    CustomPseudoRandom(unsigned int seed) : seed(seed) {}

    unsigned int getNext() {
        seed = (a * seed + c) % m;
        return seed;
    }
};

// Collatz Conjecture
void collatz(unsigned int n) {
    while (n != 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    std::cout << "1\n";
}

// Pseudo-random Collatz
void pseudoRandomCollatz(unsigned int seed, int iterations) {
    CustomPseudoRandom generator(seed);
    for (int i = 0; i < iterations; ++i) {
        unsigned int n = generator.getNext() % 100 + 1;  // Limit to 1-100 for variety
        std::cout << "Starting Collatz sequence with seed " << n << ":\n";
        collatz(n);
        std::cout << "\n";
    }
}

int main() {
    pseudoRandomCollatz(42, 5);

    return 0;
}
