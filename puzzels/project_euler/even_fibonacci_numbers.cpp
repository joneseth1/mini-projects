//https://projecteuler.net/problem=2

#include <iostream>

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




int main() 
{
	int n = 4000000;
	calc_fib(n);
	return 0;
}