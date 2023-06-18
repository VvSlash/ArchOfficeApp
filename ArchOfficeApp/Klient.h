#ifndef KLIENT_H
#define KLIENT_H
#include <string>
class Klient {

private:
	std::string imie;
	std::string nazwisko;
	int id;
	std::string email;
	int telefon;

public:
	Klient();

	void zaloguj();

	void wyloguj();

	void edytuj();
};

#endif
