#ifndef GLOWNYPROJEKTANT_H
#define GLOWNYPROJEKTANT_H
#include "Zarzad.h"
class GlownyProjektant : public Zarzad {
	//cpos

public:
    GlownyProjektant(const std::string& username, const std::string& password, const std::string& email, int age)
        : Zarzad(username, password, email, age) {}

    void zatwierdzProjekt(Projekt& projekt) {
        projekt.setStatus("Zatwierdzony");
        std::cout << "Projekt zosta� zatwierdzony." << std::endl;
    }
	void Zatwierdza();
};

#endif
