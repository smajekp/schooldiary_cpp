#include "stdafx.h"
#include "Obecnosc.h"

Obecnosc::Obecnosc(int idUcznia, int idLekcji, string nazwaPrzedmiotu, string data, string czyObecny) {
	this->idUcznia = idUcznia;
	this->idLekcji = idLekcji;
	this->nazwaPrzedmiotu = nazwaPrzedmiotu;
	this->data = data;
	this->czyObecny = czyObecny;
}
