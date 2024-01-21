#include <iostream>
#include <Windows.h>
#include <chrono>

using namespace std::chrono;


int get_mouse_pos()
{
    while(true)
    {
        POINT p;
        if (GetCursorPos(&p))
        {
            return p.x;
        }
        Sleep(1000);
    }
}


std::pair<int, int> collatz_prng(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        count++;
        }
        
    }

    return std::make_pair(n, count);
}



int main() {
    int cursor = get_mouse_pos();
    
    auto currentTimePoint = system_clock::now();
    auto currentTimeInSeconds = duration_cast<seconds>(currentTimePoint.time_since_epoch()).count();

    long long seed = (currentTimeInSeconds / cursor);

    std::cout << "Seed: " << seed << std::endl;
    // Use Collatz as a PRNG and get the count
    std::pair<int, int> result = collatz_prng(seed);

    std::cout << "End Number: " << result.first << std::endl;
    std::cout << "Random Number: " << result.second << std::endl;

    return 0;
}
