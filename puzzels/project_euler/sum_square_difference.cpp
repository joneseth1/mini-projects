#include <iostream>
#include <cmath>



void sum_squares(int n)
{
	int sum = 0;

	for (int i = 0; i <= n; i++)
	{
		sum += pow(i,2);
	}


	std::cout << sum << std::endl;
}





int main()
{
	// what the sum should sum too 
	int n = 100; 
	sum_squares(n);
}