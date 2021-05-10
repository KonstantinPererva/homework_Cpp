#include <iostream>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;
using std::swap;

struct Name {
	string lastName;
	string firstName;
	string patronymic;
};

struct Date {
	short day;
	short mounth;
	int year;
};

struct Address {
	string street;
	string house;
	string apartment;
};

struct Worker {
	int id;
	Name name;
	Date dateOfBirthday;
	Address address;
	string department;
	string post;
	double sallary;
	short holiday;
};

void Menu();
void Copy(Worker* (&d_n), Worker* (&d_o), int n);
void AddWorker(Worker* (&d), int& n);
void DetailInfo(int num, Worker* d, int n);
void Print(Worker* d, int n);
void SortWorker(Worker* d, int n);

int _stateMenu;
//Главное меню
void Menu() {
	cout << "--- Меню ---" << endl
        << "(0) Выход" << endl
        << "(1) Добавить" << endl
        << "(2) Удалить" << endl
        << "(3) Поиск" << endl
        << "(4) Сортировка" << endl
        << "(5) Показать всех работников" << endl << endl
        << "Ваш выбор: ";

	cin >> _stateMenu;
}

//Копия данных
void Copy(Worker* (&d_n), Worker* (&d_o), int n) {
    for (int i = 0; i < n; ++i) {
        d_n[i] = d_o[i];
    }
};

//Добавить данные
void AddWorker(Worker* (&d), int& n) {
    //временный массив данных
    Worker* buf = new Worker[n];

    //сохранение данных в временный массив
    Copy(buf, d, n);

    //выделить новую память
    d = new Worker[++n];

    //возвращаем данные
    Copy(d, buf, --n);

    cout << "--- Введите данные ФИО: ---" << endl;
    cout << "\t" << "Фамилия: ";
    cin >> d[n].name.lastName;
    cin.ignore(32767, '\n');

    cout << "\t" << "Имя: ";
    cin >> d[n].name.firstName;
    cin.ignore(32767, '\n');

    cout << "\t" << "Отчество: ";
    cin >> d[n].name.patronymic;
    cin.ignore(32767, '\n');

    cout << "--- Введите данные Даты рождения: ---" << endl;
    cout << "\t" << "День: ";
    cin >> d[n].dateOfBirthday.day;
    cin.ignore(32767, '\n');

    cout << "\t" << "Месяц: ";
    cin >> d[n].dateOfBirthday.mounth;
    cin.ignore(32767, '\n');

    cout << "\t" << "Год: ";
    cin >> d[n].dateOfBirthday.year;
    cin.ignore(32767, '\n');

    cout << "--- Введите данные Адреса: ---" << endl;
    cout << "\t" << "Улица: ";
    getline(cin, d[n].address.street);

    cout << "\t" << "Дом: ";
    cin >> d[n].address.house;
    cin.ignore(32767, '\n');

    cout << "\t" << "Квартира: ";
    cin >> d[n].address.apartment; 
    cin.ignore(32767, '\n');

    cout << "--- Введите рабочие данные: ---" << endl;
    cout << "\t" << "Отдел: ";
    getline(cin, d[n].department);

    cout << "\t" << "Должность: ";
    getline(cin, d[n].post);

    cout << "\t" << "Зарплата: ";
    cin >> d[n].sallary;
    cin.ignore(32767, '\n');

    cout << "\t" << "Отпускных дней: ";
    cin >> d[n].holiday;
    cin.ignore(32767, '\n');

    system("cls");

    cout << "Сотрудник добавлен!" << endl << endl;

    delete[] buf;
};

//Подробная информация о сотруднике
void DetailInfo(int num, Worker* d, int n) {
    Worker worker = d[num];
    cout << "--- Детальная информация работника ---" << endl << endl;
    cout << "ФИО: " << worker.name.lastName << " "
        << worker.name.firstName << " "
        << worker.name.patronymic << endl << endl;

    cout << "День рождения: " << ((worker.dateOfBirthday.day < 10) ? "0" : "") << worker.dateOfBirthday.day << "."
        << ((worker.dateOfBirthday.mounth < 10) ? "0" : "") << worker.dateOfBirthday.mounth << "."
        << worker.dateOfBirthday.year << endl << endl;

    cout << "Адрес проживания: " << "ул." << worker.address.street
        << ", д." << worker.address.house
        << ", кв." << worker.address.apartment << endl << endl;

    cout << "Отдел: " << worker.department << endl << endl;

    cout << "Должность: " << worker.post << endl << endl;

    cout << "Ставка: " << worker.sallary << "грн." << endl << endl;

    cout << "Дней отпуска: " << worker.holiday << endl << endl;

    cout << "\n" 
        << "============================================================================" 
        << "\n"
        << "Для возврата в главное меню введите ... 0 " << endl
        << "Чтобы вернуться в предыдущее меню введите ... 1" << endl
        << "============================================================================" << endl
        << endl << endl
        << "Ваш выбор: ";

    int x;
    cin >> x;

    if (!x) {
        system("cls");
        Menu();
    }
    else {
        system("cls");
        Print(d, n);
    }
}

