#include <iostream>
#include <ctime>
#include <iomanip>

// Рекурсия
int divisor(int a, int b) {
    if (a == b)
        return a;

    return (a > b) ? divisor(a - b, b) : divisor(a, b - a);
}

void task_1() {
/*Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.*/
    int x,y;

    std::cin >> x >> y;

    std::cout << divisor(x, y) << "\n";
}

void numberBullsAndCows(int a, int b) {
    int arr_1[4];
    int arr_2[4];
    int matr[4][4];
    int counterCows = 0;
    int counterBulls = 0;

    for (size_t i = 0; i < 4; ++i) {
        arr_1[i] = a % 10;
        arr_2[i] = b % 10;
        a /= 10;
        b /= 10;
    }
    
    for (size_t i = 0; i < 4; ++i)
        for (size_t j = 0; j < 4; ++j)
            (arr_1[i] == arr_2[j]) ? matr[i][j] = 1 : matr[i][j] = 0;
    
    for (size_t i = 0; i < 4; ++i) {
        int sum = 0;

        for (size_t j = 0; j < 4; ++j){
            sum += matr[i][j];
            if (matr[i][j] == 1) (i == j) ? ++counterCows : ++counterBulls;
        }
        
        if (sum > 1)  
            counterBulls -= (sum - 1);
    }

    std::cout << "Cows: " << counterCows << "\t\t";
    std::cout << "Bulls: " << counterBulls << "\n\n";
}

void numCheck(int a ) {
    static int counter = 0;
    int b;
    std::cout << "Enter the number: ";
    std::cin >> b;
    std::cout << "\n";

    std::cout << "+++  " << "Try: " << (++counter) << "  +++" << "\n\n";

    if (a == b) return;

    numberBullsAndCows(a, b);

    numCheck(a);
}

void task_2() {
    /*Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий
    должен угадать его. После ввода пользователем числа программа сообщает, сколько цифр числа
    угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). После отгадывания
    числа на экран необходимо вывести количество сделанных пользователем попыток. В
    программе необходимо использовать рекурсию.*/

    std::srand(time(NULL));

    std::cout << "!!! Bulls and Cows !!!" << "\n\n";

    int a = 0;

    while (!(a / 1000))
        a = std::rand() % 10000;

    numCheck(a);

    std::cout << "----------------------------------------" << "\n";
    std::cout << "----------------------------------------" << "\n";
    std::cout << "Yippee! You have collected all the cows!" << "\n";
    std::cout << "----------------------------------------" << "\n";
    std::cout << "----------------------------------------" << "\n\n";
}

const int SIZE_FIELD = 5;
const int SIZE = 8;

const int moveX[SIZE] = {1,2,2,1,-1,-2,-2,-1};
const int moveY[SIZE] = {-2,-1,1,2,2,1,-1,-2};

void printField( int arr[][SIZE_FIELD] ) {
    for (size_t i = 0; i < SIZE_FIELD; ++i) {
        for (size_t j = 0; j < SIZE_FIELD; ++j)
            std::cout << std::setw(3) << arr[i][j];

        std::cout << "\n";
    }

    std::cout << "\n";
}

void horse(int arr[][SIZE_FIELD], int num, int i0, int j0) {
    static int k = 0;
    k++;

    arr[i0][j0] = num++;

    for (size_t i = 0; i < SIZE; ++i)
    {
        int i_new = i0 + moveY[i];
        int j_new = j0 + moveX[i];

        if (num > SIZE_FIELD * SIZE_FIELD) {
            std::cout << "Number step: " << k << "\n";
            printField(arr);
            exit(0);
        }

        if (arr[i_new][j_new] != 0 ||
            i_new < 0 || i_new > SIZE_FIELD - 1 || 
            j_new < 0 || j_new > SIZE_FIELD - 1) {
            continue;
        }

        horse(arr, num, i_new, j_new);

        arr[i_new][j_new] = 0;
    }
}

