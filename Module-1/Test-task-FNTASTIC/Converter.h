#pragma once
#include <string>

class Converter {
public:
    //�����, ���������� ��� ������������� ������� �� ')', � ��� ��������� �� '('
    std::string convert(std::string text);
private:
    /*�� ����� ��� ������� ������� ����������, ����� ��-�� ����, ��� � �������� map ������� ����� �� �
     *��� �� ��������� �������� first � second, ����� �� ��������� ������������ ��� ���������, ��� ������
     *true - ������ �� ��� ���������, ��� �� ��������, ��� ������ ��, ��� ������ ���������� ���� ���.*/
    enum Met {
        SYMBOL_MET_ONCE,
        SYMBOL_MET_SEVERAL_TIMES
    };
};