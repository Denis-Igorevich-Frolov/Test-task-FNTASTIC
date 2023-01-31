#include <iostream>
#include "Converter.h"

int main()
{
    //Включение русского языка в консоли
    system("chcp 1251");

    Converter converter;
    std::cout << "Тестовое задание для компании FNTASTIC.\n\nПрограмма заменяет все дублирующиеся символы на ')', а те, что встречаются единожны на '('\n\n\n";
    while (true) {
        std::string text;
        std::cout << "Введите текст:\n";
        getline(std::cin, text);
        std::cout << "Изменённый текст:\n";
        std::cout << converter.convert(text) << "\n\n";
    }
}