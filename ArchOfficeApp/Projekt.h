#pragma once
#include <iostream>
#include <string>
class Projekt
{
private:
    std::string nazwa;
    std::string opis;
    std::string status;
    double cena;

public:
    Projekt(const std::string& nazwa, const std::string& opis, double cena)
        : nazwa(nazwa), opis(opis), status("W trakcie"), cena(cena) {}

    std::string getNazwa() const {
        return nazwa;
    }

    std::string getOpis() const {
        return opis;
    }

    std::string getStatus() const {
        return status;
    }

    double getCena() const {
        return cena;
    }

    void setStatus(const std::string& nowyStatus) {
        status = nowyStatus;
    }

    void setNazwa(const std::string& nowaNazwa) {
        nazwa = nowaNazwa;
    }

    void setOpis(const std::string& nowyOpis) {
        opis = nowyOpis;
    }

};

