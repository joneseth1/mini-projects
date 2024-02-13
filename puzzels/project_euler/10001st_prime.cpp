#include <iostream>
#include <cmath>

bool is_prime(int n)
{
    if (n <= 1) {
        return false; // 0 and 1 are not prime 
    }
    
    int sqr_root = sqrt(n);
    for (int i = 2; i <= sqr_root; i++)
    {
        if (n % i == 0)
        {
            return false; // n is divisible by i, hence not a prime
        }
    }
    return true; // if no factor found, n is prime
}

int main()
{
    int number = 25;
    if (is_prime(number)) {
        std::cout << number << " is a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}
