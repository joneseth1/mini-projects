#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> prime;

void generate_primes(int limit) {
    for (int n = 2; prime.size() < limit; ++n) {
        bool is_prime = true;
        int sqr_root = sqrt(n);
        for (int i = 2; i <= sqr_root; ++i) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            prime.push_back(n);
        }
    }
}

int main() {
    int prime_index = 10001; 
    generate_primes(prime_index); 
    
    std::cout << "The " << prime_index << "st prime number is: " << prime.back() << std::endl;

    return 0;
}
