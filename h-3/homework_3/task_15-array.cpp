#include <iostream>

int main()
{
	const int n = 10;
	int arr_1[n] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr_2[n] = { 5,9,7,3,8,2,0,1,6,4 };
	int arrSum[n];

	for (int i = 0; i < n; ++i)
		arrSum[i] = arr_1[i] + arr_2[i];
}