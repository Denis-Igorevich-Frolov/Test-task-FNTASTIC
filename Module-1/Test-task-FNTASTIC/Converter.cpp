#include <iostream>
#include "Converter.h"
#include <map>

//�����, ���������� ��� ������������� ������� �� ')', � ��� ��������� �� '('
std::string Converter::convert(std::string text) {
    /*��� �������� �������� �� ��������� ����� ������������� ������ ��� ������ ��������� � ��������� map,
     *������� �� ��������� ���������, � �������������� ��, ��������� ��� ���� false. � ���� �� ��� ���������
     *����� ����� ������� � ��������(second) ���� �� ��������� ������������, �� � ����� � ��� �������.*/
    std::map<char, Met> map;

    for (char c : text) {
        //��� ��� ���������� ������������������ � ��������, ������ ���������� � ���������
        c = tolower(c);
        //����� insert ����� false � second'�, ���� ��������� �� ���� ������
        bool isFirstEntry = (map.insert(std::pair<char, Met>(c, Met::SYMBOL_MET_ONCE))).second;
        if (!isFirstEntry) {
            /*����� ����������� ������������ 2 ��������� � ��������� map, ���
             *��� ����� ������� ��������, ����� �� ������� ����� find ������*/
            std::map<char, Met>::iterator iter = map.find(c);
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