#include <iostream>
#include "Header.h"

using namespace std;

/*Funkcja ktora wypisuje dane produktu. Jako argumenty przyjmuje wskaznik tablicy i index elementu*/
void wypisywanie_danych(Produkt*& tablica, int id)
{
    cout << "Nazwa produktu: " << tablica[id].nazwa << endl;
    cout << "Nazwa producentu: " << tablica[id].producent << endl;
    cout << "Rodzaj stalowki: " << tablica[id].rodzaj_stalowki << endl;
    cout << "Napelnianie: " << tablica[id].napelnianie << endl;
    cout << "Kolor: " << tablica[id].kolor << endl;
    cout << "Waga: " << tablica[id].waga << endl;
    cout << "Ilosc znajdujaca w magazynie: " << tablica[id].ilosc_sztuk_w_dostawie << endl;
    cout << "Cena jednostkowa: " << tablica[id].cena_jednostkowa << endl;
    if (tablica[id].data_dostawy.dzien == 0)
    {
        cout << "Dostawa nie jest zaplanowana" << endl;
    }
    else {
        wypisywanie_daty(tablica, id);
    }
}

/*Funckja ktora wypisuje date w przyjetym formacie. Jako argumenty przyjmuje wskznik tablicy i zmienna przechowujaca index elementa
Jest stworzona dla tego zeby nie powtarzac kilka razy ten sam kod*/
void wypisywanie_daty(Produkt*& tablica, int id)
{
    if (tablica[id].data_dostawy.dzien < 10 && tablica[id].data_dostawy.miesiac >= 10)
    {
        cout << "Data nastepnej dostawy: " << 0 << tablica[id].data_dostawy.dzien << '.' << tablica[id].data_dostawy.miesiac << '.' << tablica[id].data_dostawy.rok << endl;
        cout << "Ilosc sztuk w nastepnej dostawie: " << tablica[id].ilosc_sztuk_w_dostawie << endl;
    }
    else if (tablica[id].data_dostawy.dzien >= 10 && tablica[id].data_dostawy.miesiac < 10)
    {
        cout << "Data nastepnej dostawy: " << tablica[id].data_dostawy.dzien << '.' << 0 << tablica[id].data_dostawy.miesiac << '.' << tablica[id].data_dostawy.rok << endl;
        cout << "Ilosc sztuk w nastepnej dostawie: " << tablica[id].ilosc_sztuk_w_dostawie << endl;
    }
    else if (tablica[id].data_dostawy.dzien < 10 && tablica[id].data_dostawy.miesiac < 10)
    {
        cout << "Data nastepnej dostawy: " << 0 << tablica[id].data_dostawy.dzien << '.' << 0 << tablica[id].data_dostawy.miesiac << '.' << tablica[id].data_dostawy.rok << endl;
        cout << "Ilosc sztuk w nastepnej dostawie: " << tablica[id].ilosc_sztuk_w_dostawie << endl;
    }
    else {
        cout << "Data nastepnej dostawy: " << tablica[id].data_dostawy.dzien << '.' << tablica[id].data_dostawy.miesiac << '.' << tablica[id].data_dostawy.rok << endl;
        cout << "Ilosc sztuk w nastepnej dostawie: " << tablica[id].ilosc_sztuk_w_dostawie << endl;
    }
}

//To jest fukcja ktora zwieksza rozmiar tablicy typu Produkt.
//Jako argumenty fukcja bierze wskaznik tablicy i wskaznik zmiennej przechowujacej rozmiar tablicy
void zwiekszanie_tablicy(Produkt*& tablica, int* rozmiar)
{
    Produkt* wsk = new Produkt[(*rozmiar) * 2];
    for (int i = 0; i < *rozmiar; i++)
    {
        wsk[i] = tablica[i];
    }
    delete[]tablica;
    tablica = wsk;
    *rozmiar = *rozmiar * 2;
    wsk = nullptr;
}


/*fukcja ktora zwieksza tablice typu int. Jako argumenty przyjmuje wskaznik tablicy i wskaznik zmiennej przechowujacej rozmiar*/
void zwiekszanie_tablicy_id(int*& tablica, int* rozmiar)
{
    int* wsk = new int[*rozmiar * 2];
    for (int i = 0; i < *rozmiar; i++)
    {
        wsk[i] = tablica[i];
    }
    delete[]tablica;
    tablica = wsk;
    *rozmiar = *rozmiar * 2;
    wsk = nullptr;
}


/*funkcja ktora usuwa pewny element z tablicy. Jako argumenty przyjmuje wskaznik tablicy, zmiennej przechowujacej id elementa, 
wskaznik zmiennej przechowujacej rozmiar tablicy i wskaznik zmiennej przechowujacej index wolnego miejsca*/
void usuniecie(Produkt*& tablica, int id, int* rozmiar, int* wolne_miejsce)
{
    if (*rozmiar == 1)
    {
        delete[]tablica;
        tablica = new Produkt[*rozmiar];
        *wolne_miejsce -= 1;
    }
    else {
        Produkt* wsk = new Produkt[*rozmiar];
        for (int i = 0; i < id; i++)
        {
            wsk[i] = tablica[i];
        }
        for (int i = id; i < (*wolne_miejsce - 1); i++)
        {
            wsk[i] = tablica[i + 1];
        }
        delete[]tablica;
        tablica = new Produkt[*rozmiar];
        tablica = wsk;
        *wolne_miejsce -= 1;
        wsk = nullptr;
    }
}