void task_3() {
    /*Дана шахматная доска размером 8х8 и шахматный конь. 
    Программа должна запросить у пользователя координаты клетки поля и поставить туда коня. 
    Задача программы найти и вывести путь коня, при котором он обойдет все клетки доски, 
    становясь в каждую клетку только один раз. (Так как процесс отыскания пути для разных 
    начальных клеток может затянуться, то рекомендуется сначала опробовать задачу на поле размером 6х6). 
    В программе необходимо использовать рекурсию.*/

    int matr[SIZE_FIELD][SIZE_FIELD] = {};

    horse(matr, 1, 0, 0);
}

int calcDegree(int a, int b) {
    if (!b) 
        return 1;

    return (b == 1) ? a : a * calcDegree(a, --b);
}

void task_4() {
    /*Написать рекурсивную функцию нахождения степени числа.*/

    int a, b;

    std::cin >> a >> b;

    std::cout << calcDegree(a, b) << "\n";
}

void printStar(int n) {
    if (!n) 
        return;

    std::cout << "*" << " ";

    printStar(--n);
}

void task_5() {
    /*Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь. Проиллюстрируйте работу функции примером.*/

    int n;

    std::cin >> n;

    printStar(n);
}

int sumNum(int a, int b) {
    return (a == b) ? b : a + sumNum(a + 1, b);
}

void task_6() {
    /*Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b. Пользователь вводит a и b. Проиллюстрируйте работу функции примером.*/

    int a, b;

    std::cin >> a >> b;

    std::cout << "\n" << sumNum(a, b);
}

int min10(int* a, int n, int& p)
{
    int s = 0;

    for (int i = n; i < n + 10; ++i) 
        s += a[i];

    std::cout << "n: " << n << "; s: " << s << "\n";

    if (100 - n == 10)
    {
        p = n;
        return s;
    }
    else
    {
        int s1 = min10(a, n + 1, p);

        if (s <= s1)
        {
            p = n;
            return s;
        }
        else return s1;
    }
}

void task_7() {
    /*Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел, 
    заполненных случайным образом, и находит позицию, с которой начинается последовательность из 10 чисел, сумма которых минимальна.*/

        const rsize_t length = 100;
        int arr[length];
        int p;

        std::srand(time(0));

        for (int i = 0; i < length; ++i)
            arr[i] = std::rand() % 100;

        for (int i = 0; i < length; ++i)
            std::cout << arr[i] << '\t';

        std::cout << "\n\n";

        min10(arr, 0, p);

        std::cout << "Minimum position: " << p << "\n\n";
}

// Указатели

void copyArr(size_t len, int* arr_1, int* arr_2, bool swapNum = false) {
    if (swapNum) {
        for (size_t i = 0; i < len; ++i)
            *(arr_2 + i) = *(arr_1 + (len - 1 - i));
    }
    else {
        for (size_t i = 0; i < len; ++i)
            *(arr_2 + i) = *(arr_1 + i);
    }

    std::cout << "FIRST ARRAY:  ";

    for (size_t i = 0; i < len; ++i)
        std::cout << *(arr_1 + i) << "\t";

    std::cout << "\n\n";

    std::cout << "SECOND ARRAY: ";

    for (size_t i = 0; i < len; ++i)
        std::cout << *(arr_2 + i) << "\t";

    std::cout << "\n\n";
}

void task_8() {
    /*Используя два указателя на массив целых чисел, скопировать один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву, а также
оператор разыменования.*/

    const size_t length = 10;
    int arr_1[length];
    int arr_2[length];

    std::srand(time(0));

    for (size_t i = 0; i < length; ++i)
        arr_1[i] = std::rand() % 100;

    copyArr(length, arr_1, arr_2);
}

