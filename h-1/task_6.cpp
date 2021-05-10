#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    float v,t,a;

    std::cout << "Вычислить пройденное расстояние при прямолинейном равноускоренном движении" << "\n\n"; 
    std::cout << "Введите скорость движения: "; 
    std::cin >> v;
    std::cout << "Введите время пройденного расстояния: "; 
    std::cin >> t;
    std::cout << "Введите значение ускорения: ";
    std::cin >> a;
    std::cout << "\n"; 

    float s = v * t + (a * t * t) / 2;

    std::cout << "Пройденное расстояние: " << s << "\n\n"; 

    return 0;
}