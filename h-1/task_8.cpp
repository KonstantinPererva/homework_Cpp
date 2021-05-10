#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    float h1,m1,s1;
    float h2,m2,s2;

    std::cout << "*** Для ввода времени используйте 24 часовой формат ***" << "\n\n";
    std::cout << "Введите время начала телефонного разговора" << "\n\n";
    std::cout << "Часы: ";
    std::cin >> h1;
    std::cout << "Минуты: ";
    std::cin >> m1;
    std::cout << "Секунды: ";
    std::cin >> s1;
    std::cout << "\n";

    std::cout << "Введите время завершения телефонного разговора" << "\n\n";
    std::cout << "Часы: ";
    std::cin >> h2;
    std::cout << "Минуты: ";
    std::cin >> m2;
    std::cout << "Секунды: ";
    std::cin >> s2;
    std::cout << "\n";

    const int MINUTES_PER_DAY = 1440; //минут в 24 часах
    const int COST_OF_ONE_MINUTE = 30; //стоимость минуты (копеек)

    float startMinutes = h1 * 60 + m1 + s1 / 60;
    float endMinutes = h2 * 60 + m2 + s2 / 60;

    float duration = endMinutes - startMinutes;

    if (duration < 0) {
        duration += MINUTES_PER_DAY;
    }

    float resultCost = duration * COST_OF_ONE_MINUTE / 100;

    std::cout << "Cтоимость разговора: " << resultCost << "(грн)" << "\n\n";
    
    return 0;
}