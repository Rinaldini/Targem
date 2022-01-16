/*
 *  Реализовать класс динамических строк, который:
 *  1. Написан на C++11 без каких либо сторонних библиотек.Не использует в своей
 *  основе какую - либо другую реализацию динамических строк, контейнеров или умных
 *  указателей STL.
 *  2. Класс не шаблонный.Поддерживает строки произвольного размера, используя
 *  базовые операции работы с динамическим хипом(функции malloc() / free() или
 *  операторы new / delete) для манипуляции последовательностями символов типа char.
 *  3. Имеет конструктор копирования, оператор присваивания и поддерживает
 *   move - семантику.
 *  У класса есть "внешний" оператор сложения двух строк.
 *  Нет необходимости использовать какие - то изощренные методы оптимизации(типа
 *  COW и многопоточной поддержки).
 *  Написать пример с использованием этого класса строк и какого - либо контейнера STL.
 *  Программа должна принимать список строк, затем выдавать его в порядке, обратном
 *  лексикографическому без учета регистра.
 *  Программа - пример работает из командной строки.
 *
 *
 **/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
//#include "DynamicString.h"
using namespace std;

class DynamicString
{
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
    }

    // Конструктор перемещения
    DynamicString(DynamicString&& other) {
        pointer = other.pointer;
        other.pointer = nullptr;
    }


    // деструктор
    ~DynamicString()
    {
        delete[] pointer;
    }

    // оператор присваивания копированием
    DynamicString& operator=(const DynamicString& other) {
        if (pointer != nullptr) {
            delete[] pointer;
        }

        length = strlen(other.pointer);
        pointer = new char[length + 1];
        for (int i = 0; i < length; i++) {
            pointer[i] = other.pointer[i];
        }
        pointer[length] = '\0';

        return * this;
    }

    // оператор присваивания перемещением
    DynamicString& operator=(DynamicString&& other) {
        if (this == &other) {
            return *this;
        }

        delete[] pointer;
        pointer = other.pointer;
        other.pointer = nullptr;
        return *this;
    }

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

    friend istream& operator>>(istream& i, DynamicString& other) {
        char temp[100];
        i >> setw(100) >> temp;
        other = temp;
        return i;
    }

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
    //cout << "After sort" << endl;
    
    // сортировка без учёта регистра
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
