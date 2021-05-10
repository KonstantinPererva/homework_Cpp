#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru");

    int a;
    int sum = 0;

    std::cin >> a;

    while (a != 0) {
        sum += a;

        std::cin >> a;
    }

    std::cout << "\n" << "Сумма введенных чисел = " << sum << "\n";

    return 0;
}