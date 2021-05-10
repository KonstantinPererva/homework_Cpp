#include <iostream>
#include <string>
#include <cctype>

void setPassword();

bool isspecial(char c) {
    return c == '!' || 
           c == '"' || 
           c == '#' ||
           c == '$' || 
           c == '%' || 
           c == '&' ||
           c == '+' || 
           c == '(' || 
           c == ')' ||
           c == '*' || 
           c == '\'';
}

void testPas(std::string pas) {
    bool lower, upper, digit, symbol, len, indSpace, indSymbol;
    lower = upper = digit = symbol = len = indSpace = indSymbol = false;

    std::string errorFull = "";
    std::string errorSymbol_1 = "Введите не менее 6 символов";
    std::string errorSymbol_2 = "Вводите символы указанные в правилах создания пароля";
    std::string errorSymbol_3 = "Нельзя применять к паролю символ пробела";

    if (pas.length() < 6 || pas.empty()) {
        std::cout << errorSymbol_1 << "\n";
        setPassword();
        return;
    }
    //проверка на длину пароля, если больше 6 символов, то + 1 бал
    len = pas.length() > 6;
    
    for (size_t i = 0; i < pas.length(); ++i) {
        //проверка на строчную букву + 1 бал
        if (!lower) {
            if (lower = islower(pas[i])) continue;
        }
        //проверка на прописную букву + 1 бал
        if (!upper) {
            if (upper = isupper(pas[i])) continue;
        }
        //проверка на цыфру + 1 бал
        if (!digit) {
            if (digit = isdigit(pas[i])) continue;
        }
        //проверка на символ + 1 бал
        if (!symbol) {
            if (symbol = isspecial(pas[i])) continue;
        }
        //проверка на пробел
        if (!indSpace) {
            if (indSpace = isspace(pas[i])) { 
                errorFull += "-" + errorSymbol_3 + "\n";
                continue ;
            }
        }
    }
    //проверка на запрещенный символ
    std::size_t found = pas.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYZ!\"#$%&+()*'1234567890 ");

    if (found != std::string::npos) {
        errorFull += "-" + errorSymbol_2 + "\n";
        indSymbol = true;
    }

    if (indSpace || indSymbol) {
        std::cout << "У Вас есть ошибки при создании пароля:" << "\n";

        std::cout << errorFull << "\n";

        setPassword();
    }
    else {
        std::cout << "Надежность пароля " << lower + upper + digit + symbol + len << " из 5" << "\n\n";
    }
}

void setPassword() {
    std::cout << "Введите пароль : ";

    std::string pas;
    getline(std::cin, pas);

    std::cout << "\n";

    testPas(pas);
}

int main() {
    /*--------------Строки:--------------------------------------------------
    Разработать функцию, которая оценивает стойкость пароля*/
    setlocale(LC_ALL, "ru");

    std::cout << "--- Придумайте пароль, руководствуясь правилами ---" << "\n";
    std::cout << "--- Надежность пароля оценивается по 5-и бальной шкале ---" << "\n\n";
    std::cout << "Пароль должен содержать не менее 6 символов:" << "\n";
    std::cout << "1. строчные или заглавные латинские буквы" << "\n";
    std::cout << "2. цифры" << "\n";
    std::cout << "3. ! \" # $ % & ‘ ( ) * +" << "\n\n";
    
    setPassword();
}