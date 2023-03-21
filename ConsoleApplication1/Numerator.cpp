#include "Numerator.h"

Numerator::Numerator()
{
	a=new MyStruct;
	a->count=0;
}

int Numerator::Next() const
{
	a->count++;
	return a->count;
}

Numerator::~Numerator()
{
	delete a;
}

