#include <iostream>
<<<<<<< HEAD
#include <cstring>
//#include <iomanip>
#include "DynamicString.h"


=======
#include <iomanip>
#include <vector>
#include <algorithm>
//#include "DynamicString.h"
>>>>>>> main
using namespace std;


// конструктор без параметров
DynamicString::DynamicString()
{
<<<<<<< HEAD
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
=======
public:
    // конструктор без параметров
    DynamicString() {
        pointer = nullptr;
        //length = 0;
    }

    // конструктор со списком инициализации и телом
    DynamicString(const char* str) {
        length = strlen(str);
        pointer = new char[length + 1];
        for (int i = 0; i < length; i++) {
            pointer[i] = str[i];
        }
        pointer[length] = '\0';
    }

    // конструктор копирования
    DynamicString(const DynamicString& other) {
        length = strlen(other.pointer);
        pointer = new char[length + 1];
        for (int i = 0; i < length; i++) {
            pointer[i] = other.pointer[i];
        }
        pointer[length] = '\0';
>>>>>>> main
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

<<<<<<< HEAD

bool DynamicString::operator==(const DynamicString& other)
{
    return strcmp(pointer, other.pointer);
}

=======
        length = strlen(other.pointer);
        pointer = new char[length + 1];
        for (int i = 0; i < length; i++) {
            pointer[i] = other.pointer[i];
        }
        pointer[length] = '\0';
>>>>>>> main

bool DynamicString::operator!=(const DynamicString& other)
{
    return !(operator==(other));
}


bool DynamicString::operator<(const DynamicString& other)
{
    return strcmp(pointer, other.pointer) < 0;
}

<<<<<<< HEAD

bool DynamicString::operator>(const DynamicString& other)
{
    return !(operator<(other));
}
=======
    int Length() {
        return length;
    }

    bool operator==(const DynamicString& other) {
        if (length != other.length) {
            return false;
        }
        int size = 0;
        length > other.length ? size = other.length : size = length;
        for (int i = 0; i < size; i++) {
            return (pointer[i] > other.pointer[i]);
        }
    }

    bool operator>(const DynamicString& other) {
        int size = 0;
        length > other.length ? size = other.length : size = length;
        for (int i = 0; i < size; i++) {
            return (pointer[i] > other.pointer[i]);
        }
    }

    bool operator<(const DynamicString& other) {
        return !(operator>(other));
    }

    friend ostream& operator<<(ostream& o, const DynamicString& other) {
        o << other.pointer;
        return o;
    }
>>>>>>> main


<<<<<<< HEAD
ostream& operator<<(ostream& o, const DynamicString& other)
{
    o << other.pointer;
    return o;
=======
    char& operator [](int index) {
        return pointer[index];
    }

private:
    char* pointer;
    int length;
};



int main() {
    vector<DynamicString> listOfString;
    DynamicString str("Aaa"),
                  str1 = "aaa",
                  str2 = "adc",
                  str3 = "abc cba",
                  str4 = "bcacba",
                  str5 = str,
                  str6;
    cout << "Enter a string, please" << endl;
    cin >> str6;
    listOfString.push_back(str);
    listOfString.push_back(str1);
    listOfString.push_back(str2);
    listOfString.push_back(str3);
    listOfString.push_back(str4);
    listOfString.push_back(str5);
    listOfString.push_back(str6);
    for (auto item : listOfString) {
        cout << item << " " << item.Length() << endl;
    }
    
    cout << "After sort" << endl;
    
    // сортировка в обратном порядке без учёта регистра
    sort(listOfString.rbegin(), listOfString.rend(), [](DynamicString a, DynamicString b) {
        for (int i = 0; i < min(a.Length(), b.Length()); i++) {
            auto a_char = tolower(a[i]);
            auto b_char = tolower(b[i]);
            if (a_char != b_char) {
                return a_char < b_char;
            }
        }
        return a.Length() < b.Length();
        });

    // выводим отсорированный вектор
    for (auto x : listOfString) {
        cout << x << endl;
    }
    
>>>>>>> main
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
