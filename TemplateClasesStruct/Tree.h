#pragma once
template <class T>
class Tree
{
	struct Node
	{
		T ob;
		Node* Left;
		Node* Right;
	};
	Node* Root;
	int Len;

	void AddNode(Node*& N, T& a)
	{
		N = new Node;
		N->Left = nullptr;
		N->Right = nullptr;
		N->ob = a;
		Len++;
	}

	void Add(Node* N, T& a)
	{
		if (a > N->ob)
		{
			if (N->Right == nullptr)
				AddNode(N->Right, a);
			else
				Add(N->Right, a);
		}
		if(a < N->ob)
		{
			if (N->Left == nullptr)
				AddNode(N->Left, a);
			else
				Add(N->Left, a);

		}

	}
	void clear(Node* N)
	{
		if (N != nullptr)
		{
			if (N->Left != nullptr)
				clear(N->Left);
			if (N->Right != nullptr)
				clear(N->Right);
			delete N;
			Len--;
		}
	}

	Node* FindNode(Node* N,T& a)
	{
		if (N != nullptr)
		{
			if (N->ob == a)
				return N;
			Node* tmp=nullptr;
			tmp =FindNode(N->Left, a);
			if(tmp==nullptr)
				tmp=FindNode(N->Right, a);
			return tmp;
		}
		return nullptr;
	}

public:
	Tree()
	{
		Root = nullptr;
		Len = 0;
	}

	void Add(T& a)
	{
		if (Root == nullptr)
		{
			AddNode(Root, a);
			return;		
		}
		Add(Root, a);
	}

	T R(Node*& N)
	{
		if (N->Rigt == nullptr)
		{
			T s = N->Obj;
			if (N->Left != nullptr)
			{
				Node* tmp = N->Left;
				delete N;
				N = tmp;
			}
			else
			{
				delete N;
				N = nullptr;
			}
			return s;
		}
		else
		{
			R(N->Rigt);
		}
	}



	void Remove(T& a)
	{
		if (Empty(a))
		{
			Node* tmp = FindNode(Root, a);
			tmp->Obj = R(tmp->Left);
		}
	}


	/*void Remove(T& a)
	{

	}*/

	void RemoveTree(T& a)
	{
		clear(FindNode(Root, a));
	}

	bool Empty(T& a)
	{
		if (FindNode(Root, a) == nullptr)
			return false;
		else
			return true;
	}


	~Tree()
	{
		clear(Root);
	}
};