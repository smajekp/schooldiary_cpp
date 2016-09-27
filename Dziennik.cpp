#include "stdafx.h"
#include "Dziennik.h"
#include "Uczen.h"
#include "Nauczyciel.h"
#include "Ocena.h"
#include "Bledy.h"
#include "Lekcja.h"
#include "Obecnosc.h"

vector <Nauczyciel> tablicaNauczycieli;
vector<Uczen> tablicaUczniow;
vector<Ocena> tablicaOcen;
vector<Lekcja> tablicaLekcji;
vector<Obecnosc> tablicaObecnosci;

int idLekcji = 1;
string przedmiotNauczyciela;

Dziennik::Dziennik() {
}

Dziennik::~Dziennik() {
}


bool cmp1(Uczen i, Uczen j) {
	return (i < j); // przeciazony operator
}

void Dziennik::sortujUczniow() {
	sort(tablicaUczniow.begin(), tablicaUczniow.end(), cmp1);
	int size = tablicaUczniow.size();
	for (int i = 0; i < size; i++) {
		tablicaUczniow[i].id = i + 1;
	}
}

void Dziennik::dodajUcznia() {
	system("CLS");

	wczytajUczniowZPliku();

	int id = wczytajUczniowZPliku() + 1;
	string imie;
	string nazwisko;
	string miejscowosc;
	int nrDomu;
	string nrDomuTmp;
	long int nrTelefonu;
	string nrTelefonuTmp;

	cout << "\t\t\t\t--- DODAWANIE UCZNIA ---" << endl;

	bool isError;

	while (1) {
		cout << endl << "Wpisz imiê ucznia:" << endl;
		cin >> imie;
		for (size_t i = 0; i < imie.length(); i++)
		{
			if (!(imie[i] < 47 || imie[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			nameTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz nazwisko ucznia:" << endl;
		cin >> nazwisko;
		for (size_t i = 0; i < nazwisko.length(); i++)
		{
			if (!(nazwisko[i] < 47 || nazwisko[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			surnameTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz miejscowoœæ, w której mieszka uczeñ:" << endl;
		cin >> miejscowosc;
		for (size_t i = 0; i < miejscowosc.length(); i++)
		{
			if (!(miejscowosc[i] < 47 || miejscowosc[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			cityTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz numer domu, w którym mieszka uczeñ:" << endl;
		cin >> nrDomuTmp;
		for (size_t i = 0; i < nrDomuTmp.length(); i++)
		{
			if (!(nrDomuTmp[i] > 47 && nrDomuTmp[i] < 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			houseNumberTypeError();
		}
		else {
			istringstream iss(nrDomuTmp);
			iss >> nrDomu;
			break;
		}
	}

	while (1) {

		cout << endl << "Wpisz numer telefonu ucznia:" << endl;
		cin >> nrTelefonuTmp;

		for (size_t i = 0; i < nrTelefonuTmp.length(); i++)
		{
			if (!(nrTelefonuTmp[i] > 47 && nrTelefonuTmp[i] < 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			phoneNumberTypeError();
		}
		else {
			if (nrTelefonuTmp.length() < 9)
				cout << endl << "Numer telefonu jest za krótki. Musi siê sk³adaæ z 9 znakow" << endl;
			else if (nrTelefonuTmp.length() > 9)
				cout << endl << "Numer telefonu jest za d³ugi. Musi siê sk³adaæ z 9 znakow" << endl;
			else {
				istringstream iss(nrTelefonuTmp);
				iss >> nrTelefonu;
				break;
			}
		}
	}

	Uczen nowy(id, imie, nazwisko, miejscowosc, nrDomu, nrTelefonu);
	tablicaUczniow.push_back(nowy);
	zapiszUczniowDoPliku();

	cout << endl << "Dodano nowego ucznia!" << endl;
	Sleep(1500);
	system("CLS");
}

void Dziennik::usunUcznia() {
	system("CLS");

	cout << "\t\t\t\t--- USUWANIE UCZNIA ---" << endl;

	wczytajUczniowZPliku();
	wypiszWszystkichUczniow();

	int id;
	string idTmp;
	bool isError;

	int size = tablicaUczniow.size();
	if (size <= 0) {
		cout << endl << "Brak uczniów w dzienniku.";
		Sleep(1500);
		system("CLS");
	}
	else {

		while (1) {
			cout << endl << "Wpisz numer z dziennika ucznia, którego chcesz usun¹æ" << endl;
			cin >> idTmp;
			for (size_t i = 0; i < idTmp.length(); i++)
			{
				if (!(idTmp[i] > 47 && idTmp[i] < 58))
					isError = true;
				else
					isError = false;
			}
			if (isError == true) {
				idTypeError();
			}
			else {
				istringstream iss(idTmp);
				iss >> id;
				id--;
				break;
			}
		}

		auto i = tablicaUczniow.end();
		if (id < 0 || id >(*(i - 1)).id) {//mozna zamienic na try catcha
			cout << "Wpisano niepoprawny numer z dziennika." << endl;
		}
		else{
			cout << endl << "Czy na pewno chcesz usun¹æ tego ucznia? (t/n)" << endl;

			char wybor;
			cin >> wybor;

			if (wybor == 't') {
				size = tablicaUczniow.size();
				for (int i = id; i < size - 1; ++i)
					tablicaUczniow[i] = tablicaUczniow[i + 1];
				tablicaUczniow.pop_back();
				size = tablicaUczniow.size();
				for (int i = 0; i < size; i++)
					tablicaUczniow[i].id = i;
				zapiszUczniowDoPliku();

				cout << endl << "Uczeñ zosta³ usuniêty." << endl;
				Sleep(1500);
				system("CLS");
			}
			else
			{
				system("CLS");
			}
		}
	}

}

void Dziennik::usunWszystkichUczniow(){
	tablicaUczniow.clear();
	zapiszUczniowDoPliku();

	cout << endl << "Pomyœlnie usuniêto wszystkich uczniów" << endl;
	Sleep(1500);
	system("CLS");
}

void Dziennik::edytujUcznia() {

	while (1){
		system("CLS");

		cout << "\t\t\t\t--- EDYCJA UCZNIA ---" << endl;

		wczytajUczniowZPliku();
		wczytajOcenyZPliku();
		wypiszWszystkichUczniow();

		/*try
		{
		if (id < 0)
		throw;
		cout << "Zle id" << endl;
		}
		catch(e){

		}*/

		bool isError;

		int id;
		string idTmp;

		while (1) {
			cout << endl << "Wpisz numer z dziennika ucznia którego chcesz edytowaæ" << endl;
			cin >> idTmp;
			for (size_t i = 0; i < idTmp.length(); i++)
			{
				if (!(idTmp[i] > 47 && idTmp[i] < 58))
					isError = true;
				else
					isError = false;
			}
			if (isError == true) {
				idTypeError();
			}
			else {
				istringstream iss(idTmp);
				iss >> id;
				id--;
				break;
			}
		}

		auto i = tablicaUczniow.end();
		if (id < 0 || id >(*(i - 1)).id) {//mozna zamienic na try catcha
			cout << "Wpisano niepoprawny numer z dziennika." << endl;
			Sleep(1500);
			system("CLS");
		}
		else{

			string imie, nazwisko, miejscowosc, nrDomuTmp, nrTelefonuTmp;
			int nrDomu;
			long int nrTelefonu;

			int wyborModyfikacja;
			string wyborModyfikacjaTmp;

			while (1) {

				system("CLS");

				cout << "\t\t\t\t--- EDYCJA UCZNIA ---" << endl;

				cout << endl << "Edytujesz ucznia: " << endl;
				cout << tablicaUczniow[id].id << " " << tablicaUczniow[id].imie << " " << tablicaUczniow[id].nazwisko << " " << tablicaUczniow[id].miejscowosc << " " << tablicaUczniow[id].nrDomu << " " << tablicaUczniow[id].nrTelefonu << endl;
				cout << endl << "Wybierz jedn¹ z poni¿szych opcji" << endl << endl;
				cout << "1. Edytuj imiê ucznia" << endl;
				cout << "2. Edytuj nazwisko ucznia" << endl;
				cout << "3. Edytuj miejscowoœc ucznia" << endl;
				cout << "4. Edytuj nr domu ucznia" << endl;
				cout << "5. Edytuj nr telefonu ucznia" << endl;
				cout << "6. Zakoñcz edycjê" << endl << endl;

				bool isError;

				cin >> wyborModyfikacjaTmp;
				for (size_t i = 0; i < wyborModyfikacjaTmp.length(); i++)
				{
					if (!(wyborModyfikacjaTmp[i] > 47 && wyborModyfikacjaTmp[i] < 58))
						isError = true;
					else
						isError = false;
				}
				if (isError == true) {
					idTypeError();
					Sleep(1500);
					system("CLS");
				}
				else {
					istringstream iss(wyborModyfikacjaTmp);
					iss >> wyborModyfikacja;

					switch (wyborModyfikacja) {

					case 1: {

								while (1) {
									cout << endl << "Wpisz imiê ucznia:" << endl;
									cin >> imie;
									for (size_t i = 0; i < imie.length(); i++)
									{
										if (!(imie[i] < 47 || imie[i] > 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										nameTypeError();
									}
									else {
										tablicaUczniow[id].imie = imie;
										cout << endl << "Imiê pomyœlnie zaktualizowane.";
										Sleep(1500);
										break;
									}
								}
								break;

					}

					case 2: {
								while (1) {
									cout << endl << "Wpisz nazwisko ucznia:" << endl;
									cin >> nazwisko;
									for (size_t i = 0; i < nazwisko.length(); i++)
									{
										if (!(nazwisko[i] < 47 || nazwisko[i] > 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										surnameTypeError();
									}
									else {
										tablicaUczniow[id].nazwisko = nazwisko;
										cout << endl << "Nazwisko pomyœlnie zaktualizowane.";
										Sleep(1500);
										break;
									}
								}
								break;
					}

					case 3: {
								while (1) {
									cout << endl << "Wpisz miejscowoœæ w której mieszka uczeñ:" << endl;
									cin >> miejscowosc;
									for (size_t i = 0; i < miejscowosc.length(); i++)
									{
										if (!(miejscowosc[i] < 47 || miejscowosc[i] > 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										cityTypeError();
									}
									else {
										tablicaUczniow[id].miejscowosc = miejscowosc;
										cout << endl << "Miejscowoœæ pomyœlnie zaktualizowana.";
										Sleep(1500);
										break;
									}
								}
								break;
					}
					case 4: {
								while (1) {
									cout << endl << "Wpisz numer domu, w którym mieszka uczeñ:" << endl;
									cin >> nrDomuTmp;
									for (size_t i = 0; i < nrDomuTmp.length(); i++)
									{
										if (!(nrDomuTmp[i] > 47 && nrDomuTmp[i] < 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										houseNumberTypeError();
									}
									else {
										istringstream iss(nrDomuTmp);
										iss >> nrDomu;

										tablicaUczniow[id].nrDomu = nrDomu;
										cout << endl << "Numer domu pomyœlnie zaktualizowany.";
										Sleep(1500);
										break;
									}
								}
								break;
					}

					case 5: {
								while (1) {

									cout << endl << "Wpisz numer telefonu ucznia:" << endl;
									cin >> nrTelefonuTmp;

									for (size_t i = 0; i < nrTelefonuTmp.length(); i++)
									{
										if (!(nrTelefonuTmp[i] > 47 && nrTelefonuTmp[i] < 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										phoneNumberTypeError();
									}
									else {
										if (nrTelefonuTmp.length() < 9)
											cout << endl << "Numer telefonu jest za krótki. Musi siê sk³adaæ z 9 znakow" << endl;
										else if (nrTelefonuTmp.length() > 9)
											cout << endl << "Numer telefonu jest za d³ugi. Musi siê sk³adaæ z 9 znakow" << endl;
										else {
											istringstream iss(nrTelefonuTmp);
											iss >> nrTelefonu;

											tablicaUczniow[id].nrTelefonu = nrTelefonu;
											cout << endl << "Numer telefonu pomyœlnie zaktualizowany.";
											Sleep(1500);
											break;
										}
									}
								}
								break;
					}
					case 6: {
								zapiszUczniowDoPliku();
								system("CLS");
								return;
					}
					default: {
								 cout << "Nie ma takiej opcji. Spróbuj jeszcze raz";
								 Sleep(1500);
								 break;
					}
					}
				}
			}
		}
	}

}

int Dziennik::wczytajUczniowZPliku() { //wczytuje uczniow z pliku i zwraca id ostatniego
	tablicaUczniow.clear();
	ifstream data("dane-uczniow.txt");
	int id = 0;
	string imie;
	string nazwisko;
	string miejscowosc;
	int nrDomu;
	long int nrTelefonu;

	while (data >> id >> imie >> nazwisko >> miejscowosc >> nrDomu >> nrTelefonu) {
		Uczen nowyUczen(id, imie, nazwisko, miejscowosc, nrDomu, nrTelefonu);
		tablicaUczniow.push_back(nowyUczen);
	}
	return id;
}

void Dziennik::wypiszWszystkichUczniow() {
	if (tablicaUczniow.size() == 0)
		cout << "Brak uczniów w dzienniku" << endl;
	for (auto i = tablicaUczniow.begin(); i != tablicaUczniow.end(); i++)
		(*i).wypisz();
}

void Dziennik::zapiszUczniowDoPliku() {
	sortujUczniow();
	ofstream f("dane-uczniow.txt");
	for (auto i = tablicaUczniow.begin(); i != tablicaUczniow.end(); ++i) {
		f << (*i).id << " " << (*i).imie << " " << (*i).nazwisko << " " << (*i).miejscowosc << " " << (*i).nrDomu << " " << (*i).nrTelefonu << '\n';
	}

}

bool cmp2(Nauczyciel i, Nauczyciel j) {
	return (i < j); // przeciazony operator
}

void Dziennik::sortujNauczycieli() {
	sort(tablicaNauczycieli.begin(), tablicaNauczycieli.end(), cmp2);
	int size = tablicaNauczycieli.size();
	for (int i = 0; i < size; i++) {
		tablicaNauczycieli[i].id = i + 1;
	}
}

void Dziennik::dodajNauczyciela() {
	system("CLS");

	wczytajNauczycieliZPliku();

	int id = wczytajNauczycieliZPliku() + 1;
	string login;
	string haslo;
	string imie;
	string nazwisko;
	string miejscowosc;
	string funkcja;
	string nazwaPrzedmiotu;
	int nrDomu;
	string nrDomuTmp;
	long int nrTelefonu;
	string nrTelefonuTmp;

	cout << "\t\t\t\t--- DODAWANIE NAUCZYCIELA ---" << endl;

	cout << endl << "Wpisz login nauczyciela:" << endl;
	cin >> login;

	cout << endl << "Wpisz has³o nauczyciela:" << endl;
	cin >> haslo;

	bool isError;

	while (1) {
		cout << endl << "Wpisz imiê nauczyciela:" << endl;
		cin >> imie;
		for (size_t i = 0; i < imie.length(); i++)
		{
			if (!(imie[i] < 47 || imie[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			nameTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz nazwisko nauczyciela:" << endl;
		cin >> nazwisko;
		for (size_t i = 0; i < nazwisko.length(); i++)
		{
			if (!(nazwisko[i] < 47 || nazwisko[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			surnameTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz nazwê przedmiotu, którego uczy nauczyciel:" << endl;
		cin >> nazwaPrzedmiotu;
		for (size_t i = 0; i < nazwaPrzedmiotu.length(); i++)
		{
			if (!(nazwaPrzedmiotu[i] < 47 || nazwaPrzedmiotu[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			lessonTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz miejscowoœæ, w której mieszka nauczyciel:" << endl;
		cin >> miejscowosc;
		for (size_t i = 0; i < miejscowosc.length(); i++)
		{
			if (!(miejscowosc[i] < 47 || miejscowosc[i] > 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			cityTypeError();
		}
		else {
			break;
		}
	}

	while (1) {
		cout << endl << "Wpisz numer domu, w którym mieszka nauczyciel:" << endl;
		cin >> nrDomuTmp;
		for (size_t i = 0; i < nrDomuTmp.length(); i++)
		{
			if (!(nrDomuTmp[i] > 47 && nrDomuTmp[i] < 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			houseNumberTypeError();
		}
		else {
			istringstream iss(nrDomuTmp);
			iss >> nrDomu;
			break;
		}
	}

	while (1) {

		cout << endl << "Wpisz numer telefonu nauczyciela:" << endl;
		cin >> nrTelefonuTmp;

		for (size_t i = 0; i < nrTelefonuTmp.length(); i++)
		{
			if (!(nrTelefonuTmp[i] > 47 && nrTelefonuTmp[i] < 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			phoneNumberTypeError();
		}
		else {
			if (nrTelefonuTmp.length() < 9)
				cout << endl << "Numer telefonu jest za krótki. Musi siê sk³adaæ z 9 znakow" << endl;
			else if (nrTelefonuTmp.length() > 9)
				cout << endl << "Numer telefonu jest za d³ugi. Musi siê sk³adaæ z 9 znakow" << endl;
			else {
				istringstream iss(nrTelefonuTmp);
				iss >> nrTelefonu;
				break;
			}
		}
	}

	funkcja = "Nauczyciel";

	Nauczyciel nowy(id, login, haslo, imie, nazwisko, funkcja, nazwaPrzedmiotu, miejscowosc, nrDomu, nrTelefonu);
	tablicaNauczycieli.push_back(nowy);
	zapiszNauczycieliDoPliku();

	cout << endl << "Dodano nowego nauczyciela!" << endl;
	Sleep(1500);
	system("CLS");
}

void Dziennik::usunNauczyciela() {
	system("CLS");

	cout << "\t\t\t\t--- USUWANIE NAUCZYCIELA ---" << endl;

	wczytajNauczycieliZPliku();
	wypiszWszystkichNauczycieli();

	int id;
	string idTmp;
	bool isError;

	int size = tablicaNauczycieli.size();
	if (size <= 0) {
		cout << endl << "Brak nauczycieli.";
		Sleep(1500);
		system("CLS");
	}
	else {

		while (1) {
			cout << endl << "Wpisz id nauczyciela, którego chcesz usun¹æ" << endl;
			cin >> idTmp;
			for (size_t i = 0; i < idTmp.length(); i++)
			{
				if (!(idTmp[i] > 47 && idTmp[i] < 58))
					isError = true;
				else
					isError = false;
			}
			if (isError == true) {
				idTeacherTypeError();
			}
			else {
				istringstream iss(idTmp);
				iss >> id;
				id--;
				break;
			}
		}

		auto i = tablicaNauczycieli.end();
		if (id < 0 || id >(*(i - 1)).id) {
			cout << "Wpisano niepoprawne id." << endl;
		}
		else{
			cout << endl << "Czy na pewno chcesz usun¹æ tego nauczyciela? (t/n)" << endl;

			char wybor;
			cin >> wybor;

			if (wybor == 't') {
				size = tablicaNauczycieli.size();
				for (int i = id; i < size - 1; ++i)
					tablicaNauczycieli[i] = tablicaNauczycieli[i + 1];
				tablicaNauczycieli.pop_back();
				size = tablicaNauczycieli.size();
				for (int i = 0; i < size; i++)
					tablicaNauczycieli[i].id = i;
				zapiszNauczycieliDoPliku();

				cout << endl << "Nauczyciel zosta³ usuniêty." << endl;
				Sleep(1500);
				system("CLS");
			}
			else
			{
				system("CLS");
			}
		}
	}

}

void Dziennik::edytujNauczyciela() {

	while (1){
		system("CLS");

		cout << "\t\t\t\t--- EDYCJA NAUCZYCIELA ---" << endl;

		wczytajNauczycieliZPliku();
		wypiszWszystkichNauczycieli();

		/*try
		{
		if (id < 0)
		throw;
		cout << "Zle id" << endl;
		}
		catch(e){

		}*/

		bool isError;

		int id;
		string idTmp;

		while (1) {
			cout << endl << "Wpisz id nauczyciela, którego chcesz edytowaæ" << endl;
			cin >> idTmp;
			for (size_t i = 0; i < idTmp.length(); i++)
			{
				if (!(idTmp[i] > 47 && idTmp[i] < 58))
					isError = true;
				else
					isError = false;
			}
			if (isError == true) {
				idTypeError();
			}
			else {
				istringstream iss(idTmp);
				iss >> id;
				id--;
				break;
			}
		}

		auto i = tablicaNauczycieli.end();
		if (id < 0 || id >(*(i - 1)).id) {
			cout << "Wpisano niepoprawne id nauczyciela." << endl;
			Sleep(1500);
			system("CLS");
		}
		else{

			string imie, login, haslo, nazwisko, nazwaPrzedmiotu, miejscowosc, nrDomuTmp, nrTelefonuTmp;
			int nrDomu;
			long int nrTelefonu;

			string funkcja = "Nauczyciel";

			int wyborModyfikacja;
			string wyborModyfikacjaTmp;

			while (1) {

				system("CLS");

				cout << "\t\t\t\t--- EDYCJA NAUCZYCIELA ---" << endl;

				cout << endl << "Edytujesz nauczyciela: " << endl;
				cout << tablicaNauczycieli[id].id << " " << tablicaNauczycieli[id].login << " " << tablicaNauczycieli[id].haslo << " " << tablicaNauczycieli[id].imie << " " << tablicaNauczycieli[id].nazwisko << " " << tablicaNauczycieli[id].funkcja << " " << tablicaNauczycieli[id].nazwaPrzedmiotu << " " << tablicaNauczycieli[id].miejscowosc << " " << tablicaNauczycieli[id].nrDomu << " " << tablicaNauczycieli[id].nrTelefonu << endl;
				cout << endl << "Wybierz jedn¹ z poni¿szych opcji" << endl << endl;
				cout << "1. Edytuj login nauczyciela" << endl;
				cout << "2. Edytuj has³o nauczyciela" << endl;
				cout << "3. Edytuj imiê nauczyciela" << endl;
				cout << "4. Edytuj nazwisko nauczyciela" << endl;
				cout << "5. Edytuj przedmiot nauczyciela" << endl;
				cout << "6. Edytuj miejscowoœæ nauczyciela" << endl;
				cout << "7. Edytuj numer domu nauczyciela" << endl;
				cout << "8. Edytuj numer telefonu nauczyciela" << endl;
				cout << "9. Zakoñcz edycjê" << endl << endl;

				bool isError;

				cin >> wyborModyfikacjaTmp;
				for (size_t i = 0; i < wyborModyfikacjaTmp.length(); i++)
				{
					if (!(wyborModyfikacjaTmp[i] > 47 && wyborModyfikacjaTmp[i] < 58))
						isError = true;
					else
						isError = false;
				}
				if (isError == true) {
					idTeacherTypeError();
					Sleep(1500);
					system("CLS");
				}
				else {
					istringstream iss(wyborModyfikacjaTmp);
					iss >> wyborModyfikacja;

					switch (wyborModyfikacja) {

					case 1: {
								cout << endl << "Wpisz login nauczyciela:" << endl;
								cin >> login;
								tablicaNauczycieli[id].login = login;
								cout << endl << "Login pomyœlnie zaktualizowany.";
								Sleep(1500);
								break;
					}

					case 2: {
								cout << endl << "Wpisz has³o nauczyciela:" << endl;
								cin >> haslo;
								tablicaNauczycieli[id].haslo = haslo;
								cout << endl << "Has³o pomyœlnie zaktualizowane.";
								Sleep(1500);
								break;
					}

					case 3: {
								while (1) {
									cout << endl << "Wpisz imiê nauczyciela:" << endl;
									cin >> imie;
									for (size_t i = 0; i < imie.length(); i++)
									{
										if (!(imie[i] < 47 || imie[i] > 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										nameTypeError();
									}
									else {
										tablicaNauczycieli[id].imie = imie;
										cout << endl << "Imiê pomyœlnie zaktualizowane.";
										Sleep(1500);
										break;
									}
								}
								break;
					}

					case 4: {
								while (1) {
									cout << endl << "Wpisz nazwisko nauczyciela:" << endl;
									cin >> nazwisko;
									for (size_t i = 0; i < nazwisko.length(); i++)
									{
										if (!(nazwisko[i] < 47 || nazwisko[i] > 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										surnameTypeError();
									}
									else {
										tablicaNauczycieli[id].nazwisko = nazwisko;
										cout << endl << "Nazwisko pomyœlnie zaktualizowane.";
										Sleep(1500);
										break;
									}
								}
								break;
					}
					case 5: {
								while (1) {
									cout << endl << "Wpisz miejscowoœæ, w której mieszka nauczyciela:" << endl;
									cin >> miejscowosc;
									for (size_t i = 0; i < miejscowosc.length(); i++)
									{
										if (!(miejscowosc[i] < 47 || miejscowosc[i] > 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										cityTypeError();
									}
									else {
										tablicaNauczycieli[id].miejscowosc = miejscowosc;
										cout << endl << "Miejscowoœæ pomyœlnie zaktualizowana.";
										Sleep(1500);
										break;
									}
								}
								break;
					}
					case 6: {
								while (1) {
									cout << endl << "Wpisz numer domu, w którym mieszka nauczyciela:" << endl;
									cin >> nrDomuTmp;
									for (size_t i = 0; i < nrDomuTmp.length(); i++)
									{
										if (!(nrDomuTmp[i] > 47 && nrDomuTmp[i] < 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										houseNumberTypeError();
									}
									else {
										istringstream iss(nrDomuTmp);
										iss >> nrDomu;

										tablicaNauczycieli[id].nrDomu = nrDomu;
										cout << endl << "Numer domu pomyœlnie zaktualizowany.";
										Sleep(1500);
										break;
									}
								}
								break;
					}

					case 7: {
								while (1) {

									cout << endl << "Wpisz numer telefonu nauczyciela:" << endl;
									cin >> nrTelefonuTmp;

									for (size_t i = 0; i < nrTelefonuTmp.length(); i++)
									{
										if (!(nrTelefonuTmp[i] > 47 && nrTelefonuTmp[i] < 58))
											isError = true;
										else
											isError = false;
									}
									if (isError == true) {
										phoneNumberTypeError();
									}
									else {
										if (nrTelefonuTmp.length() < 9)
											cout << endl << "Numer telefonu jest za krótki. Musi siê sk³adaæ z 9 znakow" << endl;
										else if (nrTelefonuTmp.length() > 9)
											cout << endl << "Numer telefonu jest za d³ugi. Musi siê sk³adaæ z 9 znakow" << endl;
										else {
											istringstream iss(nrTelefonuTmp);
											iss >> nrTelefonu;

											tablicaNauczycieli[id].nrTelefonu = nrTelefonu;
											cout << endl << "Numer telefonu pomyœlnie zaktualizowany.";
											Sleep(1500);
											break;
										}
									}
								}
								break;
					}
					case 8: {
								zapiszUczniowDoPliku();
								system("CLS");
								return;
					}
					default: {
								 cout << "Nie ma takiej opcji. Spróbuj jeszcze raz";
								 Sleep(1500);
								 break;
					}
					}
				}
			}
		}
	}

}

int Dziennik::wczytajNauczycieliZPliku() { //wczytuje nauczycieli z pliku i zwraca id ostatniego
	tablicaNauczycieli.clear();
	ifstream data("dane-nauczycieli.txt");
	int id = 0;

	string login;
	string haslo;
	string imie;
	string nazwisko;
	string funkcja;
	string nazwaPrzedmiotu;
	string miejscowosc;
	int nrDomu;
	long int nrTelefonu;

	while (data >> id >> login >> haslo >> imie >> nazwisko >> funkcja >> nazwaPrzedmiotu >> miejscowosc >> nrDomu >> nrTelefonu) {
		Nauczyciel nowyNauczyciel(id, login, haslo, imie, nazwisko, funkcja, nazwaPrzedmiotu, miejscowosc, nrDomu, nrTelefonu);
		tablicaNauczycieli.push_back(nowyNauczyciel);
	}
	return id;
}

void Dziennik::wypiszWszystkichNauczycieli() {
	if (tablicaNauczycieli.size() == 0)
		cout << "Brak nauczycieli w bazie" << endl;
	for (auto i = tablicaNauczycieli.begin(); i != tablicaNauczycieli.end(); i++)
		(*i).wypisz();
}

void Dziennik::zapiszNauczycieliDoPliku() {
	sortujNauczycieli();
	ofstream f("dane-nauczycieli.txt");
	for (auto i = tablicaNauczycieli.begin(); i != tablicaNauczycieli.end(); ++i) {
		f << (*i).id << " " << (*i).login << " " << (*i).haslo << " " << (*i).imie << " " << (*i).nazwisko << " " << (*i).funkcja << " " << (*i).nazwaPrzedmiotu << " " << (*i).miejscowosc << " " << (*i).nrDomu << " " << (*i).nrTelefonu << '\n';
	}

}

void Dziennik::dodajOcene() {

	system("CLS");

	cout << "\t\t\t\t----- DODAWANIE OCEN -----" << endl << endl;

	wczytajUczniowZPliku();
	wczytajOcenyZPliku();
	wypiszWszystkichUczniow();

	cout << endl << "Nazwa przedmiotu: " << przedmiotNauczyciela << endl << endl;

	string idTmp;
	int id;
	bool isError;

	while (1) {
		cout << "Podaj numer z dziennika ucznia:" << endl;
		cin >> idTmp;
		for (size_t i = 0; i < idTmp.length(); i++)
		{
			if (!(idTmp[i] > 47 && idTmp[i] < 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			idTypeError();
			cout << endl;
		}
		else {
			istringstream iss(idTmp);
			iss >> id;

			auto i = tablicaUczniow.end();
			if (id < 0 || id >(*(i - 1)).id) {//mozna zamienic na try catcha
				cout << "Wpisano niepoprawny numer z dziennika." << endl << endl;
			}
			else{
				break;
			}
		}
	}


	string przedmiot;
	int wartosc;
	string typ;

	while (1) {
		cout << endl << "Podaj typ oceny (odpowiedz, kartkowka, sprawdzian, aktywnosc):" << endl;
		cin >> typ;
		if (typ != "odpowiedz" && typ != "kartkowka" && typ != "sprawdzian" && typ != "aktywnosc"){
			rateTypeError();
		}
		else
			break;
	}

	while (1) {
		string wartoscTmp;

		cout << endl << "Podaj uzyskan¹ przez ucznia ocene:" << endl;
		cin >> wartoscTmp;
		for (size_t i = 0; i < wartoscTmp.length(); i++)
		{
			if (!(idTmp[i] > 47 && idTmp[i] < 58))
				isError = true;
			else
				isError = false;
		}
		if (isError == true) {
			rateError();
			cout << endl;
		}
		else {
			istringstream iss(wartoscTmp);
			iss >> wartosc;
		}

		if (wartosc < 1 || wartosc > 6){
			rateError();
			cout << endl;
		}
		else
			break;
	}
	Ocena nowa(id, przedmiotNauczyciela, typ, wartosc);
	tablicaOcen.push_back(nowa);
	zapiszOcenyDoPliku();

	cout << endl << "Ocena zosta³a dodana pomyœlnie" << endl;
	Sleep(1500);
	system("CLS");
}

void Dziennik::zapiszOcenyDoPliku() {
	ofstream f("oceny-uczniow.txt");
	for (auto i = tablicaOcen.begin(); i != tablicaOcen.end(); ++i) {
		f << (*i).id << " " << (*i).przedmiot << " " << (*i).typ << " " << (*i).wartosc << '\n';
	}
}

void Dziennik::wczytajOcenyZPliku() {
	tablicaOcen.clear();
	ifstream data("oceny-uczniow.txt");
	int id;
	string typ;
	int wartosc;
	string przedmiot;
	while (data >> id >> przedmiot >> typ >> wartosc) {
		Ocena nowa(id, przedmiot, typ, wartosc);
		tablicaOcen.push_back(nowa);
	}
}

void Dziennik::sprawdzOceny() {
	system("CLS");
	cout << "\t\t\t\t--- SPRAWD OCENY ---" << endl << endl;

	wczytajOcenyZPliku();
	wczytajUczniowZPliku();
	wypiszWszystkichUczniow();

	cout << endl << "Szukaj wszystkich ocen z danego przedmiotu." << endl << endl;
	cout << "Podaj nazwê przedmiotu: " << endl;
	string nazwa;
	cin >> nazwa;
	bool czyZnalezionoPrzedmiot = false;
	for (auto i = tablicaOcen.begin(); i != tablicaOcen.end(); i++) {
		if ((*i).przedmiot == nazwa) {
			czyZnalezionoPrzedmiot = true;
			cout << endl << "Numer z dziennika ucznia: " << (*i).id << endl;
			cout << "Imie i nazwisko: " << tablicaUczniow[(*i).id - 1].imie << " " << tablicaUczniow[(*i).id - 1].nazwisko << endl;
			cout << "Przedmiot: " << (*i).przedmiot << endl;
			cout << "Ocena: " << (*i).wartosc << endl;
			cout << "Typ oceny: " << (*i).typ << endl;
		}
	}
	if (!czyZnalezionoPrzedmiot) {
		cout << endl << "Nie ma ocen z tego przedmiotu" << endl;
	}

	string backToMenu;

	while (1){
		cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
		cin >> backToMenu;

		if (backToMenu == "1"){
			system("CLS");
			break;
		}
	}
}

void Dziennik::sprawdzOcenyPrzedmiotu() {
	cout << "\t\t\t\t--- SPRAWD OCENY ---" << endl << endl;

	wczytajOcenyZPliku();
	wczytajUczniowZPliku();
	wypiszWszystkichUczniow();

	string nazwa = przedmiotNauczyciela;

	cout << endl << "Szukaj wszystkich ocen z przedmiotu: " << nazwa << endl;

	bool czyZnalezionoPrzedmiot = false;
	for (auto i = tablicaOcen.begin(); i != tablicaOcen.end(); i++) {
		if ((*i).przedmiot == nazwa) {
			czyZnalezionoPrzedmiot = true;
			cout << endl << "Numer z dziennika ucznia: " << (*i).id << endl;
			cout << "Imie i nazwisko: " << tablicaUczniow[(*i).id - 1].imie << " " << tablicaUczniow[(*i).id - 1].nazwisko << endl;
			cout << "Przedmiot: " << (*i).przedmiot << endl;
			cout << "Ocena: " << (*i).wartosc << endl;
			cout << "Typ oceny: " << (*i).typ << endl;
		}
	}
	if (!czyZnalezionoPrzedmiot) {
		cout << endl << "Nie ma takiego przedmiotu." << endl;
	}
	string backToMenu;

	while (1){
		cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
		cin >> backToMenu;

		if (backToMenu == "1"){
			system("CLS");
			break;
		}
	}
}

string space2underscore(string text) {
	for (string::iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}
	return text;
}

string underscore2space(string text) {
	for (string::iterator it = text.begin(); it != text.end(); ++it) {
		if (*it == '_') {
			*it = ' ';
		}
	}
	return text;
}

void Dziennik::dodajTemat(){
	system("CLS");

	int id = wczytajTematyZPliku() + 1;

	cout << "\t\t\t\t----- DODAWANIE TEMATU -----" << endl << endl;

	cout << "Nazwa przedmiotu: " << przedmiotNauczyciela << endl << endl;

	string temat;

	cout << "Wpisz temat lekcji:" << endl;
	cin.sync();
	getline(std::cin, temat);
	temat = space2underscore(temat);

	string data;

	while (1){
		cout << endl << "Wpisz datê lekcji w formacie (DD-MM-RRRR np. 20-01-2016):" << endl;
		cin >> data;
		if (data.length() < 10)
			cout << "Format daty jest za krótki" << endl;
		if (data.length() > 10)
			cout << "Format daty jest za d³ugi" << endl;
		if (!(data.length() == 10) || (data[2] != '-') || (data[5] != '-')){
			cout << "Z³y format daty." << endl;
		}
		if ((data.length() == 10) && (data[2] == '-') && (data[5] == '-')){
			break;
		}
	}

	Lekcja nowa(id, przedmiotNauczyciela, temat, data);
	tablicaLekcji.push_back(nowa);
	zapiszTematDoPliku();

	idLekcji++;
	cout << endl << "Temat zosta³ dodany pomyœlnie.";
	Sleep(1500);
	system("CLS");
}

void Dziennik::zapiszTematDoPliku() {
	ofstream f("tematy-lekcji.txt");
	for (auto i = tablicaLekcji.begin(); i != tablicaLekcji.end(); ++i) {
		f << (*i).id << " " << (*i).nazwaPrzedmiotu << " " << (*i).temat << " " << (*i).data << '\n';
	}
}

int Dziennik::wczytajTematyZPliku() {
	tablicaLekcji.clear();
	ifstream dane("tematy-lekcji.txt");
	int id = 0;
	string nazwaPrzedmiotu;
	string temat;
	string data;
	while (dane >> id >> nazwaPrzedmiotu >> temat >> data) {
		Lekcja nowa(id, nazwaPrzedmiotu, temat, data);
		tablicaLekcji.push_back(nowa);
	}
	return id;
}

void Dziennik::wypiszWszystkieTematyPrzedmiotu(){
	system("CLS");

	cout << "\t\t\t\t--- SPRAWD TEMATY LEKCJI ---" << endl << endl;

	wczytajTematyZPliku();

	string nazwa = przedmiotNauczyciela;

	cout << endl << "Szukaj tematów z przedmiotu: " << nazwa << endl;

	bool czyZnalezionoPrzedmiot = false;
	for (auto i = tablicaLekcji.begin(); i != tablicaLekcji.end(); i++) {
		if ((*i).nazwaPrzedmiotu == nazwa) {
			czyZnalezionoPrzedmiot = true;
			cout << endl << "Temat lekcji: " << underscore2space((*i).temat) << endl;
			cout << "Data: " << (*i).data << endl;
		}
	}
	if (!czyZnalezionoPrzedmiot) {
		cout << endl << "Nie ma takiego przedmiotu." << endl;
	}
	string backToMenu;

	while (1){
		cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
		cin >> backToMenu;

		if (backToMenu == "1"){
			system("CLS");
			break;
		}
	}
}


void Dziennik::sprawdzObecnosc(){
	system("CLS");

	int idLekcji = wczytajObecnosciZPliku() + 1;
	wczytajUczniowZPliku();
	wczytajTematyZPliku();

	cout << "\t\t\t\t----- SPRAWDZANIE OBECNOŒCI -----" << endl << endl;

	cout << "Nazwa przedmiotu: " << przedmiotNauczyciela << endl;

	string czyObecny;
	string nazwaPrzedmiotu = przedmiotNauczyciela;
	string data;

	data = tablicaLekcji[idLekcji-1].data;

	for (int i = 0; i < tablicaUczniow.size(); i++){
		cout << endl << "Czy " << tablicaUczniow[i].imie << " " <<  tablicaUczniow[i].nazwisko << " jest obecny/obecna? (t/n)" << endl; //"JEST... WPISZ   0 LUB 1
		int idUcznia = tablicaUczniow[i].id;
		while (1){
			cin >> czyObecny;
			if (czyObecny != "t" && czyObecny != "n"){
				cout << "Mo¿esz podaæ tylko t lub n" << endl << endl;
			}
			else
				break;
		}
		Obecnosc nowa(idUcznia, idLekcji, nazwaPrzedmiotu, data, czyObecny);
		tablicaObecnosci.push_back(nowa);
	}

	zapiszObecnosciDoPliku();

	idLekcji++;
	cout << endl << "Obecnoœæ sprawdzona i zapisana.";
	Sleep(1500);
	system("CLS");
}

void Dziennik::zapiszObecnosciDoPliku() {
	ofstream f("obecnosci.txt");
	for (auto i = tablicaObecnosci.begin(); i != tablicaObecnosci.end(); ++i) {
		f << (*i).idUcznia << " " << (*i).idLekcji << " " << (*i).nazwaPrzedmiotu << " " << (*i).data << " " << (*i).czyObecny << '\n';
	}
}

int Dziennik::wczytajObecnosciZPliku() {
	tablicaObecnosci.clear();
	ifstream dane("obecnosci.txt");
	int idUcznia;
	int idLekcji = 0;
	string czyObecny;
	string nazwaPrzedmiotu;
	string data;
	while (dane >> idUcznia >> idLekcji >> nazwaPrzedmiotu >> data >> czyObecny) {
		Obecnosc nowa(idUcznia, idLekcji, nazwaPrzedmiotu, data, czyObecny);
		tablicaObecnosci.push_back(nowa);
	}
	return idLekcji;
}

void Dziennik::sprawdzNieobecnosci(){
	system("CLS");
	cout << "\t\t\t\t--- SPRAWD NIEOBECNOŒCI ---" << endl << endl;

	wczytajObecnosciZPliku();
	wczytajUczniowZPliku();
	wypiszWszystkichUczniow();

	cout << endl << "Szukaj wszystkich nieobecnoœci danego ucznia." << endl << endl;
	cout << "Podaj numer z dziennika ucznia: " << endl;
	int id;
	cin >> id;
	bool czyZnalezionoPrzedmiot = false;
	for (auto i = tablicaObecnosci.begin(); i != tablicaObecnosci.end(); i++) {
		if ((*i).idUcznia == id && (*i).czyObecny == "n") {
			czyZnalezionoPrzedmiot = true;
			cout << endl << "Numer z dziennika ucznia: " << (*i).idUcznia << endl;
			cout << "Imie i nazwisko: " << tablicaUczniow[(*i).idUcznia - 1].imie << " " << tablicaUczniow[(*i).idUcznia - 1].nazwisko << endl;
			cout << "Przedmiot: " << (*i).nazwaPrzedmiotu << endl;
			cout << "Data: " << (*i).data << endl;
		}
	}
	if (!czyZnalezionoPrzedmiot) {
		cout << endl << "Uczen nie opuœci³ ¿adnej lekcji." << endl;
	}

	string backToMenu;

	while (1){
		cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
		cin >> backToMenu;

		if (backToMenu == "1"){
			system("CLS");
			break;
		}
	}
}

//menu
void Dziennik::menu() {


	wczytajNauczycieliZPliku();

	cout << "\t\t\t\t----- DZIENNIK ELEKTRONICZNY -----" << endl << endl;

	string userLogin;
	string userPassword;
	int ilegwiazdek = 0;
	cout << "Podaj login: ";
	cin >> userLogin;
	cout << "Podaj has³o: ";
	userPassword = "";
	char ch;
	ch = _getch();
	while (ch != 13) {
		if (ch == 8) {
			if (ilegwiazdek == 0) {
				ch = _getch();
			}
			else {
				ilegwiazdek--;
				userPassword.pop_back();
				system("CLS");
				cout << "\t\t\t\t----- DZIENNIK ELEKTRONICZNY -----" << endl << endl;
				cout << "Podaj login: " << userLogin << endl;
				cout << "Podaj has³o: ";
				for (int i = 0; i < ilegwiazdek; i++)
					cout << "*";
			}
		}
		else {
			ilegwiazdek++;
			userPassword.push_back(ch);
			cout << '*';
		}
		ch = _getch();
	}



	int wyborMenu = 4;
	int wybor;
	string wyborTmp;

	string userImie;
	string userNazwisko;
	string userFunkcja;

	unsigned int size = tablicaNauczycieli.size();

	for (unsigned int i = 0; i < size; i++) {

		if (userLogin == "dyrektor") {
			if (userLogin == tablicaNauczycieli[i].getLogin() && userPassword == tablicaNauczycieli[i].getHaslo()) {
				wyborMenu = 1;

				userImie = tablicaNauczycieli[i].getImie();
				userNazwisko = tablicaNauczycieli[i].getNazwisko();
				userFunkcja = tablicaNauczycieli[i].getFunkcja();

				cout << endl << "\t\t\t\t\t--- TRWA LOGOWANIE ---" << endl;
				Sleep(1000);
				system("CLS");
				break;
			}
			else if (userLogin == tablicaNauczycieli[i].getLogin() && userPassword != tablicaNauczycieli[i].getHaslo()) {
				wyborMenu = 4;
				break;
			}
		}

		else if (userLogin == "wychowawca") {
			if (userLogin == tablicaNauczycieli[i].getLogin() && userPassword == tablicaNauczycieli[i].getHaslo()) {
				wyborMenu = 2;

				userImie = tablicaNauczycieli[i].getImie();
				userNazwisko = tablicaNauczycieli[i].getNazwisko();
				userFunkcja = tablicaNauczycieli[i].getFunkcja();

				cout << endl << "\t\t\t\t\t--- TRWA LOGOWANIE ---" << endl;
				Sleep(1000);
				system("CLS");
				break;
			}
			else if (userLogin == tablicaNauczycieli[i].getLogin() && userPassword != tablicaNauczycieli[i].getHaslo()) {
				wyborMenu = 4;
				break;
			}
		}
		else if (userLogin != "wychowawca" && userLogin != "dyrektor") {
			if (userLogin == tablicaNauczycieli[i].getLogin() && userPassword == tablicaNauczycieli[i].getHaslo()) {
				wyborMenu = 3;
				userImie = tablicaNauczycieli[i].getImie();
				userNazwisko = tablicaNauczycieli[i].getNazwisko();
				userFunkcja = tablicaNauczycieli[i].getFunkcja();
				przedmiotNauczyciela = tablicaNauczycieli[i].getPrzedmiot();
				cout << endl << "\t\t\t\t\t--- TRWA LOGOWANIE ---" << endl;
				Sleep(1000);
				system("CLS");
				break;
			}
			/*	else {
					wyborMenu = 4;
					break;
					}*/
		}


	}

	switch (wyborMenu) {

	case 1:
	{
			  while (1) {

				  //system("CLS");

				  cout << "\t\t\t\t----- DZIENNIK ELEKTRONICZNY -----" << endl << endl;
				  cout << "Zalogowany jako: " << userImie << " " << userNazwisko << " - " << userFunkcja << endl;

				  //dyrektor
				  cout << "Podaj opcjê, któr¹ chcesz wybraæ." << endl << endl;
				  cout << "1. DANE UCZNIÓW" << endl;
				  cout << "2. DANE NAUCZYCIELI" << endl;
				  cout << "3. DODAJ NAUCZYCIELA" << endl;
				  cout << "4. USUÑ NAUCZYCIELA" << endl;
				  cout << "5. EDYTUJ NAUCZYCIELA" << endl;
				  cout << "6. WYLOGUJ" << endl << endl;

				  bool isError;

				  cin >> wyborTmp;

				  if (wyborTmp != "1" && wyborTmp != "2" && wyborTmp != "3" && wyborTmp != "4" && wyborTmp != "5" && wyborTmp != "6")
					  isError = true;
				  else
					  isError = false;

				  if (isError == true) {
					  menuChoiceError();
					  Sleep(1500);
					  system("CLS");
				  }
				  else{

					  istringstream iss(wyborTmp);
					  iss >> wybor;

					  switch (wybor) {

						  //dane uczniow
					  case 1:
					  {
								system("CLS");
								cout << "\t\t\t\t----- DANE UCZNIÓW -----" << endl << endl;
								wczytajUczniowZPliku();
								wypiszWszystkichUczniow();

								string backToMenu;

								while (1){
									cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
									cin >> backToMenu;

									if (backToMenu == "1"){
										system("CLS");
										break;
									}
								}


					  }
						  break;


						  //dane uczniów
					  case 2:
					  {
								system("CLS");
								cout << "\t\t\t\t----- DANE NAUCZYCIELI -----" << endl << endl;
								wczytajNauczycieliZPliku();
								wypiszWszystkichNauczycieli();

								string backToMenu;

								while (1){
									cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
									cin >> backToMenu;

									if (backToMenu == "1"){
										system("CLS");
										break;
									}
								}
					  }
						  break;

						  //dodaj nauczyciela
					  case 3:
					  {
								dodajNauczyciela();
					  }
						  break;

						  //usun nauczyciela
					  case 4:
					  {
								usunNauczyciela();
					  }
						  break;

						  //edytuj nauczyciela
					  case 5:
					  {
								edytujNauczyciela();
					  }
						  break;

						  //wyjœcie z dziennika
					  case 6:
					  {
								cout << endl << "CZY NA PEWNO CHCESZ SIÊ WYLOGOWAÆ? (t/n)" << endl;

								char wyborWyjscie;
								cin >> wyborWyjscie;

								if (wyborWyjscie == 't'){
									exit(1);
								}
								else
									system("CLS");
					  }
						  break;

						  //inna opcja
					  default:
					  {
								 cout << "Nie ma takiej opcji. Wybierz inny numer";
								 Sleep(1000);
								 system("CLS");
					  }
						  break;

					  }
				  }
			  }
	}
		break;


	case 2:
	{
			  while (1) {
				  cout << "\t\t\t\t----- DZIENNIK ELEKTRONICZNY -----" << endl << endl;
				  cout << "Zalogowany jako: " << userImie << " " << userNazwisko << " - " << userFunkcja << endl;

				  //wychowawca
				  cout << "Podaj opcjê, któr¹ chcesz wybraæ." << endl << endl;
				  cout << "1. SPRAWD NIEOBECNOŒCI" << endl;
				  cout << "2. DANE UCZNIÓW" << endl;
				  cout << "3. SPRAWD OCENY" << endl;
				  cout << "4. DODAJ UCZNIA" << endl;
				  cout << "5. USUÑ UCZNIA" << endl;
				  cout << "6. USUÑ WSZYSTKICH UCZNIÓW" << endl;
				  cout << "7. EDYTUJ UCZNIA" << endl;
				  cout << "8. WYJŒCIE Z DZIENNIKA" << endl << endl;

				  bool isError;

				  cin >> wyborTmp;

				  if (wyborTmp != "1" && wyborTmp != "2" && wyborTmp != "3" && wyborTmp != "4" && wyborTmp != "5" && wyborTmp != "6" && wyborTmp != "7" && wyborTmp != "8")
					  isError = true;
				  else
					  isError = false;

				  if (isError == true) {
					  menuChoiceError();
					  Sleep(1500);
					  system("CLS");
				  }
				  else{

					  istringstream iss(wyborTmp);
					  iss >> wybor;

					  switch (wybor) {

						  //sprawdŸ nieobecnoœci
					  case 1:
					  {
								sprawdzNieobecnosci();
					  }
						  break;

						  //dane uczniów
					  case 2:
					  {
								system("CLS");
								cout << "\t\t\t\t----- DANE UCZNIÓW -----" << endl << endl;
								wczytajUczniowZPliku();
								wypiszWszystkichUczniow();

								string backToMenu;

								while (1){
									cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
									cin >> backToMenu;

									if (backToMenu == "1"){
										system("CLS");
										break;
									}
								}
					  }
						  break;

						  //sprawdŸ oceny
					  case 3:
					  {
								sprawdzOceny();
					  }
						  break;

						  //dodaj ucznia
					  case 4:
					  {
								dodajUcznia();
					  }
						  break;

						  //usuñ ucznia
					  case 5:
					  {
								usunUcznia();
					  }
						  break;

						  //usuñ wszystkich uczniów
					  case 6:
					  {
								usunWszystkichUczniow();
					  }
						  break;

						  //edytuj ucznia
					  case 7:
					  {
								edytujUcznia();
					  }
						  break;

						  //wyjœcie z dziennika
					  case 8:
					  {
								cout << endl << "CZY NA PEWNO CHCESZ SIÊ WYLOGOWAÆ? (t/n)" << endl;

								char wyborWyjscie;
								cin >> wyborWyjscie;

								if (wyborWyjscie == 't'){
									exit(1);
								}
								else
									system("CLS");
					  }
						  break;

						  //inna opcja
					  default:
					  {
								 cout << "Nie ma takiej opcji. Wybierz inny numer";
								 Sleep(1000);
								 system("CLS");
					  }
						  break;
					  }
				  }
			  }
	}
		break;

	case 3:
	{
			  while (1) {
				  cout << "\t\t\t\t----- DZIENNIK ELEKTRONICZNY -----" << endl << endl;
				  cout << "Zalogowany jako: " << userImie << " " << userNazwisko << " - " << userFunkcja << endl;

				  //nauczyciel
				  cout << "Podaj opcjê, któr¹ chcesz wybraæ." << endl << endl;
				  cout << "1. WPISZ TEMAT LEKCJI" << endl;
				  cout << "2. SPRAWD OBECNOŒÆ" << endl;
				  cout << "3. SPRAWD OCENY" << endl;
				  cout << "4. WPISZ OCENÊ" << endl;
				  cout << "5. POKA¯ WSZYSTKIE TEMATY LEKCJI" << endl;
				  cout << "6. ŒREDNIE UCZNIÓW Z TEGO PRZEDMIOTU" << endl;
				  cout << "7. DANE UCZNIÓW" << endl;
				  cout << "8. WYJŒCIE Z DZIENNIKA" << endl << endl;

				  bool isError;

				  cin >> wyborTmp;

				  if (wyborTmp != "1" && wyborTmp != "2" && wyborTmp != "3" && wyborTmp != "4" && wyborTmp != "5" && wyborTmp != "6" && wyborTmp != "7" && wyborTmp != "8")
					  isError = true;
				  else
					  isError = false;

				  if (isError == true) {
					  menuChoiceError();
					  Sleep(1500);
					  system("CLS");
				  }
				  else{

					  istringstream iss(wyborTmp);
					  iss >> wybor;

					  switch (wybor) {

						  //wpisz temat lekcji
					  case 1:
					  {
								dodajTemat();
					  }
						  break;

						  //sprawd¿ obecnoœæ
					  case 2:
					  {
								sprawdzObecnosc();
					  }
						  break;

					  case 3:
					  {
								sprawdzOcenyPrzedmiotu();
					  }
						  break;

						  //wpisz ocenê
					  case 4:
					  {
								dodajOcene();
					  }
						  break;

						  //wpisz ocenê
					  case 5:
					  {
								wypiszWszystkieTematyPrzedmiotu();
					  }
						  break;

						  //srednie uczniow
					  case 6:
					  {
								wypiszWszystkieTematyPrzedmiotu();
					  }
					  break;

						  //dane uczniów
					  case 7:
					  {
								system("CLS");
								cout << "\t\t\t\t----- DANE UCZNIÓW -----" << endl << endl;
								wczytajUczniowZPliku();
								wypiszWszystkichUczniow();

								string backToMenu;

								while (1){
									cout << endl << "¯eby wróciæ do menu wprowadŸ 1" << endl;
									cin >> backToMenu;

									if (backToMenu == "1"){
										system("CLS");
										break;
									}
								}
					  }
						  break;

						  //wyjœcie z dziennika
					  case 8:
					  {
								cout << endl << "CZY NA PEWNO CHCESZ SIÊ WYLOGOWAÆ? (t/n)" << endl;

								char wyborWyjscie;
								cin >> wyborWyjscie;

								if (wyborWyjscie == 't'){
									exit(1);
								}
								else
									system("CLS");
					  }
						  break;

						  //inna opcja
					  default:
					  {
								 cout << "Nie ma takiej opcji. Wybierz inny numer";
								 Sleep(1000);
								 system("CLS");
					  }
						  break;
					  }
				  }

			  }
	}
		break;

	case 4:
	{
			  cout << endl << endl << "B£ÊDNE DANE LOGOWANIA!" << endl;
			  Sleep(1500);
			  system("CLS");
	}
		break;



	}

}