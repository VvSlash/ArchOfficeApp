#ifndef KARTA_H
#define KARTA_H
#include "Platnosc.h"
#include <string>
class Karta : Platnosc {

public:
	std::string wlasciciel;

	void pobierz();

	Karta();
};

#endif
