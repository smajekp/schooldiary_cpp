#include "stdafx.h"
#include "Bledy.h"

void phoneNumberTypeError(){
	cout << "Numer telefonu musi si� sk�ada� wy��cznie z cyfr (0-9)." << endl;
}

void nameTypeError(){
	cout << "Imi� musi si� sk�ada� wy��cznie z liter." << endl;
}

void surnameTypeError(){
	cout << "Nazwisko musi si� sk�ada� wy��cznie z liter." << endl;
}

void houseNumberTypeError(){
	cout << "Numer domu musi si� sk�ada� wy��cznie z cyfr (0-9)." << endl;
}

void cityTypeError(){
	cout << "Miejscowo�� musi si� sk�ada� wy��cznie z liter." << endl;
}

void menuTypeError(){
	cout << "Wybieraj�c opcj� mo�esz u�ywa� tylko liczb." << endl;
}

void menuChoiceError(){
	cout << "Nie ma takiej opcji w menu." << endl;
}

void idTypeError(){
	cout << "Numer z dziennika ucznia musi by� liczb�." << endl;
}

void lessonTypeError(){
	cout << "Nazwa przedmiotu musi si� sk�ada� wy��cznie z liter." << endl;
}

void idTeacherTypeError(){
	cout << "Id nauczyciela musi by� liczb�." << endl;
}

void rateTypeError(){
	cout << "Mo�esz wprowadzi� tylko takie typy oceny: odpowiedz, kartkowka, sprawdzian, aktywnosc." << endl;
}

void rateError(){
	cout << "Mo�esz wprowadzi� ocen� wy��cznie z zakresu 1-6.";
}