#include <iostream>
#include "Converter.h"
#include <map>

//Метод, заменяющий все дублирующиеся символы на ')', а все одиночные на '('
std::string Converter::convert(std::string text) {
    /*Сам алгоритм проверки на дубликаты будет производиться просто при помощи помещения в коллекцию map,
     *в которой будут храниться символы и единое ли было их вхождение, да и поиск в ней быстрый.*/
    std::map<char, Met> map;

    for (char c : text) {
        //Так как необходима нечувствительность к регистру, символ приводится к строчному
        c = tolower(c);

        std::map<char, Met>::iterator iter = map.find(c);
        if (iter == map.end()) {
            map.insert(std::pair<char, Met>(c, Met::SYMBOL_MET_ONCE));
        }
        else {
            /*Если значение(second) элемента map уже равно SYMBOL_MET_SEVERAL_TIMES,
             *то нет нужды лишний раз обращаться к коллекции*/
            if (iter->second == Met::SYMBOL_MET_ONCE)
                iter->second = Met::SYMBOL_MET_SEVERAL_TIMES;
        }
    }

    std::string newText;
    //Забивается итоговый текст
    for (char c : text) {
        /*Во время второго цикла, символы также приводится к строчному регистру. Это можно было бы вынести в
         *отдельный цикл в начале, но я думаю, что при длинном тексте лучше минимизировать количество циклов*/
        c = tolower(c);

        if (map.count(c)){
            /*Теперь просто ищется соответствие c элементом в коллекции, и в зависимости от 
             *значения(second) найденного элемента, выбирается какой скобочкой станет символ*/
            if (map.find(c)->second == Met::SYMBOL_MET_ONCE)
                newText.append("(");
            else
                newText.append(")");
        }
    }
    
    return newText;
}