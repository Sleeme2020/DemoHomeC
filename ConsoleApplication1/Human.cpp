#include "Human.h"

Human::Human(MyString& name, MyString& firstname, MyString& lastname, Date& birthday)
{
	this->name = name;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthday = birthday;
}

Human::Human()
{

}

MyString& Human::GetSetName()
{
	return name;
}