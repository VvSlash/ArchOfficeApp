#ifndef KOORDYNATOR_H
#define KOORDYNATOR_H
#include "Zarzad.h"
class Koordynator : public Zarzad {

public:
    Koordynator(const std::string& username, const std::string& password, const std::string& email)
        : Zarzad(username, password, email) {}

    

	void dodajPrzychod(double kwota) {
		if (zalogowany) {
			double przychody = this->getPrzychody();
			przychody += kwota;
			this->setPrzychody(przychody);
			std::cout << "Dodano przychód w wysokoœci: " << kwota << std::endl;
		}
		else {
			std::cout << "B³¹d: U¿ytkownik nie jest zalogowany." << std::endl;
		}
	}

	void dodajWydatek(double kwota) {
		if (zalogowany) {
			double wydatki = this->getWydatki();
			wydatki += kwota;
			this->setWydatki(wydatki);
			std::cout << "Dodano wydatek w wysokoœci: " << kwota << std::endl;
		}
		else {
			std::cout << "B³¹d: U¿ytkownik nie jest zalogowany." << std::endl;
		}
	}

	double obliczZysk() const {
		if (zalogowany) {
			return this->getPrzychody() - this->getWydatki();
		}
		else {
			std::cout << "B³¹d: U¿ytkownik nie jest zalogowany." << std::endl;
		}
	}

	double obliczPrzychody() const {
		if (zalogowany) {
			return this->getPrzychody();
		}
		else {
			std::cout << "B³¹d: U¿ytkownik nie jest zalogowany." << std::endl;
		}
	}

	double obliczWydatki() const {
		if (zalogowany) {
			return this->getWydatki();
		}
		else {
			std::cout << "B³¹d: U¿ytkownik nie jest zalogowany." << std::endl;
		}
	}
	void PrzypisujeZadania();
};

#endif
