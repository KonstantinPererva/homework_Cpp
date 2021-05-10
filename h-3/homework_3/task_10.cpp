#include<iostream>

int main() {
    int h = 8;
    int w = 8;
    int r = 3;

    for (int i = 0; i < h; i++) {
        for (int m = 0; m < r; ++m) {
            char cell_1 = (i % 2) ? '-' : '*';
            char cell_2 = (i % 2) ? '*' : '-';

            for (int j = 0; j < w / 2; ++j) {
                for (int k = 0; k < r; ++k)
                    std::cout << cell_1;

                for (int k = 0; k < r; ++k)
                    std::cout << cell_2;
            }

            std::cout << "\n";
        }
    }
}