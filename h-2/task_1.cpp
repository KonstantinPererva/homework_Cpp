#include <iostream>

int main()
{
    int a;
    int result = 0;

    std::cin >> a;

    for(; a <= 500; a++)
    {
        result += a;
    }

    std::cout << "\n" << result << "\n";

    return 0;
}