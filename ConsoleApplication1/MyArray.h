#pragma once
#include "Human.h"
#include "Kvartira.h"
#include <cassert>
typedef Human T;
typedef Kvartira T2;

class MyArray
{
	T* Arr;
	int Len;
	
public:
	MyArray(int a);
	MyArray();
	~MyArray();
	void resize(int x);
	void clear();
	T& operator[](int i);
	T operator[](int i) const;
	int GetLen() const;
	MyArray& Move(MyArray& A);
	MyArray(const MyArray& A);
};



class MyArrayKv
{
	T2* Arr;
	int Len;

public:
	MyArrayKv(int a);
	MyArrayKv();
	MyArrayKv(const MyArrayKv& kv);
	~MyArrayKv();
	void resize(int x);
	void clear();
	T2& operator[](int i);
	T2 operator[](int i) const;
	int GetLen() const;
	MyArrayKv& operator=(const MyArrayKv& kv);

	MyArrayKv& Move(MyArrayKv& A);
};