//Вывести данные
void Print(Worker* d, int n) {
    for (int i = 0; i < n; i++)
        cout << (i + 1) << ". "
        << d[i].name.lastName << " "
        << d[i].name.firstName << " "
        << d[i].name.patronymic << " - "
        << d[i].post << endl << endl;
}

//Вывести данные
void Print(Worker* d, int n, int x) {

    for (int i = 0; i < n; i++) {
        switch (x) {
        case 1:
            cout << (i + 1) << ". " << d[i].name.lastName << " " << d[i].name.firstName << " " << d[i].name.patronymic << endl << endl;
            break;
        case 2:
            cout << (i + 1) << ". " << d[i].department << " - " << d[i].name.lastName << " " << d[i].name.firstName  << " " << d[i].name.patronymic << endl << endl;
            break;
        case 3:
            cout << (i + 1) << ". " << d[i].sallary << " - " << d[i].name.lastName << " " << d[i].name.firstName << " " << d[i].name.patronymic << endl << endl;
            break;
        case 4:
            cout << (i + 1) << ". " << d[i].holiday << " - " << d[i].name.lastName << " " << d[i].name.firstName << " " << d[i].name.patronymic << endl << endl;
            break;
        default:
            break;
        }
    }
}

//Удалить данные
void DeleteWorker(Worker* (&d), int& n) {
    cout << "--- Удаление данных сотрудника ---" << endl;

    Print(d, n);

    int _n;
    cout << "Введите порядковый номер: ";
    cin >> _n;
    _n--;

    system("cls");

    if (_n >= 0 && _n < n) {
        Worker* buf = new Worker[n];

        Copy(buf, d, n);

        --n;
        d = new Worker[n];

        int q = 0;

        for (int i = 0; i <= n; ++i, ++q) {
            if (i == _n) continue;

            d[q] = buf[i];
        }

        delete[] buf;

        system("cls");

        cout << "Данные сотрудника удалены" << endl << endl;
    }
    else {
        cout << "Номер введен не верно" << endl << endl;
    }
}

//Сортировка
void SortWorker(Worker* d, int n) {

    cout << "### Сортировать по ... ###" << endl << endl
        << "(1) Фамилии" << endl
        << "(2) Отделу" << endl
        << "(3) Зарплате" << endl
        << "(4) Количеству отпускных дней" << endl << endl
        << "Ваш выбор: ";

    short x;
    cin >> x;
    cin.ignore(32767, '\n');

    switch (x)
    {
    case 1:
        system("cls");
        cout << "### Сортировка работников по Фамилии ###" << endl << endl;

        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - i - 1; ++j)
                if (d[j].name.lastName > d[j + 1].name.lastName)
                    swap(d[j], d[j + 1]);

        break;
    case 2:
        system("cls");
        cout << "### Сортировка работников по отделу ###" << endl << endl;

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (d[j].department > d[j + 1].department)
                    swap(d[j], d[j + 1]);
        break;
    case 3:
        system("cls");
        cout << "### Сортировка работников по зарплате ###" << endl << endl;

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (d[j].sallary > d[j + 1].sallary)
                    swap(d[j], d[j + 1]);
        break;
    case 4:
        system("cls");
        cout << "### Сортировка работников по количеству отпускных дней ###" << endl << endl;

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (d[j].holiday > d[j + 1].holiday)
                    swap(d[j], d[j + 1]);
        break;
    default:
        break;
    }

    Print(d, n, x);
}

//Вывод автомобилей по результату поиска
void ViewSearchResult(Worker* d, int resultIndex) {
    Worker worker = d[resultIndex];
    cout << "--- Детальная информация работника ---" << endl << endl;
    cout << "ФИО: " << worker.name.lastName << " "
        << worker.name.firstName << " "
        << worker.name.patronymic << endl << endl;

    cout << "День рождения: " << ((worker.dateOfBirthday.day < 10) ? "0" : "") << worker.dateOfBirthday.day << "."
        << ((worker.dateOfBirthday.mounth < 10) ? "0" : "") << worker.dateOfBirthday.mounth << "."
        << worker.dateOfBirthday.year << endl << endl;

    cout << "Адрес проживания: " << "ул." << worker.address.street
        << ", д." << worker.address.house
        << ", кв." << worker.address.apartment << endl << endl;

    cout << "Отдел: " << worker.department << endl << endl;

    cout << "Должность: " << worker.post << endl << endl;

    cout << "Ставка: " << worker.sallary << "грн." << endl << endl;

    cout << "Дней отпуска: " << worker.holiday << endl << endl;

    cout << "___________________________" << endl << endl;
}

