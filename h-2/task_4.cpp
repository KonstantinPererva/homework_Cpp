#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru");

    int a;
    int p = 1;

    std::cin >> a;

    while (!(a >= 1 && a <= 20)) {
        std::cout << "¬ведите число меньшее 20 " << "\n";
        std::cin >> a;
    }

    for (; a <= 20; a++) {
        p *= a;
    }

    std::cout << p;

    return 0;
}