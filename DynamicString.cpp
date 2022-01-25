#include <iostream>
#include <cstring>
//#include <iomanip>
#include "DynamicString.h"


using namespace std;


// конструктор без параметров
DynamicString::DynamicString()
{
    pointer = nullptr;
    length = 0;
}


// конструктор со списком инициализации и телом
DynamicString::DynamicString(const char* str)
{
    length = strlen(str);
    pointer = new char[length + 1];
    for (int i = 0; i < length; i++) {
        pointer[i] = str[i];
    }
    pointer[length] = '\0';
}


// конструктор копирования
DynamicString::DynamicString(const DynamicString& other)
{
    length = strlen(other.pointer);
    pointer = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        pointer[i] = other.pointer[i];
    }
    pointer[length] = '\0';
}


// Конструктор перемещения
DynamicString::DynamicString(DynamicString&& other)
{
    pointer = other.pointer;
    other.pointer = nullptr;
}


// оператор присваивания копированием
DynamicString& DynamicString::operator=(const DynamicString& other)
{
    if (pointer != nullptr)
    {
        delete[] pointer;
    }
    length = strlen(other.pointer);
    pointer = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        pointer[i] = other.pointer[i];
    }
    pointer[length] = '\0';
    return * this;
}


// оператор присваивания перемещением
DynamicString& DynamicString::operator=(DynamicString&& other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] pointer;
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
}


bool DynamicString::operator==(const DynamicString& other)
{
    return strcmp(pointer, other.pointer);
}


bool DynamicString::operator!=(const DynamicString& other)
{
    return !(operator==(other));
}


bool DynamicString::operator<(const DynamicString& other)
{
    return strcmp(pointer, other.pointer) < 0;
}


bool DynamicString::operator>(const DynamicString& other)
{
    return !(operator<(other));
}


ostream& operator<<(ostream& o, const DynamicString& other)
{
    o << other.pointer;
    return o;
}


istream& operator>>(istream& i, DynamicString& other)
{
    char temp[80];
    i.get(temp, 80);
    if (i)
    {
        //i >> temp;
        other = temp;
    }
    while (i && i.get() != '\n')
        continue;
    return i;
}
