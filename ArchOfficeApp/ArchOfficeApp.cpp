// ArchOfficeApp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include <fstream>
#include "time.h"
#include "Finanse.h"
#include "GlownyProjektant.h"
#include "Karta.h"
#include "Klient.h"
#include "Koordynator.h"
#include "Platnosc.h"
#include "Przelew.h"
#include "Temat.h"
#include "Zarzad.h"
#include <vector>
#include "BiuroArchitektoniczne.h"

struct UserRecord {
    std::string username;
    std::string password;
    std::string email;
    int age;
    bool isAdmin;
};

int main()
{
    std::vector<Projekt> projekty;

    GlownyProjektant projektant("projektant1", "haslo1", "projektant1@example.com", 40);
    Koordynator koordynator("koordynator1", "haslo2", "koordynator1@example.com", 35);
    Klient klient("klient1", "haslo3", "klient1@example.com", 30);

    klient.wyslijNowyProjekt("Projekt 1", "Opis projektu 1", 5000.0, projekty);

    if (projekty.size() > 0) {
        projektant.zatwierdzProjekt(projekty[0]);
        koordynator.zmienStatusProjektu(projekty[0], "W realizacji");
        projektant.edytujProjekt(projekty[0], "Projekt 1 (zmieniony)", "Zmieniony opis projektu 1");

        projektant.dodajPrzychod(projekty[0].getCena() * 0.8);
        projektant.dodajWydatek(projekty[0].getCena() * 0.3);

        BiuroArchitektoniczne biuro(1000.0);
        biuro.dodajKoszt(500.0);

        double przychody = projektant.obliczPrzychody();
        double wydatki = projektant.obliczWydatki();

        std::cout << "Zysk: " << biuro.obliczZysk(przychody, wydatki) << std::endl;
    }

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
