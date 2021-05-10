#include <iostream>

int main() {
	int counter = 0;

	for (int i = 100; i <= 999; ++i) {
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;

		num1 = i / 100;
		num2 = (i / 10) % 10;
		num3 = i % 10;

		if (num1 != num2 && num2 != num3 && num1 != num3) ++counter;
	}

	std::cout << counter << "\n";
}
