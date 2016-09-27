#pragma once
#include "stdafx.h"
#include "Osoba.h"

class Nauczyciel : public Osoba {
public:
	int id;
	string login;
	string haslo;
	string imie;
	string nazwisko;
	string funkcja;
	string nazwaPrzedmiotu;
	string miejscowosc;
	int nrDomu;
	long int nrTelefonu;
	
public:
	Nauczyciel();
	Nauczyciel(int,string , string, string, string, string, string, string, int, long int);
	void wypisz();
	bool operator < (const Nauczyciel a);

	string getLogin();
	string getHaslo();
	string getImie();
	string getNazwisko();
	string getPrzedmiot();
	string getFunkcja();
};