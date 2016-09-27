#pragma once
#include "stdafx.h"
#include "Uczen.h"

class Dziennik  {

public:
	Dziennik();
	~Dziennik();
	void menu();

	//uczen
	int Dziennik::wczytajUczniowZPliku();
	void wypiszWszystkichUczniow();
	void dodajUcznia();
	void zapiszUczniowDoPliku();
	void usunUcznia();
	void edytujUcznia();
	void wstawTabliceUczniow();
	void sortujUczniow();
	void usunWszystkichUczniow();

	//oceny
	void dodajOcene();
	void zapiszOcenyDoPliku();
	void wczytajOcenyZPliku();
	void sprawdzOceny();

	//nauczyciel
	int Dziennik::wczytajNauczycieliZPliku();
	void wypiszWszystkichNauczycieli();
	void dodajNauczyciela();
	void zapiszNauczycieliDoPliku();
	void usunNauczyciela();
	void edytujNauczyciela();
	void sprawdzOcenyPrzedmiotu();	
	void sortujNauczycieli();
	void dodajTemat();
	void zapiszTematDoPliku();
	int wczytajTematyZPliku();
	void wypiszWszystkieTematyPrzedmiotu();
	void sprawdzObecnosc();
	void zapiszObecnosciDoPliku();
	int wczytajObecnosciZPliku();
	void sprawdzNieobecnosci();
	void sredniaZPrzedmiotu();

};