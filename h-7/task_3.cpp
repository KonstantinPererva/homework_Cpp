#include <iostream>
#include <string>

void creatingArrayNumbers(std::string str) {
    std::string numStr = "";
    int len = 0;
    int counter = 0;

    //вывел массив в консоль
    for (int i = 0; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            ++counter;

            if (str[i] == str[str.length() - 1]) {
                ++len;
            }
        }
        else if (counter) {
            ++len;
            counter = 0;
        }
    }

    counter = 0;
    int* arr = new int[len];

    for (int i = 0; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            numStr += str[i];

            if (str[i] == str[str.length() - 1]) {
                int num = std::stoi(numStr);
                arr[counter] = num;
                numStr = "";
            }
        }
        else if (!numStr.empty()) {
            int num = std::stoi(numStr);
            arr[counter++] = num;
            numStr = "";
        }
    }

    //вывел массив в консоль
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << "  ";
    }

    delete [] arr;
}

int main() {
    /*--------------Строки:--------------------------------------------------
    Вводится строка, содержащая буквы, целые неотрицательные числа и иные символы. 
   Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
   Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве должны оказаться 
   числа 48, 9, 13 и 0 */
    setlocale(LC_ALL, "ru");

    std::string str;

    getline(std::cin, str);
    
    creatingArrayNumbers(str);
}