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

