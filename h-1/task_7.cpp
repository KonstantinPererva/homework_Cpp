#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    float s, t;

    std::cout << "Введите расстояние до аэропорта (км): ";
    std::cin >> s;
    std::cout << "\n";
    std::cout << "Введите время за которое нужно доехать (мин): ";
    std::cin >> t;
    std::cout << "\n\n";

    float h = t / 60; // в часах

    float v = s / h;

    std::cout << "Скорость, с которой нужно ехать: " << v << "(км/ч)" << "\n\n";
    
    return 0;
}