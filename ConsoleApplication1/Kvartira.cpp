#include "Kvartira.h"





void Kvartira::clear()
{
	humans.clear();
}

void Kvartira::resize(int x)
{/*
	Human* tmp = humans;
	humans = new Human[count + x];
	for (size_t i = 0; i < count; i++)
	{
		humans[i] = tmp[i];
	}
	count += x;
	if(tmp!=nullptr)
		delete[] tmp;*/
	humans.resize(x);
}

Kvartira::Kvartira():Kvartira(1,30)
{
	
}

Kvartira::Kvartira(int komnat, double squaremetr)
{
	/*humans = nullptr;
	count = 0;*/
	num = numerator.Next();
	this->komnat = komnat;
	this->squaremetr = squaremetr;
}

Kvartira::Kvartira(int komnat, double squaremetr, Human& humans)
	:Kvartira(komnat, squaremetr)
{
	this->humans.resize(1);
	this->humans[0] = humans;
	/*this->humans = new Human[1];
	this->humans[0] = humans;*/

}

Kvartira::Kvartira(int komnat, double squaremetr
	, Human* humans,int count) :Kvartira(komnat, squaremetr)
{
	/*this->count = count;
	this->humans = new Human[count];*/
	this->humans.resize(count);
	for (int i = 0; i < count; i++)
	{
		this->humans[i] = humans[i];
	}
}



Kvartira& Kvartira::operator+(const Human& human)
{
	resize(1);
	humans[humans.GetLen() - 1] = human;
	return *this;
}

Kvartira& Kvartira::operator+(const Kvartira& kvartira)
{
	resize(kvartira.humans.GetLen());
	for (int i= humans.GetLen() -kvartira.humans.GetLen(),j=0;i< humans.GetLen();i++,j++)
	{
		humans[i] = kvartira.humans[j];
	}
	komnat += kvartira.komnat;
	squaremetr += kvartira.squaremetr;
	return *this;
}

Kvartira& Kvartira::operator-(const Human& human)
{
	for (int i = 0; i < humans.GetLen(); i++)
	{
		if (humans[i] == human)
		{
			humans[i] = humans[humans.GetLen() - 1];
			break;
		}
	}
	resize(-1);
	return *this;
}

Kvartira& Kvartira::operator=(const Kvartira& kvartira)
{
	clear();
	resize(kvartira.humans.GetLen());
	for (int i = 0; i < humans.GetLen(); i++)
	{
		humans[i] = kvartira.humans[i];
	}
	squaremetr = kvartira.squaremetr;
	komnat = kvartira.komnat;
	return *this;
}

Kvartira& Kvartira::operator=(Kvartira&& kvartira)
{
	//clear();
	humans.Move(kvartira.humans);
	//count = kvartira.count;
	//kvartira.humans = nullptr;
	squaremetr = kvartira.squaremetr;
	komnat = kvartira.komnat;
	num = kvartira.num;
	return *this;
}

Kvartira& Kvartira::operator=(const Human& human)
{
	clear();
	resize(1);
	humans[0] = human;
	return *this;
}

Human& Kvartira::operator[](int num)
{
	assert(num>=0 && num< humans.GetLen() && "Index of not rigion");
	return humans[num];
}
