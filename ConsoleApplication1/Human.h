#pragma once
#include "MyString.h"
#include "Date.h"


class Human
{  
        static int numerator;
        int num;
        MyString name;
        MyString firstname;
        MyString lastname;
        Date birthday; 

public:
    Human();
    
    Human(MyString& name, MyString& firstname, MyString& lastname
        , Date& birthday);
    Human(MyString name, MyString firstname, MyString lastname
        , Date birthday);

    MyString& GetSetName();
    MyString& GetSetFirstName();
    MyString& GetSetLastName();
    Date& GetSetBirthday();
    int GetNum();
    bool operator==(const Human& hum);
    
    
};

