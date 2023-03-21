#include "Human.h"

int Human::numerator{ 0 };

Human::Human(MyString& name, MyString& firstname, MyString& lastname, Date& birthday)
{
	num = numerator++;
	this->name = name;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthday = birthday;
}

Human::Human(MyString name, MyString firstname, MyString lastname, Date birthday)
	
{
	num = numerator++;
	this->name = name;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthday = birthday;
}

Human::Human()
{
	num = numerator++;
}

MyString& Human::GetSetName()
{
	return name;
}

MyString& Human::GetSetFirstName()
{
	return firstname;
}

MyString& Human::GetSetLastName()
{
	return lastname;
}

Date& Human::GetSetBirthday()
{
	return birthday;
}

int Human::GetNum()
{
	return num;
}

bool Human::operator==(const Human& hum)
{
	if (this == &hum) return true;
	if (num == hum.num) return true;
	if (name == hum.name && firstname == hum.firstname)
		return true;
	else
		return false;
}
