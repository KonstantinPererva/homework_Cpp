#include <iostream>

//====================================
//Функции. Перегрузка функций
//====================================
// Задание 1
/*Написать перегруженные функции (int, double, char) для выполнения следующих задач:
    --- Инициализация квадратной матрицы;
    --- Вывод матрицы на экран;
    --- Определение максимального и минимального элемента на главной диагонали матрицы;*/

void Fill(size_t len, int arr[][5]) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            arr[i][j] = static_cast<int>(static_cast<int>('a') + std::rand() % 10);

            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }

    int min = arr[0][0];
    int max = arr[0][0];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; ++j) {
            if (i == j) {
                if (min > arr[i][j]) min = arr[i][j]; 

                if (max < arr[i][j])  max = arr[i][j]; 
            }
        }
    }

    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n\n";
}

void Fill(size_t len, double arr[][5]) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            arr[i][j] = static_cast<double>(static_cast<int>('a') + std::rand() % 10);

            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }

    double min = arr[0][0];
    double max = arr[0][0];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; ++j) {
            if (i == j) {
                if (min > arr[i][j]) min = arr[i][j]; 

                if (max < arr[i][j])  max = arr[i][j]; 
            }
        }
    }

    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n\n";
}

void Fill(size_t len, char arr[][5]) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            arr[i][j] = static_cast<char>(static_cast<int>('a') + std::rand() % 10);

            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }

    char min = arr[0][0];
    char max = arr[0][0];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; ++j) {
            if (i == j) {
                if (min > arr[i][j]) min = arr[i][j]; 

                if (max < arr[i][j])  max = arr[i][j]; 
            }
        }
    }

    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n";
}

void task_1() {
    const size_t length = 5;
    int arr_1[length][length];
    double arr_2[length][length];
    char arr_3[length][length];

    Fill(length, arr_1);
    Fill(length, arr_2);
    Fill(length, arr_3);
}

////////////////////////////////////////////////////////////////////////////////////
// Задание 2
/*Написать перегруженные функции и протестировать их в основной программе:
    --- Нахождения максимального значения в одномерном массиве;
    --- Нахождения максимального значения в двумерном массиве;
    --- Нахождения максимального значения в трёхмерном массиве;
    --- Нахождения максимального значения двух целых;
    --- Нахождения максимального значения трёх целых;*/

void maxValue (size_t len, int* arr) {
    int max = arr[0];

    for (size_t i = 0; i < len; ++i)
        if (max < arr[i]) max = arr[i];

    std::cout << "Max: " << max << "\n";
}

void maxValue(size_t len, int arr[][3]) {
    int max = arr[0][0];

    for (size_t i = 0; i < len; ++i)
        for (size_t j = 0; j < len; ++j)
            if (max < arr[i][j]) max = arr[i][j];
        

    std::cout << "Max: " << max << "\n";
}

void maxValue(size_t len, int arr[][3][3]) {
    int max = arr[0][0][0];

    for (size_t i = 0; i < len; ++i)
        for (size_t j = 0; j < len; ++j)
            for (size_t k = 0; k < len; ++k)
                if (max < arr[i][j][k]) max = arr[i][j][k];


    std::cout << "Max: " << max << "\n";
}

void maxValue(int x, int y) {
    std::cout << "Max: " << ((x > y) ? x : y) << "\n";
}

void maxValue(int x, int y, int z) {
    int max = 0;
    int arr[] = { x,y,z };

    for (size_t i = 0; i < 3; ++i)
        if (max < arr[i]) max = arr[i];

    std::cout << "Max: " << max << "\n";

    // 2 способ нахождения максимального значения трёх целых
    /*if (x > y) {
        if (x > z) std::cout << "Max: " << x << "\n";
        else std::cout << "Max: " << z << "\n";
    }
    else {
        if (y > z)  std::cout << "Max: " << y << "\n";
        else std::cout << "Max: " << z << "\n";
    }*/
}

void task_2() {
    const size_t length = 3;
    int arr_1[]{ 4,8,2 };
    int arr_2[][length]{ {15,64,25},{48,34,62} };
    int arr_3[][length][length]{ {{57,4,15},{21,31,43},{6,65,156}}, {{16,36,3},{1,5,89},{42,37,59}} };

    maxValue(length, arr_1);
    maxValue(length, arr_2);
    maxValue(length, arr_3);
    maxValue(5, 9);
    maxValue(8, 3, 12);
}

////////////////////////////////////////////////////////////////////////////////////
// Задание 3
/*Измените программы из первого и второго задания с помощью шаблонов*/

template<typename T>
void FillTemplate(size_t len, T arr[][5]) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            arr[i][j] = T(static_cast<int>('a') + std::rand() % 10);

            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }

    T min = arr[0][0];
    T max = arr[0][0];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; ++j) {
            if (i == j) {
                if (min > arr[i][j]) min = arr[i][j];

                if (max < arr[i][j])  max = arr[i][j];
            }
        }
    }

    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n\n";
}