void swapArray(size_t len, int* arr) {
    std::cout << "FIRST ARRAY:  ";

    for (size_t i = 0; i < len; ++i)
        std::cout << *(arr + i) << "\t";

    std::cout << "\n\n";

    for (size_t i = 0; i < len / 2; ++i)
        std::swap(*(arr + i), *(arr + (len - 1 - i)));

    std::cout << "SECOND ARRAY: ";

    for (size_t i = 0; i < len; ++i)
        std::cout << *(arr + i) << "\t";

    std::cout << "\n\n";
}

void task_9() {
/*Используя указатель на массив целых чисел, изменить порядок следования элементов массива
на противоположный.
Использовать в программе арифметику указателей для продвижения по массиву, а также
оператор разыменования.*/

    const size_t length = 10;
    int arr[]{ 56, 85, 43, 25, 42, 12, 83, 5, 37, 22 };

    swapArray(length, arr);
}

void task_10() {
    /*Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы
во втором массиве элементы находились в обратном порядке.
Использовать в программе арифметику указателей для продвижения по массиву, а также
оператор разыменования.*/

    const size_t length = 10;
    int arr_1[length];
    int arr_2[length];

    std::srand(time(0));

    for (size_t i = 0; i < length; ++i)
        arr_1[i] = std::rand() % 100;

    bool swapNum = true;

    copyArr(length, arr_1, arr_2, swapNum);
}

void task_11() {
    /*Используя указатели и оператор разыменования, определить наибольшее из двух чисел*/

    int a = 10;
    int b = 20;

    int* aPtr = &a;
    int* bPtr = &b;
    
    std::cout << ((*aPtr > *bPtr) ? *aPtr : *bPtr) << "\n";
}

void task_12() {
    /*Используя указатели и оператор разыменования, 
    определить знак числа, введённого с клавиатуры.*/

    int x;

    std::cin >> x;
    std::cout << "\n";

    int* xPtr = &x;

    if(*xPtr > 0)
        std::cout << "number " << *xPtr << " --- positive number" << "\n";

    if(*xPtr < 0)
        std::cout << "number " << *xPtr << " --- negative number" << "\n";
}

void task_13() {
    /*Используя указатели и оператор разыменования, обменять местами значения двух переменных*/

    int a = 12; 
    int b = 84;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n\n";

    int* aPtr = &a;
    int* bPtr = &b;

    std::swap(*aPtr, *bPtr);

    std::cout << "swap variables a and b" << "\n\n";

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
}

void summ(int* x, int* y, int* tmp)
{
    *tmp = *x + *y;
}

void razn(int* x, int* y, int* tmp)
{
    *tmp = *x - *y;
}

void proizv(int* x, int* y, int* tmp)
{
    *tmp = *x * *y;
}

void delen(int* x, int* y, int* tmp)
{
    *tmp = *x / *y;
}

void task_14() {
    /*Написать примитивный калькулятор, пользуясь только указателями.*/

    int a, b, res;
    char dei;

    do {
        std::cin >> a >> dei >> b;
        std::cout << "= ";

        switch (dei) {
        case '+':
            summ(&a, &b, &res);
            std::cout << res << "\n";
            break;
        case '-':
            razn(&a, &b, &res);
            std::cout << res << "\n";
            break;
        case '*':
            proizv(&a, &b, &res);
            std::cout << res << "\n";
            break;
        case '/':
            delen(&a, &b, &res);
            std::cout << res << "\n";
            break;
        default:
            std::cout << "Error!";
        }

        std::cout << "\n" << "If you want to continue, press 1: " << "\n\n";

        std::cin >> a;
    } while (a == 1);
}

void sumValue(size_t len, int* arr) {
    for (size_t i = 0; i < len; ++i)
        std::cout << *(arr + i) << "\t";

    std::cout << "\n\n";

    int sum = 0;

    for (size_t i = 0; i < len; ++i)
        sum += *(arr + i);

    std::cout << "Sum = " << sum << "\n\n";
}

void task_15() {
    const size_t length = 10;
    int arr[]{ 56, 85, 43, 25, 42, 12, 83, 5, 37, 22 };

    sumValue(length, arr);
}

int main () {
    task_7();
}