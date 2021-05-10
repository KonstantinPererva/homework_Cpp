#include<iostream>

int main() {
    const int n = 7;
    int arr[n] = {54,36,45,26,89,41,27};
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++) {
        if (max < arr[i]) max = arr[i];

        if (min > arr[i]) min = arr[i];
    }

    std::cout << "Max: " << max << "\n";
    std::cout << "Min: " << min << "\n";
}
