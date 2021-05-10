#include <iostream>
#include <string>

void inversion(std::string str) {
    int len = str.length();

    for (size_t i = 0; i < len / 2; i++)
        std::swap(str[i], str[len - 1 - i]);

    std::cout << str << "\n\n";
}

int main() {
    /*--------------Строки:--------------------------------------------------
    Разработать функцию, которая инвертирует строку ("Баба яга" -- "агя абаБ")*/
    setlocale(LC_ALL, "ru");

    std::string str;

    getline(std::cin, str);
    
    inversion(str);
}