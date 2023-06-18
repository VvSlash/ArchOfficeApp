#ifndef PLATNOSC_H
#define PLATNOSC_H
#include <ctime>
class Platnosc {

private:
	tm dataplatnosci;
	double wartosc;

public:
	Platnosc();

	void realizuj();

	void sprawdz();

	void potwierdz();
};

#endif
