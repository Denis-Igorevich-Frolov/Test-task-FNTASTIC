#include <iostream>
#include "Converter.h"
#include <map>

//�����, ���������� ��� ������������� ������� �� ')', � ��� ��������� �� '('
std::string Converter::convert(std::string text) {
    /*��� �������� �������� �� ��������� ����� ������������� ������ ��� ������ ��������� � ��������� map,
     *� ������� ����� ��������� ������� � ������ �� ���� �� ���������, �� � ����� � ��� �������.*/
    std::map<char, Met> map;

    for (char c : text) {
        //��� ��� ���������� ������������������ � ��������, ������ ���������� � ���������
        c = tolower(c);

        std::map<char, Met>::iterator iter = map.find(c);
        if (iter == map.end()) {
            map.insert(std::pair<char, Met>(c, Met::SYMBOL_MET_ONCE));
        }
        else {
            /*���� ��������(second) �������� map ��� ����� SYMBOL_MET_SEVERAL_TIMES,
             *�� ��� ����� ������ ��� ���������� � ���������*/
            if (iter->second == Met::SYMBOL_MET_ONCE)
                iter->second = Met::SYMBOL_MET_SEVERAL_TIMES;
        }
    }

    std::string newText;
    //���������� �������� �����
    for (char c : text) {
        /*�� ����� ������� �����, ������� ����� ���������� � ��������� ��������. ��� ����� ���� �� ������� �
         *��������� ���� � ������, �� � �����, ��� ��� ������� ������ ����� �������������� ���������� ������*/
        c = tolower(c);

        if (map.count(c)){
            /*������ ������ ������ ������������ c ��������� � ���������, � � ����������� �� 
             *��������(second) ���������� ��������, ���������� ����� ��������� ������ ������*/
            if (map.find(c)->second == Met::SYMBOL_MET_ONCE)
                newText.append("(");
            else
                newText.append(")");
        }
    }
    
    return newText;
}