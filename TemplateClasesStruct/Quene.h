#pragma once


template<class T>
class Quene
{
	struct Node
	{
		T ob;
		Node* Next;
	};

	Node* Root;
	Node* End;
	int Len;

public:
	Quene()
	{
		Root = nullptr;
		End = nullptr;
		Len = 0;
	}

	void Add(T& a)
	{
		if (Root == nullptr)
		{
			Root = new Node;
			Root->ob = a;
			End = Root;
			Len++;
			return;
		}
		End->Next = new Node;
		End = End->Next;
		End->ob = a;
		End->Next = nullptr;
		Len++;
	}

	void Push()
	{
		if (Root != nullptr)
		{
			Node* tmp = Root;
			Root = Root->Next;
			Len--;
			delete tmp;
		}
	}
	T& Pop()
	{
		if (Root != nullptr)
			return Root->ob;
	}


};