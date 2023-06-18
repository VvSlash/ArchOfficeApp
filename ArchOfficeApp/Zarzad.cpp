#include "Zarzad.h"
#include <iostream>

void Zarzad::zaloguj() {
    std::string login;
    std::string haslo;

    std::cout << "Podaj login: ";
    std::cin >> login;

    std::cout << "Podaj haslo: ";
    std::cin >> haslo;

    // Sprawd� poprawno�� loginu i has�a oraz wykonaj logowanie.
    if (sprawdzPoprawnoscDanych(login, haslo)) {
        std::cout << "Logowanie udane. Witaj, " << nazwa << "!" << std::endl;
    }
    else {
        std::cout << "B��d logowania. Sprawd� login i has�o." << std::endl;
    }
}

bool Zarzad::sprawdzPoprawnoscDanych(const std::string& login, const std::string& haslo) {
    // Tutaj mo�na doda� kod sprawdzaj�cy poprawno�� danych logowania, np. por�wnuj�cy zapisane dane z przekazanymi danymi.
    // Przyk�adowo, mo�na utworzy� prost� logik�, kt�ra zwraca true tylko wtedy, gdy login to "admin" i has�o to "admin123":
    if (login == "admin" && haslo == "admin") {
        return true;
    }
    else {
        return false;
    }
}

void Zarzad::wyloguj() {
    // Wykonaj niezb�dne operacje zwi�zane z wylogowaniem u�ytkownika.

    zalogowany = false;  // Ustaw status u�ytkownika na wylogowany (false).

    std::cout << "U�ytkownik zosta� wylogowany." << std::endl;
}

void Zarzad::edytuj() {
	// TODO - implement Zarzad::edytuj
	throw "Not yet implemented";
}
