#pragma once
template<class T>
class List
{
	struct Node
	{
		T Obj;
		Node* Next;
		Node* Prev;
	};
	Node* Root;
	Node* End;
	int Len;
	void Add(Node* N, T& a)
	{
		N->Next = new Node;
		N->Next->Obj = a;
		N->Next->Next = nullptr;
		Len++;
		N->Next->Prev = N;
		End = N->Next;
	}

	int IndexOf(int& i, Node* N, T& a)
	{
		if (N->Obj == a)
		{
			return i;
		}
		else
		{
			if (N->Next == nullptr)
			{
				return -1;
			}
			else
			{
				return IndexOf(i + 1, N->Next, a);
			}
		}
	}
	
	T& Go_To_indexD(int& i, Node* N)
	{
		if (i == 0)
			return N->Obj;
		else
			return Go_To_index(--i, N->Next);
	}
	T& Go_To_indexR(int& i, Node* N)
	{
		if (i == 0)
			return N->Obj;
		else
			return Go_To_indexR(--i, N->Prev);
	}

	void RemoveD(int& i, Node* N)
	{
		if (i == 0)
		{
			Node* tmp = N->Next;
			N->Next = N->Next->Next;
			delete tmp;
			Len--;
		}
		else
			RemoveD(--i, N->Next);
	}
	void RemoveR(int& i, Node* N)
	{
		if (i == 0)
		{
			Node* tmp = N->Prev;
			N->Prev = N->Prev->Prev;
			delete tmp;
			Len--;
		}
		else
			RemoveR(--i, N->Prev);
	}

	

public:


	ListD()
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
			Root->Obj = a;
			Root->Next = nullptr;
			Len++;
			End = Root;
			return;
		}
		Add(End, a);
	}

	int IndexOf(T& a)
	{
		int x = 0;
		if (Root == nullptr)
		{
			return -1;
		}
		return IndexOf(x, Root, a);
	}


	T& operator[](int x)
	{

		// assert ? X>=0 or x<len
		if(Len/2>x)
			return Go_To_indexD(x, Root);
		else
			return Go_To_indexD(Len - 1 -x, End);
	}
	int GetLen()
	{
		return Len;
	}

	void Remove(int x)
	{
		//assert
		if (x == 0)
		{
			Node* tmp = Root;
			Root = Root->Next;
			delete tmp;
			Root->Prev = nullptr;
			Len--;
			return;
		}
		if (x - 1 == Len)
		{
			Node* tmp = End;
			End = End->Prev;
			delete tmp;
			End->Next= nullptr;
			Len--;
			return;
		}
		if (Len / 2 > x)
			RemoveD(--x, Root);
		else
			RemoveR(Len-1-(--x), End);

	}

	void Remove(T& a)
	{
		int x = IndexOf(a);
		if (x != -1)
			Remove(x);
	}

};