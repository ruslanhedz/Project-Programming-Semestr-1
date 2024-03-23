#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <winbase.h>
#include <fstream>

using namespace std;

struct Data {  // definicja struktury dla daty
    int dzien = 0;
    int miesiac = 0;
    int rok = 0;
};

struct Produkt { // definicja struktury dla produktu
    string nazwa;
    string producent;
    string rodzaj_stalowki;
    string napelnianie;
    string kolor;
    int waga;
    int liczba_w_magazynie;
    float cena_jednostkowa;
    Data data_dostawy;
    int ilosc_sztuk_w_dostawie;
};

void wypisywanie_daty(Produkt*& Piora, int id); // funkcja ktora wypisuje date w zwyklym formacie

void wypisywanie_danych(Produkt*& tablica, int id);// funkcja ktora wypisuje wszystkie dane produktu

void zwiekszanie_tablicy(Produkt*& tablica, int* rozmiar); // funkcja przeznaczona dla zwiekszania tablicy typu Produkt

void zwiekszanie_tablicy_id(int*& tablica, int* rozmiar); // funkcja przeznaczona dla zwiekszania tablicy typu int

void usuniecie(Produkt*& tablica, int id, int* rozmiar, int* wolne_miejsce); // funkcja ktora usuwa element tablicy

void wczytywanie_danych(Produkt*& Piora, int id); // funkcja ktora wczytuje dane produktu

void dodanie_dostawy(Produkt*& tablica, int id, int wybor_programu); // funkcja ktora dodaje dostawe produktu

void zmiana_danych(Produkt*& Piora, int id); // funkcja ktora zmienia dane produktu

void warianty_dla_filtrowania(Produkt*& Piora, int id, int* rozmiar, int* wolne_miejsce); // funkcja ktora ma w sobie wariatny dla filtrowania/wyszukiwania

void wypisywanie_danych(Produkt*& tablica, int* rozmiar, int* wolne_miejsce);// funkcja ktora wypisuje wszystkie dane produktu

void wypisywanie_danych_produktu(Produkt*& tablica, int* rozmiar, int* wolne_miejsce); // funkcja ktora wypisuje dane konkretnego produktu

void wyswietlenie_wszystkich_produktow(Produkt*& tablica, int* wolne_miejsce); // funkcja nazw wszystkich produktow zgromadzonych w bazie

void dodanie_produktu(Produkt*& Piora, int* rozmiar, int* wolne_miejsce); // funkcja ktora dodaje produkt do bazy

void ususniecie_produktu(Produkt*& Piora, int* rozmiar, int* wolne_miejsce); // funkcja ktora usuwa produkt z bazy

void zmiana_danych_produktu(Produkt*& Piora, int* wolne_miejsce); // funkcja ktora zmienia dane produktu

void dodanie_dostawy_produktow(Produkt*& Piora, int* wolne_miejsce); // fukcja ktora dodaje dostawe produktow

void filtrowanie(Produkt*& Piora, int* rozmiar, int* wolne_miejsce); // fukcja ktora fultruje produkty w bazie

void wcztywanie_z_pliku(Produkt*& tablica, int* rozmiar, int* wolne_miejsce); // funkcja ktora wczytuje z pliku dane

void zapisywanie_do_pliku(Produkt*& tablica, int* wolne_miejsce); // funkcja ktora zapisuje w plik dane

void wyszukiwanie_za_pomoca_wyrazen_regurarnych(Produkt*& Piora, int* rozmiar, int* wolne_miejsce); // funkcja ktora wyszukuje za pomoca wyrazen regularnych


#endif // !HEADER_H

