#include <iostream>

int main()
{
    int sum = 0;

    for (int i = 1; i <= 1000; i++) {
        sum += i;
    }

    std::cout << sum / 1000;

    return 0;
}