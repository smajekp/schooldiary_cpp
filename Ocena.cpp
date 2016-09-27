#include "stdafx.h"
#include "Ocena.h"

//konstruktor sparametryzowany oceny
Ocena::Ocena(int id, string przedmiot, string typ, int wartosc) {
	this->id = id;
	this->przedmiot = przedmiot;
	this->typ = typ;
	this->wartosc = wartosc;
}

//funkcja wypisuj¹ca
void Ocena::wypisz() {
	cout << "Id ucznia: " << id << endl;
	cout << "Przedmiot: " << przedmiot << endl;
	cout << "Typ: " << typ << endl;
	cout << "Ocena: " << wartosc << endl;
}
bool Ocena::operator == (const Ocena a){
	return wartosc == a.wartosc;
}
Ocena& Ocena::operator+=(const Ocena& vec){
	return Ocena(this->id, this->przedmiot, this->typ, this->wartosc + 1);
}
/*
Ocena a(...)
Ocena b(..)
a =+b;
a dodaje +1
*/

Ocena& Ocena::operator-=(const Ocena& vec) {
	return Ocena(this->id, this->przedmiot, this->typ, this->wartosc - 1);
}
