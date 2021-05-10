#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru");

    int a, b;
    
    std::cin >> a >> b;

    if (a > b) {
        int c;
        c = a;
        a = b;
        b = c;
    }

    std::cout << "\n";

    std::cout << "Четные числа:" << "\n";

    for (int i = a; i <= b; i++) {
        if (!(i % 2)) {
            std::cout << i << "\n";
        }
    }

    std::cout << "\n";
    std::cout << "Нечетные числа:" << "\n";

    for (int i = a; i <= b; i++) {
        if (i % 2) {
            std::cout << i << "\n";
        }
    }

    std::cout << "\n";
    std::cout << "Числа кратные семи:" << "\n";

    for (int i = a; i <= b; i++) {
        if (!(i % 7)) {
            std::cout << i << "\n";
        }
    }

    return 0;
}