#include <iostream>

void figure_1() {
    int row = 12; 
    int star = 12;
    int startPrintStar = star;
    int startIndent = 0;

    for (int i = 0; i < row; ++i) {
        for (int k = 0; k < startIndent; ++k)
            std::cout << " ";

        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        --startPrintStar;
        ++startIndent;

        std::cout << "\n";
    }
}

void figure_2() {
    int row = 12;
    int star = 12;
    int startPrintStar = 1;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        ++startPrintStar;

        std::cout << "\n";
    }
}

void figure_3() {
    int row = 12;
    int star = 11;
    int startPrintStar = star;
    int startIndent = 0;

    for (int i = 0; i < row; ++i) {
        if (i < row / 2) {
            for (int k = 0; k < startIndent; ++k)
                std::cout << " ";

            for (int j = 0; j < startPrintStar; ++j)
                std::cout << "*";

            startPrintStar -= 2;
            ++startIndent;
        }

        std::cout << "\n";
    }
}

void figure_4() {
    int row = 12;
    int star = 11;
    int startPrintStar = 1;
    int startIndent = star / 2;

    for (int i = 0; i < row; ++i) {
        if (i >= row / 2) {
            for (int k = 0; k < startIndent; ++k)
                std::cout << " ";

            for (int j = 0; j < startPrintStar; ++j)
                std::cout << "*";

            startPrintStar += 2;
            --startIndent;
        }

        std::cout << "\n";
    }
}

void figure_5() {
    int row = 12;
    int star = 11;

    int startPrintStar = star;
    int startIndent = 0;

    for (int i = 0; i < row; ++i) {
        for (int k = 0; k < startIndent; ++k)
            std::cout << " ";

        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        if (i < row / 2 - 1) {
            startPrintStar -= 2;
            ++startIndent;
        }
        else if (i == row / 2 - 1) {
            startPrintStar = 1;
            startIndent = star / 2;
        }
        else {
            startPrintStar += 2;
            --startIndent;
        }

        std::cout << "\n";
    }
}

void figure_6() {
    int row = 11;
    int star = 12;

    int startPrintStar = 1;
    int startIndent = star - 2;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        for (int k = 0; k < startIndent; ++k)
            std::cout << " ";

        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        startPrintStar = (i < row / 2) ? ++startPrintStar : --startPrintStar;

        startIndent = (i < row / 2) ? startIndent -= 2 : startIndent += 2;

        std::cout << "\n";
    }
}

void figure_7() {
    int row = 11;
    int star = 12;

    int startPrintStar = 1;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        (i < row / 2) ? ++startPrintStar : --startPrintStar;

        std::cout << "\n";
    }
}

void figure_8() {
    int row = 11;
    int star = 12;

    int startPrintStar = 1;
    int startIndent = star - 1;

    for (int i = 0; i < row; ++i) {
        for (int k = 0; k < startIndent; ++k)
            std::cout << " ";

        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        startPrintStar = (i < row / 2) ? ++startPrintStar : --startPrintStar;

        startIndent = (i < row / 2) ? startIndent -= 1 : startIndent += 1;

        std::cout << "\n";
    }
}

void figure_9() {
    int row = 12;
    int star = 12;
    int startPrintStar = star;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        --startPrintStar;

        std::cout << "\n";
    }
}

void figure_10() {
    int row = 12;
    int star = 12;
    int startPrintStar = 1;
    int startIndent = star - 1;

    for (int i = 0; i < row; ++i) {
        for (int k = 0; k < startIndent; ++k)
            std::cout << " ";

        for (int j = 0; j < startPrintStar; ++j)
            std::cout << "*";

        ++startPrintStar;
        --startIndent;

        std::cout << "\n";
    }
}

void figureSelection(int num) {
    switch (num) {
        case 1:
            figure_1();
            break;      
        case 2:         
            figure_2();
            break;
        case 3:
            figure_3();
            break;
        case 4:
            figure_4();
            break;
        case 5:
            figure_5();
            break;
        case 6:
            figure_6();
            break;
        case 7:
            figure_7();
            break;
        case 8:
            figure_8();
            break;
        case 9:
            figure_9();
            break;
        case 10:
            figure_10();
            break;
        default:
            break;
    }
}

int main() {
    setlocale(LC_ALL,"ru");

    std::cout << "Введите номер фигуры от 1 до 10: ";

    int a;

    std::cin >> a;
    std::cout << "\n";

    while (a) {
        figureSelection(a);

        std::cout << "\n" << "Введите номер фигуры от 1 до 10: ";
        std::cin >> a;
        std::cout << "\n";
    }
}
