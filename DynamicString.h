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
    DynamicString(); // конструктор без параметров
    DynamicString(const char* str); // конструктор со списком инициализации и телом
    DynamicString(const DynamicString& other); // конструктор копирования
    DynamicString(DynamicString&& other); // Конструктор перемещения

    // деструктор
    ~DynamicString() {delete[] pointer;}

    DynamicString& operator=(const DynamicString& other); // оператор присваивания копированием
    DynamicString& operator=(DynamicString&& other); // оператор присваивания перемещением

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