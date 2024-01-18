//https://projecteuler.net/problem=2

#include <iostream>

void calc_fib(int n) 
{
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) 
	{
		b = a + b;
		a = b - a;
	}
}




int main() 
{
	int n = 4000000;
	calc_fib(n);
	return 0;
}