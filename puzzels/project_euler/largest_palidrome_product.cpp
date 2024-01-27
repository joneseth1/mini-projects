#include <iostream>
using namespace std;

// Function to check if a number is palindrome
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int largestPalindrome = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product <= largestPalindrome) {
                // If the product is less than or equal to the largest palindrome found so far,
                // then there is no need to continue checking for smaller products.
                break;
            }
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }

    cout << "The largest palindrome made from the product of two 3-digit numbers is: " << largestPalindrome << endl;

    return 0;
}
