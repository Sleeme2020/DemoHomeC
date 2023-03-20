#pragma once
#include "MyString.h"
#include "Date.h"


class Human
{  
        MyString name;
        MyString firstname;
        MyString lastname;
        Date birthday; 

public:
    Human();
    Human(MyString& name, MyString& firstname, MyString& lastname
        , Date& birthday);

    MyString& GetSetName();
    
    
    
};

