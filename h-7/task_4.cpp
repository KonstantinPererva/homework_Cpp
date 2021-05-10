#include <iostream>
#include <string>

void countLetters(std::string str) {
    int lower = 0;
    int upper = 0;
    
    for (int i = 0; i < str.length(); ++i) {
        //проверка на строчную букву
        if (int(str[i]) >= int('a') && int(str[i]) <= int('z')) ++lower;
        //проверка на прописную букву
        if (int(str[i]) >= int('A') && int(str[i]) <= int('Z')) ++upper;
    }

    //вывел результат в консоль
    std::cout << "Строчных английских: " << lower << "\n";
    std::cout << "Прописных английских: " << upper << "\n";
}

int main() {
    /*--------------Строки:--------------------------------------------------
    Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
   Учитывать только английские буквы*/
    setlocale(LC_ALL, "ru");

    std::string str;

    getline(std::cin, str);
    
    countLetters(str);
}