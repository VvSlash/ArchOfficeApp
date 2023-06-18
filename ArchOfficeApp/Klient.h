#ifndef KLIENT_H
#define KLIENT_H
#include <string>
#include "Uzytkownik.h"
#include "Projekt.h"
#include <vector>
#include "Projekt.h"
class Klient : public Uzytkownik {

private:
	std::string imie;
	std::string nazwisko;
	int id;
	std::string email;
	int telefon;

public:
	Klient(const std::string& username, const std::string& password, const std::string& email)
		: Uzytkownik(username, password, email) {}

	void wyslijNowyProjekt(const std::string& nazwa, const std::string& opis, double cena, std::vector<Projekt>& projekty) {
		projekty.push_back(Projekt(nazwa, opis, cena));
		std::cout << "Nowy projekt zosta³ wys³any." << std::endl;
	}
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
	Klient();

	void edytuj();
};

#endif
