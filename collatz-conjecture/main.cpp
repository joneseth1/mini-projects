#include <iostream>



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
 




int main(){
	pseudoRandomCollatz(42, 5); 
}