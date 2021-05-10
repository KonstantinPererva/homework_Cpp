#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;
using std::swap;

struct Car {
    string model;
    double length;
    double clearance;
    double engineDisplacement;
    double powerEngine;
    string wheelDiameter;
    string color;
    string gearboxType;
};

int _stateMenu;
//Главное меню
void Menu() {
    cout << "--- Меню ---" << endl << endl
        << "(0) Выход" << endl
        << "(1) Добавить" << endl
        << "(2) Просмотреть все" << endl
        << "(3) Поиск" << endl << endl;

    cout << "Ваш выбор: ";
    cin >> _stateMenu;
}

//Копия данных
void Copy(Car* (&d_n), Car* (&d_o), int n) {
    for (int i = 0; i < n; ++i) {
        d_n[i] = d_o[i];
    }
};  

//Вывод данных
void Print(Car* d, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Модель: " << d[i].model << endl;

        cout << "Длина: " << d[i].length << endl;

        cout << "Клиренс: " << d[i].clearance << endl;

        cout << "Объем двигателя: " << d[i].engineDisplacement << endl;

        cout << "Мощность двигателя: " << d[i].powerEngine << endl;

        cout << "Диаметр колес: " << d[i].wheelDiameter << endl;

        cout << "Цвет: " << d[i].color << endl;

        cout << "Тип коробки передач: " << d[i].gearboxType << endl << endl;

        cout << "___________________________" << endl << endl;
    }
};

//Вывод автомобилей по результату поиска
void ViewSearchResult(Car* d, int resultIndex) {
    cout << "Модель: " << d[resultIndex].model << endl;

    cout << "Длина: " << d[resultIndex].length << endl;

    cout << "Клиренс: " << d[resultIndex].clearance << endl;

    cout << "Объем двигателя: " << d[resultIndex].engineDisplacement << endl;

    cout << "Мощность двигателя: " << d[resultIndex].powerEngine << endl;

    cout << "Диаметр колес: " << d[resultIndex].wheelDiameter << endl;

    cout << "Цвет: " << d[resultIndex].color << endl;

    cout << "Тип коробки передач: " << d[resultIndex].gearboxType << endl << endl;

    cout << "___________________________" << endl << endl;
}

//Ввод данных для поиска 
void SelectParams(Car* d, int n, int sel) {
    double dataNum = 0;
    string dataStr;
    int res = 0;

    if (!sel) return;

    switch (sel)
    {
    case 1:
        cout << "--- Поиск по параметру \"Модель\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataStr;

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].model.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) cout << "Совпадений не найдено!" << endl << endl;

        break;
    case 2:
        cout << "--- Поиск по параметру \"Длина\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataNum;

        system("cls");

        cout << "Результат поиска ---" << dataNum << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (d[i].length == dataNum) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        break;
    case 3:
        cout << "--- Поиск по параметру \"Клиренс\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataNum;

        for (int i = 0; i < n; ++i) {
            if (d[i].clearance == dataNum) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        system("cls");

        cout << "Результат поиска ---" << dataNum << "---" << endl << endl;

        break;
    case 4:
        cout << "--- Поиск по параметру \"Объем двигателя\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataNum;

        for (int i = 0; i < n; ++i) {
            if (d[i].engineDisplacement == dataNum) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        system("cls");

        cout << "Результат поиска ---" << dataNum << "---" << endl << endl;

        break;
    case 5:
        cout << "--- Поиск по параметру \"Мощность двигателя\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataNum;

        for (int i = 0; i < n; ++i) {
            if (d[i].powerEngine == dataNum) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        system("cls");

        cout << "Результат поиска ---" << dataNum << "---" << endl << endl;

        break;
    case 6:
        cout << "--- Поиск по параметру \"Диаметр колес\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataStr;

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].wheelDiameter.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        break;
    case 7:
        cout << "--- Поиск по параметру \"Цвет\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataStr;

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].color.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }
        break;
    case 8:
        cout << "--- Поиск по параметру \"Тип коробки передач (Mechanical / Automatic)\" ---" << endl << endl;
        cout << "Введите параметр для поиска: ... ";
        cin >> dataStr;

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].gearboxType.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) cout << "Совпадений не найдено!" << endl << endl;
        break;
    default:
        system("cls");
        Menu();
        break;
    }
};

//Поиск по параметрам
void SearchCar(Car* d, int n) {
    cout << "--- Поиск по параметрам ---" << endl << endl
        
        << "(0) Выход" << endl
        << "(1) Модель" << endl
        << "(2) Длина" << endl
        << "(3) Клиренс" << endl
        << "(4) Объем двигателя" << endl
        << "(5) Мощность двигателя" << endl
        << "(6) Диаметр колес" << endl
        << "(7) Цвет" << endl
        << "(8) Тип коробки передач (Mechanical / Automatic)" << endl << endl;

    cout << "Ваш выбор: ";

    int sel;
    cin >> sel;

    SelectParams(d, n, sel);
};

//Добавить данные
void AddCar(Car* (&d), int& n) {
    cout << "--- Добавить автомобиль ---" << endl << endl;

    //временный массив данных
    Car* buf;
    buf = new Car[n];

    //сохранение данных в временный массив
    Copy(buf, d, n);

    //выделить новую память
    d = new Car[++n];

    //возвращаем данные
    Copy(d, buf, --n);

    cout << "Введите модель: ";
    cin >> d[n].model;

    cout << "Введите длину: ";
    cin >> d[n].length;

    cout << "Введите клиренс: ";
    cin >> d[n].clearance;

    cout << "Введите объем двигателя: ";
    cin >> d[n].engineDisplacement;

    cout << "Введите мощность двигателя: ";
    cin >> d[n].powerEngine;

    cout << "Введите диаметр колес: ";
    cin >> d[n].wheelDiameter;

    cout << "Введите цвет: ";
    cin >> d[n].color;

    cout << "Введите тип коробки передач (Mechanical / Automatic): ";
    cin >> d[n].gearboxType;

    delete[] buf;

    system("cls");

    cout << "Автомобиль добавлен!" << endl << endl;
};

int main() {
    /*--------------Структуры:-----------------------------------------------
    Реализовать структуру «Автомобиль» (длина,
    клиренс (высота посадки), объем двигателя, мощность
    двигателя, диаметр колес, цвет, тип коробки передач).
    Создайте функции для задания значений, отображения
    значений, поиска значений.*/
    setlocale(LC_ALL, "ru");

    Menu();

    //инициализация данных
    int amountOfData = 0;

    //массив данных
    Car* d = new Car[amountOfData];

    while (_stateMenu != 0) {
        switch (_stateMenu) {
        case 1:
            system("cls");
            AddCar(d, amountOfData);
            ++amountOfData;

            system("pause");
            system("cls");
            Menu();

            break;
        case 2:
            system("cls");

            if (amountOfData != 0) {
                Print(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();

            break;
        case 3:
            system("cls");

            if (amountOfData != 0) {
                SearchCar(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();

            break;
        default:
            system("cls");
            Menu();
            break;
        }
    }
}