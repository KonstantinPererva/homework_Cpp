#include<iostream>

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Введите два чила: ";
	int a;
    int b;
    int c;

    std::cin >> a >> b;
    std::cout << "\n";

    (a > b) ? c = a : c = b;

    for (int i = 1; i <= c; i++)
        if (a % i == 0 && b % i == 0) std::cout << i << "\n";
}
