#pragma once
#include "stdafx.h"

template<typename T>
class Przedmiot {
	T nazwaPrzedmiotu;
	void doSomething(T a) {
		nazwaPrzedmiotu = a;
	}
};