#pragma once
#include "Human.h"
#include <cassert>
#include "MyArray.h"
#include "Numerator.h"
class Kvartira
{
	/*Human* humans;
	int count;*/
	MyArray humans;
	static Numerator numerator;
	int num;
	double squaremetr;
	int komnat;	
	void clear();
	void resize(int x);
public:
	Kvartira();
	Kvartira(int komnat, double squaremetr);
	Kvartira(int komnat, double squaremetr, Human& humans);
	Kvartira(int komnat, double squaremetr, Human* humans, int count);
	
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

