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


void collatz(int n)
{
    auto start_time = high_resolution_clock::now(); // Record the start time

    while (n != 1)
    {
        std::cout << n << " ";
        if (n % 2 == 0)
        {
            n = n / 2;
        } 
        else {
            n = 3 * n + 1;
        }
    }

    std::cout << "Num: " << n << std::endl;
    // auto end_time = high_resolution_clock::now(); // Record the end time
    // auto duration = duration_cast<milliseconds>(end_time - start_time); // Calculate the duration

    // std::cout << "\nRandom Number: " << duration.count() << std::endl;
}


int main() {
    int cursor = get_mouse_pos();
    
    auto currentTimePoint = system_clock::now();
    auto currentTimeInSeconds = duration_cast<seconds>(currentTimePoint.time_since_epoch()).count();

    long long seed = (currentTimeInSeconds * cursor);

    std::cout << "Seed: " << seed << std::endl;

    collatz(seed); 

    return 0;
}
