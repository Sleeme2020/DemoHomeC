#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Stack
{
	T* Arr;
	T* Top;
	//int Len;
	T* Down;
public:
	Stack<T>():Stack(10)
	{

	}
	Stack(int a)
	{
		Arr = new T[a];
		Down = (Arr + a - 1);
	}
	void Pop(T& a)
	{
		if (!IsFull())
		{
			if (Top == nullptr)
			{
				Top = Arr;
				*Top = a;
			}
			else
			{
				*(++Top) = a;
			}
		}
	}
	void Pop(T a)
	{
		if (!this->IsFull())
		{
			if (Top == nullptr)
			{
				Top = Arr;
				*Top = a;
			}
			else
			{
				*(++Top) = a;
			}
		}
	}
	T& top()
	{
		if (!this->IsNull()) {
			return *Top;
		}
	}
	void Push()
	{
		if (!IsNull())
		{
			if (Top == Arr)
			{
				Top = nullptr;
			}
			else
				Top--;
		}
	}

	bool IsFull()
	{
		if (Top == Down)
			return true;
		else
			return false;
	}
	bool IsNull()
	{
		if (Top == nullptr)
			return true;
		else
			return false;
	}
	~Stack()
	{
		delete[] Arr;
	}
	Stack& operator=(const Stack& st)
	{
		delete[] Arr;
		/*T* Iter = st.Arr;
		int len = 0;
		do {
			len++;
		} while ((Iter++)<=Down);*/
		int len = sizeof(st.Arr) / sizeof(T);
		Arr = new T[len];
		Top = st.Top;
		for (size_t i = 0; i < len; i++)
		{
			if (st.Top == &(st.Arr[i]))
			{
				Top = &Arr[i];
			}
			Arr[i] = st.Arr[i];
		}
		Down = (Arr + len - 1);
		return *this;
	}
	friend ostream& operator<<(ostream& out, Stack& st)
	{
		
			T* Iter = st.Arr;
			int i = 0;
			if (st.Top != nullptr)
				do {
					out << "[" << ++i << "] " << *Iter << endl;
				} while ((++Iter) <= st.Down);

				return out;
		
	}
};


