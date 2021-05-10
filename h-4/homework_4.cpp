#include <iostream>
#include <iomanip>
//==================
// Многомерные массивы
//==================

void Task_1() {
    /*Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: 
    пользователь вводит число (например, 3) первый элемент массива принимает значение этого числа, 
    последующий элемент массива принимает значение этого числа умноженного на 2 (т.е. 6 для нашего примера), 
    третий элемент массива предыдущий элемент, умноженный на 2 (т.е. 6*2=12 для нашего примера). 
    Созданный массив вывести на экран.*/

    int x;
    std::cin >> x;
    std::cout << "\n";

    int arr[2][5];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << (arr[i][j] = x) << "\t";
            x *= 2;
        }
    }
            
    std::cout << "\n";
}

void Task_2() {
    /*Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: 
    пользователь вводит число (например, 3) первый элемент массива принимает значение этого числа, 
    последующий элемент массива принимает значение этого числа + 1 (т.е. 4 для нашего примера), 
    третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего примера). 
    Созданный массив вывести на экран.*/

    int x;
    std::cin >> x;
    std::cout << "\n";

    int arr[2][5];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << (arr[i][j] = x) << "\t";
            x += 1;
        }
    }

    std::cout << "\n";
}

void Task_3() {
    /*Создайте двухмерный массив. 
    Заполните его случайными числами и покажите на экран. 
    Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз). 
    Выполнить сдвиг массива и показать на экран полученный результат. 
    Сдвиг циклический.*/

    const int col = 5;
    const int row = 4;
    int arr[row][col]{ {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20} };

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j)
            std::cout << arr[i][j] << "\t";

        std::cout << "\n";
    }

    std::cout << "\n";

    int shift;
    char direction;

    std::cout << "Move by ... ";
    std::cin >> shift;
    std::cout << "Right or left? (R or L)" << "\n";
    std::cout << "Up or down? (U or D) ... ";
    std::cin >> direction;
    std::cout << "\n\n";

    int shift_x = shift % col;
    int shift_y = shift % row;

    switch (direction)
    {
    case 'R':
    case 'L':
        if (!shift_x) break;

        for (size_t i = 0; i < row; ++i)
            for (size_t n = 0; n < shift_x; ++n)
                for (size_t j = 0; j < col - 1; ++j)
                    (direction == 'R') ? std::swap(arr[i][col - j - 2], arr[i][col - j - 1]) : std::swap(arr[i][j], arr[i][j + 1]);

        break;

    case 'U':
    case 'D':
        if (!shift_y) break;

        for (size_t n = 0; n < shift_y; ++n)
            for (size_t i = 0; i < row - 1; ++i)
                for (size_t j = 0; j < col; ++j)
                    (direction == 'D') ? std::swap(arr[row - i - 2][j], arr[row - i - 1][j]) : std::swap(arr[i][j], arr[i + 1][j]);

        break;
    }

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j)
            std::cout << arr[i][j] << "\t";

        std::cout << "\n";
    }
}

void Task_4() {
    /*В двумерном массиве целых числе посчитать:
        --- Сумму всех элементов массива
        --- Среднее арифметическое всех элементов массива
        --- Минимальный элемент
        --- Максимальный элемент*/

    const int col = 5;
    const int row = 4;
    int arr[row][col]{ {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20} };

    double sum = 0;
    double mean;
    int min = arr[0][0];
    int max = arr[0][0];

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            sum += arr[i][j];
            if (min > arr[i][j]) min = arr[i][j];
            if (max < arr[i][j]) max = arr[i][j];
        }
    }

    mean = sum / (row * col);

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n";
    std::cout << "Arithmetical mean: " << mean << "\n";
}

