#include <iostream>

int main()
{
    int k;

    std::cin >> k;
    std::cout << "\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << k << " x " << i << " = " << k * i << "\n";
    }

    return 0;
}