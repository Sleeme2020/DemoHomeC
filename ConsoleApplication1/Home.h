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

	//Добавляю ползователей
	Home& operator+(const Kvartira& kvartirs);
	//Соеденяю квартиры
	Home& operator+(const Home& hom);
	//Удаляем человека
	Home& operator-(const Kvartira& kvartirs);
	//конструктор копирования
	Home(const Home& hom);
	//Конструктор переноса
	Home(Home&& hom);
	//Присваеваем
	Home& operator=(const Home& hom);
	//переносим
	Home& operator=(Home&& hom);
	//Сбрасываем всех людей и присваеваем 1
	Home& operator=(const Kvartira& kvartirs);
	//индексатор коллекции
	Kvartira& operator[](int num);

};

