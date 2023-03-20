#pragma once
#include <iostream>
using namespace std;
class Date
{
    int d;
    int m;
    int y;
    friend void SetDayF(Date& ref, int a);
public:
    Date();
    Date& SetDay(int a);
    Date& SetMon(int a);
    Date& SetYear(int a);
    void SetMonF(int a);
    void SetYearF(int a);
    void Print();
    friend ostream& operator<< (ostream& output, const Date& date);
    friend istream& operator>> (istream& input, Date& date);

};
ostream& operator<< (ostream& output, const Date& date);
istream& operator>> (istream& input, Date& date);
void SetDayF(Date& ref, int a);