void task_3() {
    const size_t length = 5;
    int arr_1[length][length];
    double arr_2[length][length];
    char arr_3[length][length];

    FillTemplate(length, arr_1);
    FillTemplate(length, arr_2);
    FillTemplate(length, arr_3);
}

//====================================
//Сортировка массивов
//====================================
// Задание 4
/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом пузырьковой сортировки.*/

void task_4() {
    const int length = 100;
    int arr[length];

    for (size_t i = 0; i < length; ++i)
        arr[i] = std::rand() % 100;

    for (int i = 0; i < length - 1; i++) 
        for (int j = 0; j < length - i - 1; ++j) 
            if (arr[j] > arr[j + 1])
                std::swap(arr[j + 1], arr[j]);

    for (size_t i = 0; i < length; ++i)
        std::cout << arr[i] << " ";
}

////////////////////////////////////////////////////////////////////////////////////
// Задание 5
/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом вставок.*/

void task_5() {
    const int length = 100;
    int arr[length];

    for (size_t i = 0; i < length; ++i)
        arr[i] = std::rand() % 100;

    for (int i = 1; i < length; ++i)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
            std::swap(arr[j - 1], arr[j]);

    for (size_t i = 0; i < length; ++i)
        std::cout << arr[i] << " ";
}

////////////////////////////////////////////////////////////////////////////////////
// Задание 6
/*Написать программу «успеваемость». Пользователь вводит 10 оценок студента. Реализовать меню для пользователя
    --- Вывод оценок (вывод содержимого массива)
    --- Пересдача экзамена (пользователь вводит номер элемента массива и новую оценку)
    --- Выходит ли стипендия (стипендия выходит, если средний бал не ниже 10.7)*/

void PrintMenu() {
    std::cout << "Для просмотра всех оценок выберите ------------- 1" << "\n";
    std::cout << "Для изменения оценок выберите ------------------ 2" << "\n";
    std::cout << "Для просчета на получение стипендии выберите --- 3" << "\n\n";
}

void PrintGrades(size_t len, int* arr) {
    for (size_t i = 0; i < len; ++i)
        std::cout << arr[i] << " ";

    std::cout << "\n\n";
}

void ChangeGrade(int* arr) {
    int a, b;
    std::cout << "Введите номер оценки от 1 до 10 ... ";
    std::cin >> a;
    std::cout << "Выберите новую оценку ... ";
    std::cin >> b;

    arr[a - 1] = b;
}

void Scholarship(size_t len, int* arr) {
    double sum = 0;

    for (size_t i = 0; i < len; ++i)
        sum += arr[i];

    double mean = sum / static_cast<double>(len);

    if (mean >= 10.7)
        std::cout << "Стипендия выходит :)" << "\n";
    else
        std::cout << "Стипендия не выходит :(" << "\n";

    std::cout << "\n";
}

void task_6() {
    const size_t length = 10;
    int arr[length];

    for (size_t i = 0; i < length; ++i)
    {
        std::cout << "Введите оценку №" << (i + 1) << " ... ";
        std::cin >> arr[i];
    }

    std::cout << "\n";

    int x;

    do {
        PrintMenu();

        std::cin >> x;

        switch (x) {
            case 1:
                PrintGrades(length, arr);
                break;
            case 2:
                ChangeGrade(arr);
                std::cout << "Новый список оценок: ";
                PrintGrades(length, arr);

                break;
            case 3:
                Scholarship(length, arr);

                break;
        }
    } while (x);
}

////////////////////////////////////////////////////////////////////////////////////
// Задание 7
/*Необходимо отсортировать первые две трети массива в порядке возрастания, 
если среднее арифметическое всех элементов больше нуля; иначе - лишь первую треть. 
Остальную часть массива не сортировать, а расположить в обратном порядке.*/

void sortArray(size_t len, int* arr, bool negative) {

    int len_1 = (negative) ? len / 3 : (len / 3) * 2;
    int len_2 = (negative) ? (len / 3) * 2 : len / 3;

    for (size_t i = 0; i < len_1; i++)
        for (int j = 0; j < len_1 - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j + 1], arr[j]);

    for (size_t i = 0; i < (len_2) / 2; ++i)
        std::swap(arr[len_1 + i], arr[len - i - 1]);

    for (size_t i = 0; i < len; ++i)
        std::cout << arr[i] << " ";

    std::cout << "\n";
}

void task_7() {
    const size_t length = 18;
    int arr[length]{ -5,9,-3,29,-48,-34,57,-12,-9,-45,16,24,-52,67,36,-18,7,56 };
    double sum = 0;

    for (size_t i = 0; i < length; i++)
        sum += arr[i];

    double mean = sum / length;

    bool negative = (mean > 0) ? false : true;

    sortArray(length,arr, negative);
}

int main() {
    setlocale(LC_ALL, "ru");

    //task_1();
    //task_2();
    //task_3();
    //task_4();
    //task_5();
    //task_6();
    task_7();
}