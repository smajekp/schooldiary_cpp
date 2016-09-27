#include "stdafx.h"
#include "Uczen.h"

Uczen::Uczen(){

}

Uczen::Uczen(int id, string imie, string nazwisko, string miejscowosc, int nrDomu, long int nrTelefonu){
	this->id = id;
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->miejscowosc = miejscowosc;
	this->nrDomu = nrDomu;
	this->nrTelefonu = nrTelefonu;
}
bool Uczen::operator < (const Uczen a){
	return this->nazwisko < a.nazwisko;
}
Uczen::Uczen(const Uczen& a) {
	id = a.id;
	imie = a.imie;
	nazwisko = a.nazwisko;
	miejscowosc = a.miejscowosc;
	nrDomu = a.nrDomu;
	nrTelefonu = a.nrTelefonu;
}

void Uczen::wypisz(){
	cout << id << " " << imie << " " << nazwisko << " " << miejscowosc << " " << nrDomu << " " << nrTelefonu << endl;
}

bool Uczen::operator == (const Uczen a)
{
	return a.id == id;
}

Uczen* alokujDynamicznie(int id) {
	Uczen* nowy = new Uczen;
	return nowy;
}

void zwolnijPamiec(Uczen* a) {
	delete a;
	a = NULL;
}






