#ifndef GLOWNYPROJEKTANT_H
#define GLOWNYPROJEKTANT_H
#include "Zarzad.h"
class GlownyProjektant : public Zarzad {
	//cpos

public:
    GlownyProjektant(const std::string& username, const std::string& password, const std::string& email)
        : Zarzad(username, password, email) {}

    void zatwierdzProjekt(Projekt& projekt) {
        projekt.setStatus("Zatwierdzony");
        std::cout << "Projekt zosta³ zatwierdzony." << std::endl;
    }
	void Zatwierdza();
};

#endif
