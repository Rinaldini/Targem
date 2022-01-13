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
#include <vector>
//#include "DynamicString.h"
using namespace std;

class DynamicString
{
public:
    // конструктор без параметров
    DynamicString() {
        pointer = nullptr;
    }

    // конструктор со списком инициализации и телом
    DynamicString(const char* str) {
        int length = GetLength(str);
        pointer = new char[length + 1];
        for (int i = 0; i < length; i++) {
            pointer[i] = str[i];
        }
        pointer[length] = '\0';
    }

    // конструктор копирования
    DynamicString(const DynamicString& other) {
        int length = GetLength(other.pointer);
        pointer = new char[length + 1];
        for (int i = 0; i < length; i++) {
            pointer[i] = other.pointer[i];
        }
        pointer[length] = '\0';
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

        int length = GetLength(other.pointer);
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


    int GetLength(const char* str) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    void Print() {
        cout << pointer;
    }

private:
    char* pointer;
    //int length;
};




int main() {
    
    //vector<string> listOfString;
    DynamicString str("Hello");
    DynamicString str1 = " world";
    DynamicString str3 = str;
    //cout << getLength(str) << endl;
    
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
