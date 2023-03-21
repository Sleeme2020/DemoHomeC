#pragma warning (disable:4996)
#include "MyString.h"
#include <iostream>
#include <string>
using namespace std;
MyString::MyString()
{
    str = new char[1];
    str[0] = '\0';
    len = 0;
}

MyString& MyString::operator+(const MyString& b)
{
    char* tmp = new char[len + b.len + 1];
    for (int i = 0; i < len; i++)
    {
        tmp[i] = str[i];
    }
    for (int i = len; i < b.len + len; i++)
    {
        tmp[i] = b.str[i - len];
    }
    tmp[len + b.len] = '\0';
    MyString st(tmp);
    delete[] tmp;
    return st;
	// TODO: вставьте здесь оператор return
}

MyString& MyString::operator+(const char* b)
{
    char* tmp = new char[len + strlen(b) + 1];
    for (int i = 0; i < len; i++)
    {
        tmp[i] = str[i];
    }
    for (int i = len; i < strlen(b) + len; i++)
    {
        tmp[i] = b[i - len];
    }
    tmp[len + strlen(b)] = '\0';
    MyString st(tmp);
    delete[] tmp;
    return st;
	// TODO: вставьте здесь оператор return
}

MyString& MyString::operator=(const MyString& b)
{
    if (str != nullptr)
        delete[] str;
    len = b.len;
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = b.str[i];
    }
    str[len] = '\0';
    return *this;
	// TODO: вставьте здесь оператор return
}

MyString& MyString::operator=(MyString&& b)
{
    if (str != nullptr)
        delete[] str;
    len = b.len;
    str = b.str;
    b.str = nullptr;
    /*str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = b.str[i];
    }
    str[len] = '\0';*/
    return *this;
	// TODO: вставьте здесь оператор return
}

bool MyString::operator==(const MyString& b)
{
    return strcmp(str, b.str) == 0 ? true : false;

}


MyString::MyString(const MyString& tmp):MyString(tmp.str)
{
}

MyString::MyString(MyString&& tmp)
{
    str = tmp.str;
    len = tmp.len;
    tmp.str = nullptr;
    tmp.len = 0;
}

MyString::MyString(const char* str)
{
    strcpy(this->str, str);
    this->str[len] = '\0';
}

MyString::MyString(char* str)
{
    strcpy(this->str, str);
    this->str[len] = '\0';
}

MyString::~MyString()
{
    if (str != nullptr)
    {
        delete[] str;
    }
}

char* MyString::GetStr()
{
    char* tmp = new char[len + 1];
    strcpy(tmp, str);
    tmp[len] = '\0';
    return tmp;
}

void MyString::SetStr(char* a)
{

    delete[] str;
    //len = 0;        
    len = strlen(a);
    str = new char[len + 1];
    strcpy(str, a);
    str[len] = '\0';
}

void MyString::Print()
{
    cout << str;
}

MyString& operator+(const char* a, const MyString& b)
{
    int len = strlen(a);
    char* tmp = new char[len + b.len + 1];
    for (int i = 0; i < len; i++)
    {
        tmp[i] = a[i];
    }
    for (int i = len; i < b.len + len; i++)
    {
        tmp[i] = b.str[i - len];
    }
    tmp[len + b.len] = '\0';
    MyString st(tmp);
    delete[] tmp;
    return st; 
}
