#include "Date.h"

ostream& operator<<(ostream& output, const Date& date)
{
	output << date.d << "/" << date.m << "/" << date.y;
	return output;
	// TODO: вставьте здесь оператор return
}

istream& operator>>(istream& input, Date& date)
{
	input >> date.d >> date.m >> date.y;
	return input;
	// TODO: вставьте здесь оператор return
}

void SetDayF(Date& ref, int a)
{
	ref.d = a;
}

Date::Date()
{
	d = 1;
	m = 1;
	y = 1970;
}

Date& Date::SetDay(int a)
{
	d = a;
	return *this;
	// TODO: вставьте здесь оператор return
}

Date& Date::SetMon(int a)
{
	m = a;
	return *this;
	// TODO: вставьте здесь оператор return
}

Date& Date::SetYear(int a)
{
	y = a;
	return *this;
	// TODO: вставьте здесь оператор return
}

void Date::SetMonF(int a)
{
	m = a;
}

void Date::SetYearF(int a)
{
	y = a;
}

void Date::Print()
{
	cout << d << "/" << m << "/" << y;

}
