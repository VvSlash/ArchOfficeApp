#pragma once
#include <iostream>
class BiuroArchitektoniczne {
private:
    double kosztyProwadzenia;

public:
    BiuroArchitektoniczne(double kosztyProwadzenia)
        : kosztyProwadzenia(kosztyProwadzenia) {}

    void dodajKoszt(double kwota) {
        kosztyProwadzenia += kwota;
        std::cout << "Dodano koszt w wysoko�ci: " << kwota << std::endl;
    }

    double obliczZysk(double przychody, double wydatki) const {
        return przychody - wydatki - kosztyProwadzenia;
    }
};

