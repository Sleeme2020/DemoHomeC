#include "Kvartira.h"
int Kvartira::numerator{ 0 };

void Kvartira::getnum()
{
	num = numerator++;
}

void Kvartira::clear()
{
	if (humans != nullptr)
	{
		delete[] humans;
		count = 0;
	}
}

void Kvartira::resize(int x)
{
	Human* tmp = humans;
	humans = new Human[count + x];
	for (size_t i = 0; i < count; i++)
	{
		humans[i] = tmp[i];
	}
	count += x;
	if(tmp!=nullptr)
		delete[] tmp;
}

Kvartira::Kvartira():Kvartira(1,30)
{
	
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

Kvartira::~Kvartira()
{
	clear();
}

Kvartira& Kvartira::operator+(const Human& human)
{
	resize(1);
	humans[count - 1] = human;
}

Kvartira& Kvartira::operator+(const Kvartira& kvartira)
{
	resize(kvartira.count);
	for (int i=count-kvartira.count,j=0;i<count;i++,j++)
	{
		humans[i] = kvartira.humans[j];
	}
	komnat += kvartira.komnat;
	squaremetr += kvartira.squaremetr;
}

Kvartira& Kvartira::operator-(const Human& human)
{
	for (int i = 0; i < count; i++)
	{
		if (humans[i] == human)
		{
			humans[i] = humans[count - 1];
			break;
		}
	}
	resize(-1);
}
