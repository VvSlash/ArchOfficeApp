#pragma once
#include <iostream>
#include <string>
class Uzytkownik
{
protected:
    bool zalogowany;
    std::string username;
    std::string password;
    std::string email;

public:
    bool czyZalogowany() const {
        return zalogowany;
    }
    Uzytkownik(const std::string& username, const std::string& password, const std::string& email)
        : username(username), password(password), email(email), zalogowany(false) {}

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }

    std::string getEmail() const {
        return email;
    }

    void zaloguj(std::string login, std::string haslo) {
        //std::string login;
        //std::string haslo;

        //std::cout << "Podaj login: ";
        //std::cin >> login;

        //std::cout << "Podaj haslo: ";
        //std::cin >> haslo;

        // SprawdŸ poprawnoœæ loginu i has³a oraz wykonaj logowanie.
        if (sprawdzPoprawnoscDanych(login, haslo)) {
            zalogowany = true;
            std::cout << "Logowanie udane. Witaj, " << username << "!" << std::endl;
        }
        else {
            zalogowany = false;
            std::cout << "B³¹d logowania. SprawdŸ login i has³o." << std::endl;
        }
    }

    bool sprawdzPoprawnoscDanych(const std::string& login, const std::string& haslo) {
        // Tutaj mo¿na dodaæ kod sprawdzaj¹cy poprawnoœæ danych logowania, np. porównuj¹cy zapisane dane z przekazanymi danymi.
        // Przyk³adowo, mo¿na utworzyæ prost¹ logikê, która zwraca true tylko wtedy, gdy login to "admin" i has³o to "admin123":
        if (login == this->username && haslo == this->password) {
            return true;
        }
        else {
            return false;
        }
    }

    void wyloguj() {
        // Wykonaj niezbêdne operacje zwi¹zane z wylogowaniem u¿ytkownika.

        zalogowany = false;  // Ustaw status u¿ytkownika na wylogowany (false).

        std::cout << "U¿ytkownik zosta³ wylogowany." << std::endl;
    }
};

