#include <iostream>
#include <string>

void findMaxWord(std::string str) {
    std::string testWord = "";
    std::string maxWord = "";
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            testWord += str[i];

            if (str[i] == str[str.length() - 1] && testWord.length() > maxWord.length()) {
                maxWord = testWord;
            }
        }
        else if (!testWord.empty()) {
            if (testWord.length() > maxWord.length()) {
                maxWord = testWord;
            }

            testWord = "";
        }
    }

    std::cout << maxWord << "\n";
}

int main() {
    /*--------------Строки:--------------------------------------------------
    Вводится строка слов, разделенных пробелами. Найти самое длинное слово и вывести его на экран.
   Случай, когда самых длинных слов может быть несколько, не обрабатывать*/
    setlocale(LC_ALL, "ru");

    std::string str;

    getline(std::cin, str);
    
    findMaxWord(str);
}