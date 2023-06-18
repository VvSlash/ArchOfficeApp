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
	Klient(const std::string& username, const std::string& password, const std::string& email, int age)
		: Uzytkownik(username, password, email, age) {}

	void wyslijNowyProjekt(const std::string& nazwa, const std::string& opis, double cena, std::vector<Projekt>& projekty) {
		projekty.push_back(Projekt(nazwa, opis, cena));
		std::cout << "Nowy projekt zosta³ wys³any." << std::endl;
	}
	Klient();

	void zaloguj();

	void wyloguj();

	void edytuj();
};

#endif
