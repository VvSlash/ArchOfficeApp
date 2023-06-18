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
public:
	Zarzad(const std::string& username, const std::string& password, const std::string& email)
		: Uzytkownik(username, password, email) {}

	void edytujProjekt(Projekt& projekt, const std::string& nowaNazwa, const std::string& nowyOpis) {
		if (zalogowany) {
			projekt.setNazwa(nowaNazwa);
			projekt.setOpis(nowyOpis);
			std::cout << "Projekt zosta³ zaktualizowany." << std::endl;
		}
		else {
			std::cout << "B³¹d: U¿ytkownik nie jest zalogowany." << std::endl;
		}
	}
	void zmienStatusProjektu(Projekt& projekt, const std::string& nowyStatus) {
		projekt.setStatus(nowyStatus);
		std::cout << "Status projektu zosta³ zmieniony." << std::endl;
	}
	void zmienPriorytetProjektu(Projekt& projekt, const std::string& nowyPriorytet) {
		projekt.setPriorytet(nowyPriorytet);
		std::cout << "Priorytet projektu zosta³ zmieniony." << std::endl;
	}
	double getPrzychody() const {
		return przychody;
	}

	double getWydatki() const {
		return wydatki;
	}
	void setPrzychody(const double& P) {
		przychody = P;
	}

	double setWydatki(const double& W) {
		wydatki = W;
	}
	void generujZestawienie() {

	}

	void edytuj();
};

#endif
