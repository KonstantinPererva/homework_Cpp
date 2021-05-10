#include <iostream>

void outLinePartTel(int tel) {
    int repeatCount = 5;

    for (int i = 1; i <= repeatCount; i++) {
        std::cout << "| "<< tel << " ";

        if (i == repeatCount) {
            std::cout << "|" << std::endl;
        } 
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "Срочно продам автомобиль" << "\n";
    std::cout << "Марка: Mazda" << "\n";
    std::cout << "Модельный ряд: CX-7" << "\n";
    std::cout << "-------------------------" << "\n";
    std::cout << "Тел.: 222-33-44" << "\n";
    std::cout << "-------------------------" << "\n";

    int partTel = 3;
    int numberTel[partTel] = {22,33,44};

    for (int j = 0; j < partTel; j++) {
        outLinePartTel(numberTel[j]);
    }

    std::cout << "\n";
    
    return 0;
}