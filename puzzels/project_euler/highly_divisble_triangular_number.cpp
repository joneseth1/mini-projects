#include <iostream>




int main()
{
    
    int N = 6; 
    int j = N;
    int sum = N;

    while(j != 1)
    {   
        j = j - 1;
        sum += j;
    }

    std::cout << sum << std::endl;

    return 0;
}



