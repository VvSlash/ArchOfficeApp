#ifndef ZARZAD_H
#define ZARZAD_H
#include <string>
#include "Uzytkownik.h"
#include "Projekt.h"
class Zarzad : public Uzytkownik {

private:
	std::string nazwa;
	double przychody;
	double wydatki;
	bool zalogowany;
public:
	Zarzad(const std::string& username, const std::string& password, const std::string& email, int age)
		: Uzytkownik(username, password, email, age) {}

	void edytujProjekt(Projekt& projekt, const std::string& nowaNazwa, const std::string& nowyOpis) {
		projekt.setNazwa(nowaNazwa);
		projekt.setOpis(nowyOpis);
		std::cout << "Projekt zosta³ zaktualizowany." << std::endl;
	}

	void dodajPrzychod(double kwota) {
		przychody += kwota;
		std::cout << "Dodano przychód w wysokoœci: " << kwota << std::endl;
	}

	void dodajWydatek(double kwota) {
		wydatki += kwota;
		std::cout << "Dodano wydatek w wysokoœci: " << kwota << std::endl;
	}

	double obliczZysk() const {
		return przychody - wydatki;
	}

	double obliczPrzychody() const {
		return przychody;
	}

	double obliczWydatki() const {
		return wydatki;
	}


	void zaloguj();

	bool sprawdzPoprawnoscDanych(const std::string& login, const std::string& haslo);

	void wyloguj();

	void edytuj();
};

#endif
