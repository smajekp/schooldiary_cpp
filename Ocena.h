#pragma once
#include "stdafx.h"

class Ocena{
public:
	int id;
	string przedmiot;
	string typ;
	int wartosc;

public:
	Ocena(int, string, string, int );
	void wypisz();
	Ocena& operator+=(const Ocena& o);
	Ocena& operator-=(const Ocena& o);
	inline bool operator == (const Ocena);
	/*
	w programie mozmey teraz pisac
	Ocena a;
	cout<<a;
	cin>>a;
	*/
};

