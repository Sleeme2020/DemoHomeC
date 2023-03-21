#pragma once
class Numerator
{
	struct MyStruct
	{
		int count;
	};
	MyStruct* a;
public:
	Numerator();
	int Next() const;
	~Numerator();
};

