#include<iostream>

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Введите чило: ";
	int a;
	std::cin >> a;
	std::cout << "\n";

	for (int i = 1; i <= a; ++i)
		if (a % i == 0) std::cout << i << "\n";
}
