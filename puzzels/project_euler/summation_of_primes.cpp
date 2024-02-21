#include <iostream>
#include <vector>
#include <cmath>

// int PRIME_SUM = 0;

// bool isPrime(int num) {
//     if (num <= 1) {
//         return false;
//     }
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }


void magic() {
    double n = -100; 
    std::vector<int> num_list; 
    bool bol = true;


    while(bol) {
        bol = true;
        n += 1; 
        num_list.push_back(n);
        if (n == 100)
        {
            bol = false;
        }
        std::cout << n << std::endl;
    }
}


int main() {
    // for (int i = 0; i < 2000000; i++) {
    //     if (isPrime(i)) {
    //         PRIME_SUM += i;
    //     }
    // }

    // std::cout << PRIME_SUM << std::endl;



    magic();
    return 0;
}
