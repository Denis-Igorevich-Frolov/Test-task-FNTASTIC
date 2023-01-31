#pragma once
#include <string>

class Converter {
public:
    //ћетод, замен€ющий все дублирующиес€ символы на ')', а все одиночные на '('
    std::string convert(std::string text);
private:
    enum Met {
        SYMBOL_MET_ONCE,
        SYMBOL_MET_SEVERAL_TIMES
    };
};