void Task_5() {
    /*В двумерном массиве целых чисел посчитать сумму элементов: в каждой строке; в каждом столбце; одновременно по всем строкам и всем столбцам.
    Оформить следующим образом:
    3   5  6   7 | 21
    12  1  1   1 | 15
    0   7  12  1 | 20
    -----------------
    15  13 19  9 | 56
    */

    const int col = 4;
    const int row = 3;
    int arr[row][col]{ {3,5,6,7}, {12,1,1,1}, {0,7,12,1} };

    int sum = 0;
    int sumVert = 0;

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            sum += arr[i][j];
            std::cout << arr[i][j] << " ";
        }

        std::cout << "|" << " " << sum << "\n";
        sumVert += sum;
        sum = 0;
    }

    std::cout << "---------------" << "\n";

    for (size_t i = 0; i < col; ++i) {
        for (size_t j = 0; j < row; ++j)
            sum += arr[j][i];

        std::cout << sum << " ";
        sum = 0;
    }

    std::cout << "|" << " " << sumVert << "\n";
}

void Task_6() {
    /*Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.
    Первый массив заполняется случайными числами, в диапазоне от 0 до 50. 
    Второй массив заполняется по следующему принципу: первый элемент второго массива равен сумме первого и второго элемента первого массива, 
    второй элемент второго массива равен сумму третьего и четвертого элемента первого массива.*/

    const int row_1 = 5;
    const int col_1 = 10;
    int arr_1[row_1][col_1];

    const int row_2 = 5;
    const int col_2 = 5;
    int arr_2[row_2][col_2];

    for (size_t i = 0; i < row_1; ++i)
        for (size_t j = 0; j < col_1; ++j)
            arr_1[i][j] = 1 + std::rand() % 50;

    for (size_t i = 0; i < row_2; ++i)
        for (size_t j = 0; j < col_2; ++j)
            arr_2[i][j] = arr_1[i][j * 2] + arr_1[i][j * 2 + 1];
}

//==================
// Функции
//==================

int powNum(int num, int pow) {
    if (pow == 0) return 1;
    if (pow == 1) return num;

    int result = num;

    for (int i = 1; i < pow; ++i)
        result *= num;

    return result;
}

int sumNum(int x, int y) {
    int sum = 0;

    for (size_t i = x + 1; i < y; ++i)
        sum += i;

    return sum;
}

void perfectNumber(int x, int y) {
    for (int i = x + 1; i < y; ++i) {
        int result = 0;

        for (int j = 1; j < i; ++j)
            if (!(i % j))
                result += j;

        if (result == i)
            std::cout << result << " \n";
    }
}

void lucky(int x) {
    int sum_1 = 0;
    int sum_2 = 0;
    int counter = 0;

    for (; x > 0; x /= 10, counter++)
        (counter < 3) ? sum_1 += (x % 10) : sum_2 += (x % 10);


    if (sum_1 == sum_2)
        std::cout << "this number is lucky" << "\n";
    else
        std::cout << "this number is unlucky" << "\n";
}

void mean(int* arr, int len) {
    int sum = 0;

    for (size_t i = 0; i < len; ++i)
    {
        sum += arr[i];
    }

    double mean = sum / len;

    std::cout << mean << "\n";
}

void definingNum(int* arr, int len) {
    int positive = 0;
    int negative = 0;
    int zero = 0;

    for (size_t i = 0; i < len; ++i) {
        if (arr[i] > 0) ++positive;
        else if (arr[i] < 0) ++negative;
        else ++zero;
    }

    std::cout << "positive numbers: " << positive << "\n";
    std::cout << "negative numbers: " << negative << "\n";
    std::cout << "zero: " << zero << "\n";
}

