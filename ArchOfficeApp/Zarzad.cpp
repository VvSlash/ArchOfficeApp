#include "Zarzad.h"
#include <iostream>

void Zarzad::zaloguj() {
    std::string login;
    std::string haslo;

    std::cout << "Podaj login: ";
    std::cin >> login;

    std::cout << "Podaj haslo: ";
    std::cin >> haslo;

    // SprawdŸ poprawnoœæ loginu i has³a oraz wykonaj logowanie.
    if (sprawdzPoprawnoscDanych(login, haslo)) {
        std::cout << "Logowanie udane. Witaj, " << nazwa << "!" << std::endl;
    }
    else {
        std::cout << "B³¹d logowania. SprawdŸ login i has³o." << std::endl;
    }
}

bool Zarzad::sprawdzPoprawnoscDanych(const std::string& login, const std::string& haslo) {
    // Tutaj mo¿na dodaæ kod sprawdzaj¹cy poprawnoœæ danych logowania, np. porównuj¹cy zapisane dane z przekazanymi danymi.
    // Przyk³adowo, mo¿na utworzyæ prost¹ logikê, która zwraca true tylko wtedy, gdy login to "admin" i has³o to "admin123":
    if (login == "admin" && haslo == "admin") {
        return true;
    }
    else {
        return false;
    }
}

void Zarzad::wyloguj() {
    // Wykonaj niezbêdne operacje zwi¹zane z wylogowaniem u¿ytkownika.

    zalogowany = false;  // Ustaw status u¿ytkownika na wylogowany (false).

    std::cout << "U¿ytkownik zosta³ wylogowany." << std::endl;
}

void Zarzad::edytuj() {
	// TODO - implement Zarzad::edytuj
	throw "Not yet implemented";
}
