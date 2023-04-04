#pragma once

template<class T>
class List
{
	struct Node
	{
		T Obj;
		Node* Next;
	};
	Node* Root;
	int Len;

	void Add(Node* N, T& a)
	{
		if (N->Next != nullptr)
			Add(N->Next, a);
		else
		{
			N->Next = new Node;
			N->Next->Obj = a;
			N->Next->Next = nullptr;
			Len++;
			return;
		}
	}

	int IndexOf(Node* N,T& a, int& i)
	{
		if (N->Obj == a)
			return i;
		if (N->Next == nullptr)
			return -1;
		else
			return IndexOf(N->Next, a, ++i);
	}

	T& Go_To_index(int& i, Node* N)
	{
		if (i == 0)
			return N->Obj;
		else
			return Go_To_index(--i, N->Next);
	}
	void Remove(int& i, Node* N)
	{
		if (i == 0)
		{
			Node* tmp = N->Next;
			N->Next = N->Next->Next;
			delete tmp;
			Len--;
		}
		else
			Remove(--i, N->Next);
	}

public:

	List()
	{
		Root = nullptr;
		Len = 0;
	}
	void Add(T& a)
	{
		if (Root == nullptr)
		{
			Root = new Node;
			Root->Obj = a;
			Root->Next = nullptr;
			Len++;
			return;
		}
		Add(Root, a);
	}

	int IndexOf(T& a)
	{
		int x = 0;
		if (Root == nullptr)
			return -1;
		return IndexOf(Root, a, x);
	}

	T& operator[](int x)
	{
		
		// assert ? X>=0 or x<len
		return Go_To_index(x, Root);
	}

	void Remove(int x)
	{
		//assert
		if (x == 0)
		{
			Node* tmp = Root;
			Root = Root->Next;
			delete tmp;
			Len--;
		}
		else
		{
			Remove(--x, Root);
		}

	}

	void Remove(T& a)
	{
		int x = IndexOf(a);
		if (x != -1)
			Remove(x);
	}

	//Написать оператор копирующего присваивания и оператор присваивания переносом+ конструкторы этих действий
	//**(2 балла на экз) + работающий как объединение и оператор - работающий как исключение


	int GetLen()
	{
		return Len;
	}
};