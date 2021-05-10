#include <iostream>

int main()
{
	const int n = 10;
	int arr[n] = { 0,1,2,3,4,5,6,7,8,9 };

	const int h = 5;
	int arr_1[h];
	int arr_2[h];

	for (int i = 0; i < n; ++i)
		(i < h) ? arr_1[i] = arr[i] : arr_2[i - h] = arr[i];
}