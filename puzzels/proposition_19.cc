#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> divisors(201);

    for (int i = 1; i <= 200; ++i)
    {
        for (int j = 1; j <= 200; ++j)
        {
            if (i % j == 0)
            {
                divisors[i].push_back(j);
            }
        }
    }

    // Displaying the divisors
    for (int i = 1; i <= 200; ++i)
    {
        std::cout << "Divisors of " << i << ": ";
        for (int divisor : divisors[i])
        {
            std::cout << divisor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
