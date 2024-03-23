#include <iostream>
#include "Header.h"

using namespace std;

void wczytywanie_danych(Produkt*& Piora, int id)
{
    int odpowiedz = 1;
    do {
        cout << "Wpisz nazwe produktu: ";
        getline(cin, Piora[id].nazwa);
        if ((Piora[id].nazwa).length() > 256)
        {
            cout << "Nazwa produktu jest za dluga!" << endl;
        }
    } while ((Piora[id].nazwa).length() > 256);
    do {
        cout << "Wpisz nazwe producenta: ";
        getline(cin, Piora[id].producent);
        if ((Piora[id].producent).length() > 50)
        {
            cout << "Nazwa producentu jest za dluga!" << endl;
        }
    } while ((Piora[id].producent).length() > 50);
    int wybor;
    do {
        cout << "Podaj rodzaj stalowki(Wpisz numer pod ktorym jest dobra odpowiedz): \n1. F;\n2. M;\n3. B;\n4. EF." << endl; //zapytujemy uzytkonika o rodzaj stalowki piora
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
        switch (wybor)
        {
        case 1:
            Piora[id].rodzaj_stalowki = "F";
            break;
        case 2:
            Piora[id].rodzaj_stalowki = "M";
            break;
        case 3:
            Piora[id].rodzaj_stalowki = "B";
            break;
        case 4:
            Piora[id].rodzaj_stalowki = "EF";
            break;
        default:
            cout << "Takiego wyboru nie ma!" << endl;
            break;
        }
    } while (wybor < 1 || wybor > 4 || odpowiedz == 0);
    do {
        cout << "Podaj napelnianie(Wpisz numer pod ktorym jest dobra odpowiedz: \n1. naboje; \n2. tloczek;\n3. naboje i tloczek." << endl;
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
        switch (wybor)
        {
        case 1:
            Piora[id].napelnianie = "naboje";
            break;
        case 2:
            Piora[id].napelnianie = "tloczek";
            break;
        case 3:
            Piora[id].napelnianie = "naboje i tloczek";
            break;
        default:
            cout << "Zle wpisales odpowiedz!" << endl;
            break;
        }
    } while (wybor < 1 || wybor > 3 || odpowiedz == 0);
    do {
        cout << "Wpisz kolor produktu: ";
        getline(cin, Piora[id].kolor);
        if ((Piora[id].kolor).length() > 50)
        {
            cout << "Kolor produktu jest za dlugi!" << endl;
        }
    } while ((Piora[id].kolor).length() > 50);
    do {
        cout << "Wpisz wage produktu(w gramach): ";
        cin >> Piora[id].waga;
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
        if (Piora[id].waga <= 0)
        {
            cout << "Waga nie moze byc mniejsza lub rowna 0" << endl;
        }
    } while (odpowiedz == 0 || Piora[id].waga <= 0);
    do {
        cout << "Wpisz ilosc znajdujaca w magazynie: ";
        cin >> Piora[id].liczba_w_magazynie;
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
        if (Piora[id].liczba_w_magazynie < 0)
        {
            cout << "Liczba sztuk w magazynie nie moze mniejsza 0" << endl;
        }
    } while (odpowiedz == 0 || Piora[id].liczba_w_magazynie < 0);
    do {
        cout << "Wpisz cene jednostkowa: ";
        cin >> Piora[id].cena_jednostkowa;
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
        if (Piora[id].cena_jednostkowa <= 0)
        {
            cout << "Cena jednoskowa nie moze byc mniejsza lub rowna 0" << endl;
        }
    } while (odpowiedz == 0 || Piora[id].cena_jednostkowa <= 0);
    do {
        cout << "Czy jest zaplanowana dostawa produktu(Wybierz numer z dobra odpowiedzia):\n1. Tak;\n2. Nie.\n";
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
        if (wybor < 1 || wybor > 2)
        {
            cout << "Takiego wyboru nie istnieje!" << endl;
        }
    } while (odpowiedz == 0 || wybor < 1 || wybor > 2);
    dodanie_dostawy(Piora, id, wybor);
}