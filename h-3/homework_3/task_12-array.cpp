#include<iostream>

int main() {
    setlocale(LC_ALL, "ru");

    const int n = 12;
    double arr[n];

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Прибыль месяца " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::cout << "\n";

    int d1;
    int d2;

    std::cout << "Диапазон месяцев: " << "\n";
    std::cin >> d1 >> d2;
    std::cout << "\n";

    --d1;
    --d2;

    int max = d1;
    int min = d1;

    for (int i = d1; i <= d2; ++i)
    {
        if (arr[max] < arr[i]) max = i;

        if (arr[min] > arr[i]) min = i;
    }

    std::cout << "Максимальная прибыль в месяце " << max + 1 << "\n";
    std::cout << "Минимальная прибыль в месяце " << min + 1 << "\n";
}
