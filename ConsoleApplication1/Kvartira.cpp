#include "Kvartira.h"





void Kvartira::Clear()
{
	humans.Clear();
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
	this->humans.Add(humans);
	

}

Kvartira::Kvartira(int komnat, double squaremetr
	, Human* humans):Kvartira(komnat, squaremetr)
{
	for (int i = 0; i < sizeof(humans)/sizeof(Human); i++)
	{
		this->humans.Add(humans[i]);
	}
}



Kvartira& Kvartira::operator+(const Human& human)
{
	
	Human h = human;//костыль для конст

	this->humans.Add(h);
	return *this;
}

Kvartira& Kvartira::operator+(const Kvartira& kvartira)
{
	humans = humans + kvartira.humans;
	komnat += kvartira.komnat;
	squaremetr += kvartira.squaremetr;
	return *this;
}

Kvartira& Kvartira::operator-(const Human& human)
{
	Human h = human;//костыль для конст
	humans.Remove(humans.IndexOf(h));
	return *this;
}

Kvartira::Kvartira(Kvartira&& kvartira)
{
	humans.Move(kvartira.humans);
	komnat = kvartira.komnat;
	squaremetr = kvartira.squaremetr;
}

Kvartira& Kvartira::operator=(const Kvartira& kvartira)
{
	
	humans = kvartira.humans;
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
	humans.Clear();
	Human h = human;//костыль для конст
	humans.Add(h);
	return *this;
}

Human& Kvartira::operator[](int num)
{
	assert(num>=0 && num< humans.GetLen() && "Index of not rigion");
	return humans[num];
}
