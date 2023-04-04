#pragma once

template<class T>
class ListTemp
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

	int IndexOf(Node* N, T& a, int& i)
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

	void Clear(Node* N)
	{
		if (N->Next != nullptr)
			Clear(N->Next);
		if (N != nullptr)
			delete N;
	}


public:

	ListTemp(ListTemp&& l)
	{
		Root = l.Root;
		Len = l.Len;
		l.Len = 0;
		l.Root = nullptr;
	}
	ListTemp& operator=(ListTemp&& l)
	{
		Clear();
		Root = l.Root;
		Len = l.Len;
		l.Len = 0;
		l.Root = nullptr;
		return *this;
	}

	void Move(ListTemp& l)
	{
		Clear();
		Root = l.Root;
		Len = l.Len;
		l.Len = 0;
		l.Root = nullptr;
	}
	ListTemp& operator=(const ListTemp& l)
	{
		Clear();
		Node* tmp = l.Root;
		while (tmp != nullptr)
		{
			Add(tmp->Obj);
			tmp = tmp->Next;
		}

		return *this;
	}
	ListTemp()
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
	ListTemp& operator+(const ListTemp& list)
	{
		ListTemp L;
		Node* tmp = Root;
		bool flag = false;
			a:
		if (tmp == list.Root)
			flag = true;

		//
		while (tmp!=nullptr)
		{
			L.Add(tmp->Obj);
			tmp = tmp->Next;
		}
		tmp = list.Root;
		
		//
		if (flag)
			return L;
		goto a;
	}

	//Написать оператор копирующего присваивания и оператор присваивания переносом+ конструкторы этих действий
	//**(2 балла на экз) + работающий как объединение и оператор - работающий как исключение
	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}

	int GetLen()
	{
		return Len;
	}
};