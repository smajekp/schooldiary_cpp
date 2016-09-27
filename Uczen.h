#pragma once
#include "stdafx.h"
#include "Osoba.h"

class Uczen : public Osoba {
public:
	int id;
	string imie;
	string nazwisko;
	string miejscowosc;
	int nrDomu;
	long int nrTelefonu;
public:
	Uczen();
	Uczen(int, string, string, string, int, long int);
	void wypisz();
	bool operator == (const Uczen a);
	bool operator < (const Uczen a);
	Uczen* alokujDynamicznie(int id);
	void zwolnijPamiec(Uczen* a);
	Uczen(const Uczen& a);
};