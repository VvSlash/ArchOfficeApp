#ifndef KOORDYNATOR_H
#define KOORDYNATOR_H
#include "Zarzad.h"
class Koordynator : public Zarzad {


public:
    Koordynator(const std::string& username, const std::string& password, const std::string& email, int age)
        : Zarzad(username, password, email, age) {}

    void zmienStatusProjektu(Projekt& projekt, const std::string& nowyStatus) {
        projekt.setStatus(nowyStatus);
        std::cout << "Status projektu zosta³ zmieniony." << std::endl;
    }
	void PrzypisujeZadania();
};

#endif
