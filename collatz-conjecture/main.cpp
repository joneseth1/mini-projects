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
 




int main(){
	return 0; 
}