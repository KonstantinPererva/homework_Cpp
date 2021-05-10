#include<iostream>

void numberDigits(int a) {
    int counter = 0;

    for (int i = a; i > 0; i /= 10)
        ++counter;

    std::cout << "\n" << "Количество цифр числа: " << counter << "\n";
}

void sumDigits(int a) {
    int sum = 0;

    for (int i = a; i > 0; i /= 10)
        sum += i % 10;

    std::cout << "\n" << "Сумма цифр числа: " << sum << "\n";
}

void arithmeticMeanDigits(int a) {
    double counter = 0;
    double sum = 0;

    for (int i = a; i > 0; i /= 10) {
        ++counter;
        sum += i % 10;
    }
        
    double m = sum / counter;

    std::cout << "\n" << "Среднее арифметическое цифр числа: " << m << "\n";
}

void NumberZeros(int a) {
    int counter = 0;

    for (int i = a; i > 0; i /= 10)
        if (i % 10 == 0) ++counter;

    std::cout << "\n" << "Количество нулей в этом числе: " << counter << "\n";
}

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Введите чило: ";

	int a;

    std::cin >> a;
    std::cout << "\n";

    std::cout << "Выберите дальнейшее действие с этим числом:" << "\n\n";

    std::cout << "Количество цифр числа --> введите 1" << "\n";
    std::cout << "Сумма цифр числа --> введите 2" << "\n";
    std::cout << "Среднее арифметическое цифр числа --> введите 3" << "\n";
    std::cout << "Количество нулей в этом числе --> введите 4" << "\n\n";

    int b;

    std::cin >> b;

    switch (b) {
    case 1: 
        numberDigits(a);
        break;
    case 2: 
        sumDigits(a);
        break;
    case 3: 
        arithmeticMeanDigits(a);
        break;
    case 4: 
        NumberZeros(a);
        break;
    default:
        break;
    }
}
