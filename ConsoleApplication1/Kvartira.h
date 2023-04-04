#pragma once
#include "Human.h"
#include <cassert>
#include "Numerator.h"
#include "MyListTemp.h"
class Kvartira
{
	/*Human* humans;
	int count;*/
	ListTemp<Human> humans;
	static Numerator numerator;
	int num;
	double squaremetr;
	int komnat;	
public:
	void Clear();
	Kvartira();
	Kvartira(int komnat, double squaremetr);
	Kvartira(int komnat, double squaremetr, Human& humans);
	Kvartira(int komnat, double squaremetr, Human* humans);
	
	//�������� ������������
	Kvartira& operator+(const Human& human);
	//�������� ��������
	Kvartira& operator+(const Kvartira& kvartira);
	//������� ��������
	Kvartira& operator-(const Human& human);
	//����������� �����������
	Kvartira(const Kvartira& kvartira);
	//����������� ��������
	Kvartira(Kvartira&& kvartira);
	//�����������
	Kvartira& operator=(const Kvartira& kvartira);
	//���������
	Kvartira& operator=(Kvartira&& kvartira);
	//���������� ���� ����� � ����������� 1
	Kvartira& operator=(const Human& human);
	//���������� ���������
	Human& operator[](int num); 
};

