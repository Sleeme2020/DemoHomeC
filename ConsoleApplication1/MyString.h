#pragma once
class MyString
{
	char* str;
	int len;
public:
	MyString();
	MyString& operator+(const MyString& b);
	MyString& operator+(const char* b);
	MyString& operator=(const MyString& b);
	MyString& operator=(MyString&& b);
	bool operator==(const MyString& b);
	MyString Add(const MyString& a, const MyString& b);
	MyString(const MyString& tmp);
	MyString(MyString&& tmp);
	explicit MyString(const char* str);
	~MyString();
	char* GetStr();
	void SetStr(char* a);
	void Print();
	friend MyString& operator+(const char* a, const MyString& b);

};

MyString& operator+(const char* str, const MyString& b);
