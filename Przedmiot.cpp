#include "stdafx.h"
#include "Przedmiot.h"

//konstruktor sparametryzowany przedmiotu
Przedmiot::Przedmiot(string x_nazwaPrzedmiotu){
	nazwaPrzedmiotu = x_nazwaPrzedmiotu;
}

//funkcja wypisująca
void Przedmiot::wypisz(){
	cout << "Nazwa: " << nazwaPrzedmiotu << endl;
}