/*Fukcja pyta u uzytkownika nazwe produktu dane ktorego on chce wyswietlic.
Jako argumenty przyjmuje wskaznik tablicy, wsakaznik zmiennej przechowujacej rozmiar tablicy, 
wskaznik zmiennej przechowujacej index wolnego miesjsca*/
void wypisywanie_danych_produktu(Produkt*& tablica, int* rozmiar, int* wolne_miejsce)
{
    int odpowiedz = 1;
    int wybor = 0;
    int id = -2;
    string nazwa;
    do {
        cout << "Wpisz nazwe produktu, dane ktorego trzeba wyswietlic: ";
        getline(cin, nazwa);
        for (int i = 0; i < *wolne_miejsce; i++)
        {
            if (nazwa == tablica[i].nazwa)
            {
                cout << "Produkt znaleziono" << endl;
                id = i;
                wybor = 0;
                break;
            }
            else if (i == (*wolne_miejsce - 1) && nazwa != tablica[i].nazwa)
            {
                do {
                    cout << "Takiego produktu nie ma wa bazie! Czy chcesz sprobowac jeszcze raz?\n1. Tak;\n2. Nie." << endl;
                    cin >> wybor;
                    if (cin.fail())
                    {
                        cin.clear();
                        cout << "Zle wpisales odpowiedz!" << endl;
                        odpowiedz = 0;
                        cin.ignore(1000, '\n');
                        continue;
                    }
                    else {
                        odpowiedz = 1;
                    }
                    cin.ignore(1000, '\n');
                    if (wybor < 1 || wybor > 2)
                    {
                        cout << "Takiego wyboru nie istnieje" << endl;
                    }
                } while (wybor < 1 || wybor > 2 || odpowiedz == 0);
            }
        }
    } while (wybor == 1);
    if (wybor != 2)
    {
        wypisywanie_danych(tablica, id);
    }
}


/*Funkcja wypisuje nazwy wszystkich produktow zgromadzonych w bazie. Najpierw fukcja sprawdza czy sa produkty dodane do bazy,
jesli tak to pywisuje wszystkie nazwy produktow ktore sa w bazie. Jesli nie to informuje o tym uzytkownika.*/
void wyswietlenie_wszystkich_produktow(Produkt*& tablica, int* wolne_miejsce)
{
    if (*wolne_miejsce == 0)
    {
        cout << "Na razie w bazie nie zadnych produktow" << endl;
    }
    else {
        cout << "To sa nazwy wszystkich produktow w bazie." << endl;
        for (int i = 0; i < *wolne_miejsce; i++)
        {
            cout << i + 1 << ". " << tablica[i].nazwa << endl;
        }
    }
}


/*Funkcja dodaje produkt do bazy. Jako argumenty bierze wskaznik tablicy, wskaznik zmiennej przechowujacej rozmiar i
wskaznik zmiennej przechowujacej index wolnego miejsca.*/
void dodanie_produktu(Produkt*& Piora, int* rozmiar, int* wolne_miejsce)
{
    int odpowiedz = 1;
    if (*wolne_miejsce == *rozmiar)
    {
        zwiekszanie_tablicy(Piora, rozmiar);
    }
    wczytywanie_danych(Piora, *wolne_miejsce);
    *wolne_miejsce += 1;
}


/*Funkcja ususwa produkt z tablicy przechowujacej wszystkie produkty.*/
void ususniecie_produktu(Produkt*& Piora, int* rozmiar, int* wolne_miejsce)
{
    int odpowiedz = 1;
    int id = -1;
    int wybor = 2;
    do {
        cout << "Podaj nazwe produktu ktory trzeba usunac: ";
        string nazwa;
        getline(cin, nazwa);
        for (int i = 0; i < *wolne_miejsce; i++)
        {
            if (nazwa == Piora[i].nazwa)
            {
                id = i;
                wybor = 2;
                break;
            }
            else if (i == (*wolne_miejsce - 1) && nazwa != Piora[i].nazwa)
            {
                do {
                    cout << "Takiego produktu nie istnieje. Czy chcesz sprobowac jeszcze raz? 1. Tak; 2. Nie." << endl;
                    cin >> wybor;
                    if (cin.fail())
                    {
                        cin.clear();
                        cout << "Zle wpisales odpowiedz!" << endl;
                        odpowiedz = 0;
                        cin.ignore(1000, '\n');
                    }
                    else {
                        odpowiedz = 1;
                    }
                    if (wybor < 1 || wybor > 2)
                    {
                        cout << "Takiego wyboru nie ma!" << endl;
                    }
                } while (odpowiedz == 0 || wybor < 1 || wybor > 2);
                cin.ignore(1000, '\n');
            }
        }
    } while (wybor == 1);
    if (id >= 0) {
        usuniecie(Piora, id, rozmiar, wolne_miejsce);
    }
}


