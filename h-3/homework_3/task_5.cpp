#include<iostream>

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Введите чило: ";
	int a;
	std::cin >> a;
	std::cout << "\n";

	for (int b = 1; b <= a; ++b) {
		if ((a % (b * b) == 0) && (a % (b * b * b) != 0))
			std::cout << b << "\n";
	}
}
