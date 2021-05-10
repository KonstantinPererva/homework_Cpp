#include <iostream>

int main() {
	int counter = 0;

	for (int i = 100; i <= 999; ++i) {
		int b = 0;
		int c = i;

		for (int a = i; a > 0; a /= 10) {
			b = a % 10;

			if (b != c) { 
				c = b; 
			}
			else {
				++counter;
				break;
			}
		}
	}

	std::cout << counter << "\n";
}
