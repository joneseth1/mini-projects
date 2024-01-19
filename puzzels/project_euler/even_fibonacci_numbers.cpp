//https://projecteuler.net/problem=2

#include <iostream>
#include <vector>


// Basic Implementation
void calc_fib(int n) 
{
	long long  a = 0, b = 1, sum = 0;
	
	while (b <= n)
	{
		if (b % 2 == 0)
		{
			sum += b;
		}
		long long temp = a + b;
		a = b;
		b = temp;
	}
	
	std::cout << "Sum is: " << sum << std::endl; 
}


// More intensive implementation 

std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    int size = a.size();
    std::vector<std::vector<long long>> result(size, std::vector<long long>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}











int main() 
{
	int n = 4000000;
	
	return 0;
}