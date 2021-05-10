#include <iostream>

int main()
{
    int a, b;
    int sum = 0;

    std::cin >> a >> b;

    for (; a <= b; a++) {
        sum += a;
    }

    std::cout << "\n" << sum << "\n";

    return 0;
}