//Ввод данных для поиска 
void SelectParams(Worker* d, int n, int sel) {
    string dataStr;
    int res = 0;

    switch (sel)
    {
    case 1:
        cout << "--- Поиск по \"Фамилии\" ---" << endl << endl;
        cout << "Введите Фамилию для поиска: ... ";
        cin >> dataStr;

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].name.lastName.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) cout << "Совпадений не найдено!" << endl << endl;

        break;
    case 2:
        cout << "--- Поиск по \"Отделу\" ---" << endl << endl;
        cout << "Введите Отдел для поиска: ... ";
        getline(cin, dataStr);

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].department.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        break;
    case 3:
        cout << "--- Поиск по \"Должности\" ---" << endl << endl;
        cout << "Введите Должность для поиска: ... ";
        getline(cin, dataStr);

        system("cls");

        cout << "Результат поиска ---" << dataStr << "---" << endl << endl;

        for (int i = 0; i < n; ++i) {
            if (!d[i].post.compare(dataStr)) {
                ++res;
                ViewSearchResult(d, i);
            }
        }

        if (!res) {
            cout << "Совпадений не найдено!" << endl << endl;
        }

        break;
    default:
        system("cls");
        Menu();
        break;
    }
};

//Поиск по параметрам
void SearchWorker(Worker* d, int n) {
    cout << "--- Поиск по параметрам ---" << endl << endl
        << "(1) Фамилия" << endl
        << "(2) Отдел" << endl
        << "(3) Должность" << endl << endl
        << "Ваш выбор: ";

    int sel;
    cin >> sel;
    cin.ignore(32767, '\n');

    SelectParams(d, n, sel);
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	Worker Ivan, Petr, Masha, Vasya, Oleg;
	Ivan = { 0, "Иванов", "Иван", "Иванович", 12, 5, 1986, "Сергея Есенина", "11", "5", "Отдел маркетинга", "Начальник отдела маркетинга", 7650, 28 };
	Petr = { 1, "Петров", "Петр", "Петрович", 7, 9, 1993, "Металлиста", "8", "23", "Отдел продаж", "Менеджер по работе с клиентами", 5000, 22 };
	Masha = { 2, "Сидорова", "Мария", "Викторовна", 21, 2, 1995, "Полтавский шлях", "45", "16", "Финансовый отдел", "Бухгалтер", 6200, 24 };
    Vasya = { 3, "Васечкин", "Василий", "Васильевич", 3, 7, 1989, "Франтишека Крала", "49", "12", "Отдел снабжения", "Менеджер по закупкам", 5500, 20 };
	Oleg = { 4, "Колисниченко", "Олег", "Генадьевич", 17, 4, 1990, "Гоголя", "3", "26", "Отдел продаж", "Менеджер по работе с клиентами", 5000, 22 };

	const int length = 5;
	Worker arr[length] = { Ivan, Petr, Masha, Vasya, Oleg };

    Menu();

    //инициализация данных
    int amountOfData = length;

    //массив данных
    Worker* d = new Worker[amountOfData];

    for (int i = 0; i < length; ++i) {
        d[i] = arr[i];
    }

    while (_stateMenu != 0) {
        switch (_stateMenu) {
        case 1:
            system("cls");
            AddWorker(d, amountOfData);
            system("pause");
            system("cls");

            Menu();

            ++amountOfData;

            break;
        case 2:
            system("cls");

            if (amountOfData != 0) {
                DeleteWorker(d, amountOfData);
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
                SearchWorker(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            system("pause");
            system("cls");
            Menu();

            break;
        case 4:
            system("cls");

            if (amountOfData != 0) {
                SortWorker(d, amountOfData);
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            cout << endl
                << "============================================================================"
                << endl
                << "Для возврата в главное меню введите ... 0 "
                << endl
                << "Для просмотра детальной информации о работнике введите его порядковый номер "
                << endl
                << "============================================================================"
                << endl << endl
                << "Ваш выбор: ";

            int num;
            cin >> num;

            if (!num) {
                system("cls");
                Menu();
            }
            else {
                system("cls");
                DetailInfo(--num, d, amountOfData);
            }

            break;
        case 5:
            system("cls");

            if (amountOfData != 0) {
                cout << "--- Список всех работников (ФИО и Должность) ---" << endl << endl;

                Print(d, amountOfData);

                cout << endl
                    << "============================================================================"
                    << endl
                    << "Для возврата в главное меню введите ... 0 "
                    << endl
                    << "Для просмотра детальной информации о работнике введите его порядковый номер "
                    << endl
                    << "============================================================================"
                    << endl << endl
                    << "Ваш выбор: ";

                int num;
                cin >> num;

                if (!num) {
                    system("cls");
                    Menu();
                }
                else {
                    system("cls");
                    DetailInfo(--num, d, amountOfData);
                }
            }
            else {
                cout << "Данные пусты!" << endl;
            }

            break;
        default:
            system("cls");
            Menu();
            break;
        }
    }
}