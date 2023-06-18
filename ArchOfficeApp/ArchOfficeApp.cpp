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

int main()
{
	//Baza projektów
	std::vector<Projekt> projekty;
	std::vector<Klient> klienci;
	std::vector<Koordynator> koordynatorzy;
	//Rejestracja użytkowników 
	GlownyProjektant projektant("projektant1", "p1", "projektant1@example.com");
	Koordynator koordynator("koordynator1", "k1", "koordynator1@example.com");
	Klient klient1("klient1", "haslo1", "klient1@example.com");
	Klient klient2("klient2", "haslo2", "klient2@example.com");
	Klient klient3("klient3", "haslo3", "klient3@example.com");
	klienci.push_back(klient1);
	klienci.push_back(klient2);
	klienci.push_back(klient3);
	koordynatorzy.push_back(koordynator);
	//Logowanie użytkowników
	int wybor;
	int wybor1;
	int wybor2;

	do {
		std::cout << "============================" << std::endl;
		std::cout << "1. Zaloguj jako klient" << std::endl;
		std::cout << "2. Zaloguj jako projektant" << std::endl;
		std::cout << "3. Zaloguj jako koordynator" << std::endl;
		std::cout << "0. Wyjdź" << std::endl;
		std::cout << "============================" << std::endl;
		std::cout << "Wybierz opcję: ";
		std::cin >> wybor;

		switch (wybor) {
		case 1: {
			std::string login;
			std::string haslo;

			std::cout << "Podaj login: ";
			std::cin >> login;

			std::cout << "Podaj haslo: ";
			std::cin >> haslo;
			for (Klient& klient : klienci)
			{
				klient.zaloguj(login, haslo);
				if (klient.czyZalogowany())
				{
					do {
						std::cout << "============================" << std::endl;
						std::cout << "1. Złóż zamówienie" << std::endl;
						std::cout << "2. Wyświetl projekty" << std::endl;
						std::cout << "0. Wyloguj" << std::endl;
						std::cout << "============================" << std::endl;
						std::cout << "Wybierz opcję: ";
						std::cin >> wybor1;
						switch (wybor1) {
						case 1: {
							std::cout << "=== Złożenie zamówienia ===" << std::endl;
							std::string nazwa, opis;
							double cena;

							std::cin.ignore();

							std::cout << "Podaj nazwę projektu: ";
							std::getline(std::cin, nazwa);
							std::cout << "Podaj opis projektu: ";
							std::getline(std::cin, opis);
							std::cout << "Podaj cenę projektu: ";
							std::cin >> cena;

							klient.wyslijNowyProjekt(nazwa, opis, cena, projekty);
							break;
						}
						case 2: {
							int i = 1;
							std::cout << "=== Wyświetlenie projektów ===" << std::endl;
							if (!projekty.empty()) {
								for (Projekt& projekt : projekty) {
									std::cout << "ID projektu: " << i << std::endl;
									std::cout << "Nazwa projektu: " << projekt.getNazwa() << std::endl;
									std::cout << "Opis projektu: " << projekt.getOpis() << std::endl;
									std::cout << "Cena projektu: " << projekt.getCena() << std::endl;
									std::cout << "-------------------------" << std::endl;
									i++;
								}
								std::cout << "============================" << std::endl;
								std::cout << ".. Wybierz projekt do edycji" << std::endl;
								std::cout << "0. Wyjdź" << std::endl;
								std::cout << "============================" << std::endl;
								std::cout << "Wybierz opcję: ";
								std::cin >> wybor2;
								if (wybor2 <= projekty.size() && wybor2 > 0) {
									std::cout << "=== Edycja projektu ===" << std::endl;
									std::string nowaNazwa, nowyOpis;
									double nowaCena;

									std::cin.ignore();

									std::cout << "Podaj nazwę projektu: ";
									std::getline(std::cin, nowaNazwa);
									std::cout << "Podaj opis projektu: ";
									std::getline(std::cin, nowyOpis);
									std::cout << "Podaj cenę projektu: ";
									std::cin >> nowaCena;
									klient.edytujProjekt(projekty[wybor2], nowaNazwa, nowyOpis);
								}
								else if (wybor2 == 0) {
									// Wyjście z pętli
									std::cout << "Do widzenia!" << std::endl;
									break;
								}
								else {
									std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
									break;
								}
							}
							break;
						}
						case 0: {
							// Wyjście z pętli
							klient.wyloguj();
							std::cout << "Do widzenia!" << std::endl;
							break;
						}
						default: {
							std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
							break;
						}
						}
					} while (wybor1 != 0);
				}
			}
			break;
		}
		case 2: {
			std::string login;
			std::string haslo;

			std::cout << "Podaj login: ";
			std::cin >> login;

			std::cout << "Podaj haslo: ";
			std::cin >> haslo;
			for (Koordynator& koordynator : koordynatorzy)
			{
				koordynator.zaloguj(login, haslo);
				if (koordynator.czyZalogowany())
				{
					do {
						std::cout << "============================" << std::endl;
						std::cout << "1. Wyświetl projekty" << std::endl;
						std::cout << "0. Wyloguj" << std::endl;
						std::cout << "============================" << std::endl;
						std::cout << "Wybierz opcję: ";
						std::cin >> wybor1;
						switch (wybor1) {
						case 1: {
							int i = 1;
							std::cout << "=== Wyświetlenie projektów ===" << std::endl;
							if (!projekty.empty()) {
								for (Projekt& projekt : projekty) {
									std::cout << "ID projektu: " << i << std::endl;
									std::cout << "Nazwa projektu: " << projekt.getNazwa() << std::endl;
									std::cout << "Opis projektu: " << projekt.getOpis() << std::endl;
									std::cout << "Cena projektu: " << projekt.getCena() << std::endl;
									std::cout << "-------------------------" << std::endl;
									i++;
								}
								std::cout << "============================" << std::endl;
								std::cout << ".. Wybierz projekt do edycji" << std::endl;
								std::cout << "0. Wyjdź" << std::endl;
								std::cout << "============================" << std::endl;
								std::cout << "Wybierz opcję: ";
								std::cin >> wybor2;
								if (wybor2 <= projekty.size() && wybor2 > 0) {
									std::cout << "=================================" << std::endl;
									std::cout << "||Co chcesz zrobić z projektem?||" << std::endl;
									std::cout << "=================================" << std::endl;
									std::cout << "1. Zmień status projektu" << std::endl;
									std::cout << "2. Zmień priorytet projektu" << std::endl;
									std::cout << "3. Edytuj dane projektu" << std::endl;
									std::cout << "0. Wyjdź" << std::endl;
									std::cout << "=================================" << std::endl;
									std::cout << "Wybierz opcję: ";
									int wybor3;
									std::cin >> wybor3;
									switch (wybor3) {
									case 1: {
										std::cout << "=================================" << std::endl;
										std::cout << "=========Wybierz status==========" << std::endl;
										std::cout << "=================================" << std::endl;
										std::cout << "1. Przyjęty do realizacji" << std::endl;
										std::cout << "2. Odrzucony" << std::endl;
										std::cout << "3. W realizacji" << std::endl;
										std::cout << "4. Wstrzymany" << std::endl;
										std::cout << "5. Anulowany" << std::endl;
										std::cout << "6. Zakończony" << std::endl;
										std::cout << "0. Wyjdź" << std::endl;
										int wybor4;
										std::cin >> wybor4;
										switch (wybor4) {
										case 1: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Przyjęty do realizacji");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Przyjęty do realizacji\"" << std::endl;
											break;
										}
										case 2: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Odrzucony");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Odrzucony\"" << std::endl;
											break;
										}
										case 3: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "W realizacji");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"W realizacji\"" << std::endl;
											break;
										}
										case 4: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Wstrzymany");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Wstrzymany\"" << std::endl;
											break;
										}
										case 5: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Anulowany");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Anulowany\"" << std::endl;
											break;
										}
										case 6: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Zakończony");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Zakończony\"" << std::endl;
											break;
										}
										case 0: {
											// Wyjście z pętli
											std::cout << "Do widzenia!" << std::endl;
											break;
										}
										default: {
											std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
											break;
										}
										}
										break;
									}
									case 2: {
										std::cout << "=================================" << std::endl;
										std::cout << "=========Wybierz priorytet==========" << std::endl;
										std::cout << "=================================" << std::endl;
										std::cout << "1. Bardzo niski" << std::endl;
										std::cout << "2. Niski" << std::endl;
										std::cout << "3. Średni" << std::endl;
										std::cout << "4. Wysoki" << std::endl;
										std::cout << "5. Bardzo wysoki" << std::endl;
										std::cout << "0. Wyjdź" << std::endl;
										int wybor4;
										std::cin >> wybor4;
										switch (wybor4) {
										case 1: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Bardzo niski");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Bardzo niski\"" << std::endl;
											break;
										}
										case 2: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Niski");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Niski\"" << std::endl;
											break;
										}
										case 3: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Średni");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Średni\"" << std::endl;
											break;
										}
										case 4: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Wysoki");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Wysoki\"" << std::endl;
											break;
										}
										case 5: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Bardzo wysoki");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Bardzo wysoki\"" << std::endl;
											break;
										}
										case 0: {
											// Wyjście z pętli
											std::cout << "Do widzenia!" << std::endl;
											break;
										}
										default: {
											std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
											break;
										}
										}
										break;
									}
									case 3: {
										std::cout << "=== Edycja projektu ===" << std::endl;
										std::string nowaNazwa, nowyOpis;
										double nowaCena;

										std::cin.ignore();

										std::cout << "Podaj nazwę projektu: ";
										std::getline(std::cin, nowaNazwa);
										std::cout << "Podaj opis projektu: ";
										std::getline(std::cin, nowyOpis);
										std::cout << "Podaj cenę projektu: ";
										std::cin >> nowaCena;
										koordynator.edytujProjekt(projekty[wybor2], nowaNazwa, nowyOpis);
										break;
									}
									}
								}
								else if (wybor2 == 0) {
									// Wyjście z pętli
									std::cout << "Do widzenia!" << std::endl;
									break;
								}
								else {
									std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
									break;
								}
							}
							break;
						}
						case 0: {
							// Wyjście z pętli
							koordynator.wyloguj();
							std::cout << "Do widzenia!" << std::endl;
							break;
						}
						default: {
							std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
							break;
						}
						}
					} while (wybor1 != 0);
				}
			}
			break;
		}
		case 3: {
			std::string login;
			std::string haslo;

			std::cout << "Podaj login: ";
			std::cin >> login;

			std::cout << "Podaj haslo: ";
			std::cin >> haslo;
			for (Koordynator& koordynator : koordynatorzy)
			{
				koordynator.zaloguj(login, haslo);
				if (koordynator.czyZalogowany())
				{
					do {
						std::cout << "============================" << std::endl;
						std::cout << "1. Wyświetl projekty" << std::endl;
						std::cout << "2. Zarządzaj finansami" << std::endl;
						std::cout << "0. Wyloguj" << std::endl;
						std::cout << "============================" << std::endl;
						std::cout << "Wybierz opcję: ";
						std::cin >> wybor1;
						switch (wybor1) {
						case 1: {
							int i = 1;
							std::cout << "=== Wyświetlenie projektów ===" << std::endl;
							if (!projekty.empty()) {
								for (Projekt& projekt : projekty) {
									std::cout << "ID projektu: " << i << std::endl;
									std::cout << "Nazwa projektu: " << projekt.getNazwa() << std::endl;
									std::cout << "Opis projektu: " << projekt.getOpis() << std::endl;
									std::cout << "Cena projektu: " << projekt.getCena() << std::endl;
									std::cout << "-------------------------" << std::endl;
									i++;
								}
								std::cout << "============================" << std::endl;
								std::cout << ".. Wybierz projekt do edycji" << std::endl;
								std::cout << "0. Wyjdź" << std::endl;
								std::cout << "============================" << std::endl;
								std::cout << "Wybierz opcję: ";
								std::cin >> wybor2;
								if (wybor2 <= projekty.size() && wybor2 > 0) {
									std::cout << "=================================" << std::endl;
									std::cout << "||Co chcesz zrobić z projektem?||" << std::endl;
									std::cout << "=================================" << std::endl;
									std::cout << "1. Zmień status projektu" << std::endl;
									std::cout << "2. Zmień priorytet projektu" << std::endl;
									std::cout << "3. Edytuj dane projektu" << std::endl;
									std::cout << "0. Wyjdź" << std::endl;
									std::cout << "=================================" << std::endl;
									std::cout << "Wybierz opcję: ";
									int wybor3;
									std::cin >> wybor3;
									switch (wybor3) {
									case 1: {
										std::cout << "=================================" << std::endl;
										std::cout << "=========Wybierz status==========" << std::endl;
										std::cout << "=================================" << std::endl;
										std::cout << "1. Przyjęty do realizacji" << std::endl;
										std::cout << "2. Odrzucony" << std::endl;
										std::cout << "3. W realizacji" << std::endl;
										std::cout << "4. Wstrzymany" << std::endl;
										std::cout << "5. Anulowany" << std::endl;
										std::cout << "6. Zakończony" << std::endl;
										std::cout << "0. Wyjdź" << std::endl;
										int wybor4;
										std::cin >> wybor4;
										switch (wybor4) {
										case 1: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Przyjęty do realizacji");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Przyjęty do realizacji\"" << std::endl;
											break;
										}
										case 2: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Odrzucony");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Odrzucony\"" << std::endl;
											break;
										}
										case 3: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "W realizacji");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"W realizacji\"" << std::endl;
											break;
										}
										case 4: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Wstrzymany");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Wstrzymany\"" << std::endl;
											break;
										}
										case 5: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Anulowany");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Anulowany\"" << std::endl;
											break;
										}
										case 6: {
											koordynator.zmienStatusProjektu(projekty[wybor2], "Zakończony");
											std::cout << "Status projekt nr" << wybor2 << "został ustawiony na \"Zakończony\"" << std::endl;
											break;
										}
										case 0: {
											// Wyjście z pętli
											std::cout << "Do widzenia!" << std::endl;
											break;
										}
										default: {
											std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
											break;
										}
										}
										break;
									}
									case 2: {
										std::cout << "=================================" << std::endl;
										std::cout << "=========Wybierz priorytet==========" << std::endl;
										std::cout << "=================================" << std::endl;
										std::cout << "1. Bardzo niski" << std::endl;
										std::cout << "2. Niski" << std::endl;
										std::cout << "3. Średni" << std::endl;
										std::cout << "4. Wysoki" << std::endl;
										std::cout << "5. Bardzo wysoki" << std::endl;
										std::cout << "0. Wyjdź" << std::endl;
										int wybor4;
										std::cin >> wybor4;
										switch (wybor4) {
										case 1: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Bardzo niski");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Bardzo niski\"" << std::endl;
											break;
										}
										case 2: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Niski");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Niski\"" << std::endl;
											break;
										}
										case 3: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Średni");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Średni\"" << std::endl;
											break;
										}
										case 4: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Wysoki");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Wysoki\"" << std::endl;
											break;
										}
										case 5: {
											koordynator.zmienPriorytetProjektu(projekty[wybor2], "Bardzo wysoki");
											std::cout << "Priorytet projekt nr" << wybor2 << "został ustawiony na \"Bardzo wysoki\"" << std::endl;
											break;
										}
										case 0: {
											// Wyjście z pętli
											std::cout << "Do widzenia!" << std::endl;
											break;
										}
										default: {
											std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
											break;
										}
										}
										break;
									}
									case 3: {
										std::cout << "=== Edycja projektu ===" << std::endl;
										std::string nowaNazwa, nowyOpis;
										double nowaCena;

										std::cout << "Podaj nazwę projektu: ";
										std::cin >> nowaNazwa;
										std::cout << "Podaj opis projektu: ";
										std::cin >> nowyOpis;
										std::cout << "Podaj cenę projektu: ";
										std::cin >> nowaCena;
										koordynator.edytujProjekt(projekty[wybor2], nowaNazwa, nowyOpis);
										break;
									}
									}
								}
								else if (wybor2 == 0) {
									// Wyjście z pętli
									std::cout << "Do widzenia!" << std::endl;
									break;
								}
								else {
									std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
									break;
								}
							}
							break;
						}
						case 2: {

						}
						case 0: {
							// Wyjście z pętli
							koordynator.wyloguj();
							std::cout << "Do widzenia!" << std::endl;
							break;
						}
						default: {
							std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
							break;
						}
						}
					} while (wybor1 != 0);
				}
			}
			break;
		}
		case 0: {
			// Wyjście z pętli
			std::cout << "Do widzenia!" << std::endl;
			break;
		}
		default: {
			std::cout << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
			break;
		}
		}

	} while (wybor != 0);

	/*klient1.wyslijNowyProjekt("Projekt 1", "Opis projektu 1", 5000.0, projekty);
	klient2.wyslijNowyProjekt("Projekt 2", "Opis projektu 2", 5000.0, projekty);
	klient3.wyslijNowyProjekt("Projekt 3", "Opis projektu 3", 5000.0, projekty);

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
	}*/

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
