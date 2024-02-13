#include <iostream>
#include <cmath>



int sum_squares(int n)
{
	int sum = 0;

	for (int i = 0; i <= n; i++)
	{
		sum += pow(i,2);
	}


	return sum;
}

int square_sum(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	return pow(sum,2);
}



int main()
{
	// what the sum should sum too 
	int n = 100; 
	int sum_square = sum_squares(n);
	int square_sums = square_sum(n);

	std::cout << square_sums - sum_square << std::endl;
	return 0;
}