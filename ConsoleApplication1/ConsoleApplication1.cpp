// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
//class DynArr
//{
//    int* arr;
//    int len;
//
//public:
//    DynArr():DynArr(5)
//    {
//
//    }
//    DynArr(int a):arr{new int[a]},len{a}
//    {
//
//    }
//
//    void Set(int i,int a)
//    {
//        assert(i >= 0 and i < len and "Index is out "
//            "of range!");
//        arr[i] = a;
//
//    }
//
//    int Get(int i)
//    {
//        assert(i >= 0 and i < len and "Index is out "
//            "of range!");
//        return arr[i];
//    }
//
//    int& GetSet(int i)
//    {
//        assert(i >= 0 and i < len and "Index is out "
//            "of range!");
//        return arr[i];
//    }
//
//    int& operator[](int i)
//    {
//        assert(i >= 0 and i < len and "Index is out "
//            "of range!");
//        return arr[i];
//    }
//    int operator()(int i, int first ...)
//    {
//        int* tmp = &first;
//        tmp[i - 1];
//        assert(i >= 0 and i < len and "Index is out "
//            "of range!");
//        
//        return arr[i] ;
//    }
//
//    explicit operator int* ()
//    {
//        int* tmp = new int[len];
//        for (int i = 0; i < len; i++)
//        {
//            tmp[i] = arr[i];
//        }
//        return tmp;
//    }
//    operator int()
//    {
//        int sum = 0;
//        for (int i = 0; i < len; i++)
//        {
//            sum+= arr[i];
//        }
//        return sum;
//    }
//};

#include "Human.h" 




int main()
{
    
    std::cout << "Hello World!\n";
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
