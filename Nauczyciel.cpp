#include "stdafx.h"
#include "Nauczyciel.h"

Nauczyciel::Nauczyciel(){

}

string Nauczyciel::getPrzedmiot() {
	return nazwaPrzedmiotu;
}

Nauczyciel::Nauczyciel(int id, string login, string haslo, string imie, string nazwisko, string funkcja, string nazwaPrzedmiotu, string miejscowosc, int nrDomu, long int nrTelefonu){
	this->id = id;
	this->login = login;
	this->haslo = haslo;
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->funkcja = funkcja;
	this->nazwaPrzedmiotu = nazwaPrzedmiotu;
	this->miejscowosc = miejscowosc;
	this->nrDomu = nrDomu;
	this->nrTelefonu = nrTelefonu;
}

void Nauczyciel::wypisz(){
	cout << id << " " << login << " " << haslo << " " << imie << " " << nazwisko << " " << funkcja << " " << nazwaPrzedmiotu << " " << miejscowosc << " " << nrDomu << " " << nrTelefonu << endl;
}
bool Nauczyciel::operator < (const Nauczyciel a){
	return this->nazwisko < a.nazwisko;
}

string Nauczyciel::getImie(){
	return imie;
}
string Nauczyciel::getNazwisko(){
	return nazwisko;
}
string Nauczyciel::getFunkcja(){
	return funkcja;
}
string Nauczyciel::getLogin(){
	return login;
}
string Nauczyciel::getHaslo(){
	return haslo;
}
