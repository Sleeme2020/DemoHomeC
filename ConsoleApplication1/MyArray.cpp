#include "MyArray.h"

void MyArray::clear()
{
	if (Arr != nullptr)
	{
		delete[] Arr;
		Len = 0;
	}
	Arr = nullptr;
}

T& MyArray::operator[](int i)
{
	assert(i >= 0 && i < Len && "Index of not rigion");
	return Arr[i];
}

T MyArray::operator[](int i) const
{
	assert(i >= 0 && i < Len && "Index of not rigion");
	return Arr[i];
}

int MyArray::GetLen() const
{
	return Len;
}

MyArray& MyArray::Move(MyArray& A)
{
	clear();
	Arr = A.Arr;
	Len = A.Len;
	A.Arr = nullptr;
	A.Len = 0;
	return *this;
}

MyArray::MyArray(const MyArray& A)
{
	Arr = new T[A.Len];
	Len = A.Len;
	for (int i = 0; i < Len; i++)
		Arr[i] = A.Arr[i];
}



MyArray::MyArray(int a)
{
	Arr = new T[a];
	Len = a;
}

MyArray::MyArray()
{
	Arr = nullptr;
	Len = 0;
}

MyArray::~MyArray()
{
}

void MyArray::resize(int x)
{
	T* tmp = Arr;
	Arr = new T[Len + x];
	for (size_t i = 0; i < Len; i++)
	{
		Arr[i] = tmp[i];
	}
	Len += x;
	if (tmp != nullptr)
		delete[] tmp;
}


///Удалить тут


void MyArrayKv::clear()
{
	if (Arr != nullptr)
	{
		delete[] Arr;
		Len = 0;
	}
	Arr = nullptr;
}

T2& MyArrayKv::operator[](int i)
{
	assert(i >= 0 && i < Len && "Index of not rigion");
	return Arr[i];
}

T2 MyArrayKv::operator[](int i) const
{
	assert(i >= 0 && i < Len && "Index of not rigion");
	return Arr[i];
}

int MyArrayKv::GetLen() const
{
	return Len;
}

MyArrayKv& MyArrayKv::Move(MyArrayKv& A)
{
	clear();
	Arr = A.Arr;
	Len = A.Len;
	A.Arr = nullptr;
	A.Len = 0;
	return *this;
}



MyArrayKv::MyArrayKv(int a)
{
	Arr = new T2[a];
	Len = a;
}

MyArrayKv::MyArrayKv()
{
	Arr = nullptr;
	Len = 0;
}

MyArrayKv::~MyArrayKv()
{
}

void MyArrayKv::resize(int x)
{
	T2* tmp = Arr;
	Arr = new T2[Len + x];
	for (size_t i = 0; i < Len; i++)
	{
		Arr[i] = tmp[i];
	}
	Len += x;
	if (tmp != nullptr)
		delete[] tmp;
}