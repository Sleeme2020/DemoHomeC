#include "Home.h"

Home::Home(MyString& adr, int lev, const MyArrayKv& kv) :kvartirs{kv}
{
	this->Adres = adr;
	Level = lev;
}

Home::Home(Home&& hom)
{
	Level = hom.Level;
	Adres = hom.Adres;
	kvartirs.Move(hom.kvartirs);
	
	
}
