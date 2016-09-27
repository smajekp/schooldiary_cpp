#include "stdafx.h"
#include "Lekcja.h"

Lekcja::Lekcja(int id, string nazwaPrzedmiotu, string temat, string data) {
	this->id = id;
	this->nazwaPrzedmiotu = nazwaPrzedmiotu;
	this->temat = temat;
	this->data = data;
}
