#include <iostream>
#include "unordered_map.h"
#include <chrono>
// Функция для перевода римских чисел в десятичные
int romanToInt(const std::string& s) {
    //std::unordered_map<char, int> romanMap = {
    //    {'I', 1},
    //    {'V', 5},
    //    {'X', 10},
    //    {'L', 50},
    //    {'C', 100},
    //    {'D', 500},
    //    {'M', 1000}
    //};
    MyUnorderedMap map;
    map.insert("I", 1);
    map.insert("V", 5);
    map.insert("X", 10);
    map.insert("L", 50);
    map.insert("C", 100);
    map.insert("D", 500);
    map.insert("M", 1000);
    int result = 0;
    int pre_value = 0;
    for (char c : s) {
        std::string st(1, c);
        int value = map.search(st);
        if (value > pre_value) {
            // Если текущее значение больше предыдущего, вычитаем предыдущее значение
            result += value - 2 * pre_value;
        }
        else {
            result += value;
        }
        pre_value = value;
    }
    return result;
}

int main() {
    std::string romanNumber;
    std::cout << "Введите римское число для перевода в десятичное: ";
    std::cin >> romanNumber;

    int decimalNumber = romanToInt(romanNumber);
    std::cout << "Десятичное представление: " << decimalNumber << std::endl;

    return 0;
}
