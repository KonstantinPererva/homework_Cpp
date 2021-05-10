#include<iostream>

int main() {
	setlocale(LC_ALL, "ru");

	int a;
	int sum = 0;

	std::cout << "Введите число: " << "\n";
	std::cin >> a;
	std::cout << "\n";

	for (int i = a; i > 0; i /= 10)
		sum += i % 10;

	if (sum * sum * sum == a * a) 
		std::cout << "Число подходит" << "\n";
	else 
		std::cout << "Число не подходит" << "\n";
}
