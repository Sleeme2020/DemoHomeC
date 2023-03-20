#include "Kvartira.h"
int Kvartira::numerator{ 0 };

void Kvartira::getnum()
{
	num = numerator++;
}

Kvartira::Kvartira():Kvartira(1,30)
{
	humans = nullptr;
	count = 0;
	getnum();
}

Kvartira::Kvartira(int komnat, double squaremetr)
{
	humans = nullptr;
	count = 0;
	getnum();
	this->komnat = komnat;
	this->squaremetr = squaremetr;
}

Kvartira::Kvartira(int komnat, double squaremetr, Human& humans)
	:Kvartira(komnat, squaremetr)
{
	this->humans = new Human[1];
	this->humans[0] = humans;
}

Kvartira::Kvartira(int komnat, double squaremetr
	, Human* humans,int count) :Kvartira(komnat, squaremetr)
{
	this->count = count;
	this->humans = new Human[count];
	for (int i = 0; i < count; i++)
	{
		this->humans[i] = humans[i];
	}
}
