#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    float s,c,g1,g2,g3;

    std::cout << "Введите расстояние (км): "; 
    std::cin >> s;
    std::cout << "Введите расход бензина на 100 км: "; 
    std::cin >> c;
    std::cout << "Введите стоимость бензина АИ-80: ";
    std::cin >> g1;
    std::cout << "Введите стоимость бензина АИ-92: ";
    std::cin >> g2;
    std::cout << "Введите стоимость бензина АИ-95: ";
    std::cin >> g3;
    std::cout << "\n"; 

    std::cout << "сравнительная таблица стоимости поездки на " << s << "км" << "\n\n"; 
    std::cout << "АИ-80: " << (s * c / 100 * g1) << "грн" << "\n";
    std::cout << "АИ-92: " << (s * c / 100 * g2) << "грн" << "\n";
    std::cout << "АИ-95: " << (s * c / 100 * g3) << "грн" << "\n\n\n";

    return 0;
}