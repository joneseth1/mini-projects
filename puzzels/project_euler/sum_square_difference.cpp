#include <iostream>
#include <cmath>

long better_summing(int n)
{
    int sum = (n * (n + 1)) / 2;
    int sum_sq = (n * (n + 1) * (2 * n + 1)) / 6;

    return (pow(sum, 2)) - sum_sq;
}



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
	int n = 100; 
	int sum_square = sum_squares(n);
	int square_sums = square_sum(n);
	int better_sum = better_summing(n);

	std::cout << better_sum << std::endl;
	return 0;
}