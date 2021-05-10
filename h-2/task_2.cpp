#include <iostream>

int main()
{
    int x, y;

    std::cin >> x >> y;
    
    int result = x;

    for(int i = 1; i < y; i++)
    {
        result *= x;
    }

    std::cout << "\n" << result << "\n";

    return 0;
}