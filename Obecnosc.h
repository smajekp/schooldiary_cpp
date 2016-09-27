#pragma once
#include "stdafx.h"

class Obecnosc{
public:
	int idUcznia;
	int idLekcji;
	string nazwaPrzedmiotu;
	string czyObecny;
	string data;

	Obecnosc(int, int, string, string, string);
};