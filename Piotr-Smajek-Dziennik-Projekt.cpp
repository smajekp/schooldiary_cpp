// Piotr-Smajek-Dziennik-Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lekcja.h"
#include "Przedmiot.h"
#include "Osoba.h"
#include "Uczen.h"
#include "Nauczyciel.h"
#include "Ocena.h"
#include "Dziennik.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//ustawianie polskich znaków
	setlocale(LC_ALL, "polish");

	Dziennik d;

	while (1){

		d.menu();

	}



	system("PAUSE");
}

