#pragma once
#include "Kvartira.h"
#include "MyString.h"
#include "Numerator.h"

class Home
{
	MyArrayKv kvartirs;	
	int num;
	static Numerator numerator;
	int Level;
	MyString Adres;
public:
	Home();
	Home(MyString& adr,int lev);
	Home(MyString& adr, int lev, const Kvartira& kv);
	Home(MyString& adr, int lev, const MyArrayKv& kv);

	//�������� ������������
	Home& operator+(const Kvartira& kvartirs);
	//�������� ��������
	Home& operator+(const Home& hom);
	//������� ��������
	Home& operator-(const Kvartira& kvartirs);
	//����������� �����������
	Home(const Home& hom);
	//����������� ��������
	Home(Home&& hom);
	//�����������
	Home& operator=(const Home& hom);
	//���������
	Home& operator=(Home&& hom);
	//���������� ���� ����� � ����������� 1
	Home& operator=(const Kvartira& kvartirs);
	//���������� ���������
	Kvartira& operator[](int num);

};

