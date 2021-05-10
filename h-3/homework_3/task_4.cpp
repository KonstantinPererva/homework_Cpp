#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    long int newNum = 0;
    long int num;

    std::cout << "Введите число: ";
    std::cin >> num;
    std::cout << "\n";

    for (; num > 0; num /= 10) {
        if (num % 10 != 3 && num % 10 != 6) {
            newNum *= 10;
            newNum += num % 10;
        }
    }

    std::cout << "Новое число: ";

    for (; newNum > 0; newNum /= 10)
        std::cout << newNum % 10;

    std::cout << "\n";
}