/*Funkcja najpierw pyta uzytkownika nazwe produktu dane ktorego trzeba zmienic. Potem pyta co chce zmienic uzytkownik i
zaleznie od wyboru uzytkownika pytamy go jeszcze raz o te dane. Jako argumenty funkcja przyjmuje wskaznik tablicy i wskaznik
rozmiaru*/
void zmiana_danych_produktu(Produkt*& Piora, int* wolne_miejsce)
{
    int odpowiedz = 1;
    int id = -1;
    int wybor_poszuk = 0;
    do {
        cout << "Podaj nazwe produktu: ";
        string nazwa;
        getline(cin, nazwa);
        for (int i = 0; i < *wolne_miejsce; i++)
        {
            if (nazwa == Piora[i].nazwa)
            {
                id = i;
                wybor_poszuk = 0;
                break;
            }
            else if (i == (*wolne_miejsce - 1) && nazwa != Piora[i].nazwa)
            {
                do {
                    cout << "Danego produktu nie znaleziono. Czy chcesz sprobowac jeszcze raz? 1. Tak; 2. Nie" << endl;
                    cin >> wybor_poszuk;
                    if (cin.fail())
                    {
                        cin.clear();
                        cout << "Zle wpisales odpowiedz!" << endl;
                        odpowiedz = 0;
                        cin.ignore(1000, '\n');
                    }
                    else {
                        odpowiedz = 1;
                    }
                    if (wybor_poszuk < 1 || wybor_poszuk > 2)
                    {
                        cout << "Takiego wyboru nie ma!" << endl;
                    }
                } while (odpowiedz == 0 || wybor_poszuk < 1 || wybor_poszuk > 2);
                cin.ignore(1000, '\n');
            }
        }
    } while (wybor_poszuk == 1);
    if (id >= 0) {
        zmiana_danych(Piora, id);
    }
}

/*fuklcja definiuje dla siebie zmienna typu fstream. Potem odkrywa sobie plik o nazwie"baza danych.txt". Potem jezeli plik nie
jest pusty wczytuje inforamcje o produktach do tablicy*/
void wcztywanie_z_pliku(Produkt*& tablica, int* rozmiar, int* wolne_miejsce)
{
    fstream plik;
    plik.open("baza danych.txt", fstream::in);
    string linia;
    int t = 0;
    while (getline(plik, linia))
    {
        if (*rozmiar == *wolne_miejsce)
        {
            zwiekszanie_tablicy(tablica, rozmiar);
        }
        tablica[t].nazwa = linia;
        getline(plik, linia);
        tablica[t].producent = linia;
        getline(plik, linia);
        tablica[t].rodzaj_stalowki = linia;
        getline(plik, linia);
        tablica[t].napelnianie = linia;
        getline(plik, linia);
        tablica[t].kolor = linia;
        getline(plik, linia);
        tablica[t].waga = atoi(linia.c_str());
        getline(plik, linia);
        tablica[t].liczba_w_magazynie = atoi(linia.c_str());
        getline(plik, linia);
        tablica[t].cena_jednostkowa = atof(linia.c_str());
        getline(plik, linia);
        tablica[t].data_dostawy.dzien = atoi(linia.c_str());
        getline(plik, linia);
        tablica[t].data_dostawy.miesiac = atoi(linia.c_str());
        getline(plik, linia);
        tablica[t].data_dostawy.rok = atoi(linia.c_str());
        getline(plik, linia);
        tablica[t].ilosc_sztuk_w_dostawie = atoi(linia.c_str());
        t++;
        *wolne_miejsce += 1;
    }
    plik.close();
}


/*funkcja po zakonczeniu pracy z programem zapisuje dane wszystkich produktow do pliku. Dziala pobodnie jak fukcja ktora
odczytuje.*/
void zapisywanie_do_pliku(Produkt*& tablica, int* wolne_miejsce)
{
    fstream plik;
    plik.open("baza danych.txt", fstream::out);
    for (int i = 0; i < *wolne_miejsce; i++)
    {
        plik << tablica[i].nazwa << endl;
        plik << tablica[i].producent << endl;
        plik << tablica[i].rodzaj_stalowki << endl;
        plik << tablica[i].napelnianie << endl;
        plik << tablica[i].kolor << endl;
        plik << tablica[i].waga << endl;
        plik << tablica[i].liczba_w_magazynie << endl;
        plik << tablica[i].cena_jednostkowa << endl;
        plik << tablica[i].data_dostawy.dzien << endl;
        plik << tablica[i].data_dostawy.miesiac << endl;
        plik << tablica[i].data_dostawy.rok << endl;
        plik << tablica[i].ilosc_sztuk_w_dostawie << endl;
    }
    plik.close();
}