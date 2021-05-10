#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    
    float r1,r2,r3;

    std::cout << "Вычисление значения сопротивления R0 по формуле:" << "\n\n\t" << "1/R0 = 1/R1+1/R2+1/R3" << "\n\n"; 
    std::cout << "Введите значение сопротивления для R1: "; 
    std::cin >> r1;
    std::cout << "Введите значение сопротивления для R2: "; 
    std::cin >> r2;
    std::cout << "Введите значение сопротивления для R3: "; 
    std::cin >> r3;
    std::cout << "\n"; 

    float r0 = 1 / (1/r1 + 1/r2 + 1/r3);
    
    std::cout << "Значение сопротивления R0 составляет: " << r0 << "\n\n"; 

    return 0;
}