#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    
    float square,length,radius;
    const float PI = 3.14;

    std::cout << "Найти площадь круга зная длину окружности" << "\n\n"; 
    std::cout << "Введите значение длины окружности: "; 
    std::cin >> length;
    std::cout << "\n"; 

    radius = length / (2 * PI);
    square = radius * radius * PI;

    std::cout << "Площадь круга равна: " << square << "\n\n"; 

    return 0;
}