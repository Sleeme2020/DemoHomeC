#pragma once
#include "Human.h"


class Kvartira
{
	Human* humans;
	int count;
	static int numerator;
	int num;
	double squaremetr;
	int komnat;
	void getnum();
public:
	Kvartira();
	Kvartira(int komnat, double squaremetr);
	Kvartira(int komnat, double squaremetr, Human& humans);
	Kvartira(int komnat, double squaremetr, Human* humans, int count);
	//Добавляю ползователей
	Kvartira& operator+(const Human& human);
	//Соеденяю квартиры
	Kvartira& operator+(const Kvartira& kvartira);
	//Удаляем человека
	Kvartira& operator-(const Human& human);
	//конструктор копирования
	Kvartira(const Kvartira& kvartira);
	//Конструктор переноса
	Kvartira(Kvartira&& kvartira);
	//Присваеваем
	Kvartira& operator=(const Kvartira& kvartira);
	//переносим
	Kvartira& operator=(Kvartira&& kvartira);
	//Сбрасываем всех людей и присваеваем 1
	Kvartira& operator=(const Human& human);
	//индексатор коллекции
	Human& operator[](int num);
};

