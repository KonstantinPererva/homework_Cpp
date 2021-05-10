#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");

	int const n = 10;
	int arr[n]{ -3, 5, -4, 9, 7, 2, -6, -8, 3, 6 };

	int sumNegative = 0;
	int prodPositive = 1;

	for (int i = 0; i < n; ++i)
		(arr[i] < 0) ? sumNegative += arr[i] : prodPositive *= arr[i];

	std::cout << "Сумма отрицательных элементов = " << sumNegative << "\n\n";
	std::cout << "Произведение элементов с четными номерами = " << prodPositive << "\n\n";

	int min = 0;
	int max = 0;

	for (int i = 0; i < n; ++i)
	{
		if (arr[max] < arr[i]) max = i;

		if (arr[min] > arr[i]) min = i;
	}

	int prodMinMax = 1;
	int c;

	if (max < min) {
		c = max;
		max = min;
		min = c;
	}

	for (int i = min + 1; i < max; ++i)
		prodMinMax *= arr[i];

	std::cout << "Произведение элементов, находящихся между min и max элементами = " << prodMinMax << "\n\n";

	int negativeFirst = 0;
	int negativeLast = 0;
	bool flag = true;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0) {
			if (flag) {
				negativeFirst = i;
				flag = false;
			}

			negativeLast = i;
		}
	}

	int sum = 0;

	for (int i = negativeFirst + 1; i < negativeLast; ++i)
		sum += arr[i];

	std::cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами = " << sum << "\n\n";
}