 //
 //  Реализовать класс динамических строк, который:
 //  1. Написан на C++11 без каких либо сторонних библиотек.Не использует в своей
 //  основе какую - либо другую реализацию динамических строк, контейнеров или умных
 //  указателей STL.
 //  2. Класс не шаблонный.Поддерживает строки произвольного размера, используя
 //  базовые операции работы с динамическим хипом(функции malloc() / free() или
 //  операторы new / delete) для манипуляции последовательностями символов типа char.
 //  3. Имеет конструктор копирования, оператор присваивания и поддерживает
 //   move - семантику.
 //  У класса есть "внешний" оператор сложения двух строк.
 //  Нет необходимости использовать какие - то изощренные методы оптимизации(типа
 //  COW и многопоточной поддержки).
 //  Написать пример с использованием этого класса строк и какого - либо контейнера STL.
 //  Программа должна принимать список строк, затем выдавать его в порядке, обратном
 //  лексикографическому без учета регистра.
 //  Программа - пример работает из командной строки.
 //
 //


#include <vector>
#include <algorithm>
#include "DynamicString.h"


using namespace std;


int main()
{
    DynamicString str;
    vector<DynamicString> listOfString;

    cout << "Input a few lines, please. If you are done, just press Enter" << endl;


    while (cin.get() != '\n')
    {
        cin >> str;
        listOfString.push_back(str);
    }


    for (auto item : listOfString)
    {
        cout << item << " " << item.Length() << endl;
    }


    cout << endl << "After sort" << endl << endl;


    // сортировка в обратном порядке без учёта регистра
    sort(listOfString.rbegin(), listOfString.rend(), [](DynamicString a, DynamicString b)
    {
        for (int i = 0; i < min(a.Length(), b.Length()); i++)
        {
            auto a_char = tolower(a[i]);
            auto b_char = tolower(b[i]);
            if (a_char != b_char)
            {
                return a_char < b_char;
            }
        }
        return a.Length() < b.Length();
    });


    // выводим отсорированный вектор
    for (auto x : listOfString)
    {
        cout << x << endl;
    }

    
    return 0;
}
