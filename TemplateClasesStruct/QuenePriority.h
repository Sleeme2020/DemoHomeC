#pragma once

template<class T,class Priority>
class QueneP
{
	struct Node
	{
		T Ob;
		Priority Pr;
		Node* Next;
	};
	Node* Root;
	int Len;

	void Add(Node* N, T& a, Priority& p)
	{
		if (N->Next != nullptr)
		{
			if (N->Next->Pr < p)
			{
				Node* tmp = N->Next;
				N->Next = new Node;
				N->Next->ob = a;
				N->Next->Next = tmp;
				N->Next->Pr = p;
				Len++;
			}
			else
			{
				Add(N->Next, a, p);
			}
		}
		else
		{
			N->Next = new Node;
			N->Next->ob = a;
			N->Next->Next = nullptr;
			N->Next->Pr = p;
			Len++;
		}
	}

	T& Pop(Node* N, Priority& pr)
	{
		if (N->Pr == pr)
			return N->Ob;
		else
			if (N->Next != nullptr)
				return Pop(N->Next, pr);
	}
	void Push(Node*& N, Priority& pr)
	{
		if (N->Pr == pr) {
			Node* tmp = N->Next;
			delete N;
			Len--;
			N = tmp;
		}
		else
			if (N->Next != nullptr)
				Push(N->Next, pr);
	}

public:
	Quene()
	{
		Root = nullptr;
		Len = 0;
	}

	void Add(T& a,Priority& p)
	{
		if (Root == nullptr)
		{
			Root = new Node;
			Root->ob = a;
			Root->Next = nullptr;
			Root->Pr = p;
			Len++;
			return;
		}
		Add(Root, a, p);
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

	void Push(Priority& p)
	{
		if (Root != nullptr)
			Push(Root, p);

	}
	T& Pop(Priority& p)
	{
		if (Root != nullptr)
			Pop(Root, p);
	}

};