void printCard(int num, int suit )
{
    char card[13] = { 'A','2','3','4','5','6','7','8','9','0','J','Q','K' };
    std::cout << " ___________________" << "\n";
    std::cout << "|                   |" << "\n";
    if (num == 10)std::cout << "|" << std::setw(3) << "1" << card[num - 1] << std::setw(16) << "|" << "\n";
    else std::cout << "|" << std::setw(3) << card[num - 1] << std::setw(17) << "|" << "\n";
    std::cout << "|                   |" << "\n";
    std::cout << "|                   |" << "\n";
    std::cout << "|                   |" << "\n";
    std::cout << "|                   |" << "\n";
    switch (suit) {
        case 1: std::cout << "|" << std::setw(12) << "HEART" << std::setw(8) << "|" << "\n";
            break;
        case 2: std::cout << "|" << std::setw(13) << "DIAMOND" << std::setw(7) << "|" << "\n";
            break;
        case 3: std::cout << "|" << std::setw(12) << "CLUB" << std::setw(8) << "|" << "\n";
            break;
        case 4: std::cout << "|" << std::setw(12) << "SPADE" << std::setw(8) << "|" << "\n";
            break;
    }
    std::cout << "|                   |" << "\n";
    std::cout << "|                   |" << "\n";
    std::cout << "|                   |" << "\n";
    std::cout << "|                   |" << "\n";
    if (num == 10)std::cout << "|" << std::setw(16) << "1" << card[num - 1] << std::setw(3) << "|" << "\n";
    else std::cout << "|" << std::setw(17) << card[num - 1] << std::setw(3) << "|" << "\n";
    std::cout << "|___________________|" << "\n";
}

void Task_7() {
    /*Написать функцию, которая принимает два параметра: 
    основание степени и показатель степени, 
    и вычисляет степень числа на основе полученных данных.*/


    int a, b;
    std::cout << "Enter the number ... ";
    std::cin >> a;
    std::cout << "Enter the power of this number ... ";
    std::cin >> b;

    std::cout << "\n" << "Result: " << powNum(a, b) << "\n";
}

void Task_8() {
    /*Написать функцию, которая получает в качестве параметров 2 целых числа 
    и возвращает сумму чисел из диапазона между ними.*/

    int a, b;
    std::cout << "Enter the number ... ";
    std::cin >> a;
    std::cout << "Enter the second number ... ";
    std::cin >> b;

    std::cout << "\n" << "Result: " << sumNum(a, b) << "\n";
}

void Task_9() {
    /*Число называется совершенным, если сумма всех его делителей равна ему самому. 
    Напишите функцию поиска таких чисел во введенном интервале.*/

    int a, b;
    std::cout << "Enter the number ... ";
    std::cin >> a;
    std::cout << "Enter the second number ... ";
    std::cin >> b;
    std::cout << "\n";

    perfectNumber(a, b);
}

void Task_10() {
    /*Написать функцию, выводящую на экран переданную ей игральную карту.*/
    int a, s;
    std::cout << "\t\t" << "Card value:";
    std::cout << "\n" << "1 - Ace" << "\n" << "2 - Two" << "\n" << "3 - Three" << "\n" << "4 - Four" << "\n" << "5 - Five" << "\n" << "6 - Six" << "\n" << "7 - Seven" << "\n" << "8 - Eight" << "\n" << "9 - Nine" << "\n" << "10 - Ten" << "\n" << "11 - Jacket" << "\n" << "12 - Quin" << "\n" << "13 - King" << "\n\n";
    std::cout << "Input a card value ... ";
    std::cin >> a;
    std::cout << "\n\n\t\t" << "Card suits" << "\n" << "1 - Heart." << "\n" << "2 - Diamond" << "\n" << "3 - Club" << "\n" << "4 - Spade" << "\n\n";
    std::cout << "Input a card suit ... ";
    std::cin >> s;

    printCard(a,s);
}

void Task_11() {
    /*Написать функцию, которая определяет, является ли «счастливым» шестизначное число.*/
    int a;
    std::cout << "Enter the number ... ";
    std::cin >> a;
    std::cout << "\n";

    lucky(a);
}

void Task_12() {
    /*Написать функцию, которая принимает две даты (т.е. функция принимает шесть параметров) 
    и вычисляет разность в днях между этими датами. 
    Для решения этой задачи необходимо также написать функцию, которая определяет, является ли год високосным.*/
}

void Task_13() {
    /*Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.*/
    const int length = 5;
    int arr[length]{ 1,2,3,4,5 };
    
    mean(arr, length);
}

void Task_14() {
    /*Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.*/
    const int length = 10;
    int arr[length]{ -1,2,-3,0,5,-9,3,0,4,9 };

    definingNum(arr, length);
}

int main() {
    Task_1();
}