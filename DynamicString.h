#pragma once
#ifndef DYNAMICSTRING_H
#define DYNAMICSTRING_H
#include <iostream>
using std::ostream;
using std::istream;

class DynamicString {
private:
    char* pointer;
    int length;
public:
    DynamicString(); // ����������� ��� ����������
    DynamicString(const char* str); // ����������� �� ������� ������������� � �����
    DynamicString(const DynamicString& other); // ����������� �����������
    DynamicString(DynamicString&& other); // ����������� �����������

    // ����������
    ~DynamicString() {delete[] pointer;}

    DynamicString& operator=(const DynamicString& other); // �������� ������������ ������������
    DynamicString& operator=(DynamicString&& other); // �������� ������������ ������������

    int Length() {return length;}
    char& operator[](int index) {return pointer[index];}

    bool operator==(const DynamicString& other);
    bool operator!=(const DynamicString& other);
    bool operator>(const DynamicString& other);
    bool operator<(const DynamicString& other);
    friend ostream& operator<<(ostream& o, const DynamicString& other);
    friend istream& operator>>(istream& i, DynamicString& other);
};
#endif