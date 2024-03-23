#include <iostream>
#include "Header.h"

using namespace std;

/*Funkcja zmienia dane produktu. Jako argument przyjmuje wskaznik tablicy i index elementu. Jest stworzona zeby caly program
byl mniejszy*/
void zmiana_danych(Produkt*& Piora, int id)
{
    int odpowiedz = 1;
    int wybor_zmiany;
    do {
        cout << "Jakie dane Chcesz zmienic(wybierz cyfre po ktora jest dobra odpowiedz):\n"; // pytamy co chce zmienic uzytkownik
        cout << "1. Nazwe;\n2. Nazwe producenta;\n3. rodzaj stalowki;\n4. napelnianie;\n5. kolor;\n6. waga;\n";
        cout << "7. ilosc sztuk dostepnych w magazynie;\n8. cena jednostkowa;\n9. data dostawy;\n10. iloscs sztuk w nastepniej dostawie;" << endl;
        cout << "11. wszystko." << endl;
        cin >> wybor_zmiany;
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
        switch (wybor_zmiany)
        {
        case 1:
        {
            do {
                cout << "Wpisz nazwe produktu: ";
                getline(cin, Piora[id].nazwa);
                if ((Piora[id].nazwa).length() > 256)
                {
                    cout << "Nazwa produktu jest za dluga!" << endl;
                }
            } while ((Piora[id].nazwa).length() > 256);
            break;
        }
        case 2:
        {
            do {
                cout << "Wpisz nazwe producenta: ";
                getline(cin, Piora[id].producent);
                if ((Piora[id].producent).length() > 50)
                {
                    cout << "Nazwa producentu jest za dluga!" << endl;
                }
            } while ((Piora[id].producent).length() > 50);
            break;
        }
        case 3:
        {
            int stalowka;
            do {
                cout << "Podaj rodzaj stalowki(Wpisz numer pod ktorym jest dobra odpowiedz): \n1. F;\n2. M;\n3. B;\n4. EF." << endl;
                cin >> stalowka;
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
                switch (stalowka)
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
            } while (stalowka < 1 || stalowka > 4 || odpowiedz == 0);
            break;
        }
        case 4:
        {
            int napelnianie;
            do {
                cout << "Podaj napelnianie(Wpisz numer pod ktorym jest dobra odpowiedz: \n1. naboje; \n2. tloczek;\n3. naboje i tloczek." << endl;
                cin >> napelnianie;
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
                switch (napelnianie)
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
                    cout << "Takiego wyboru nie ma!" << endl;
                    break;
                }
            } while (napelnianie < 1 || napelnianie > 3 || odpowiedz == 0);
            break;
        }
        case 5:
        {
            do {
                cout << "Wpisz kolor produktu: ";
                getline(cin, Piora[id].kolor);
                if ((Piora[id].kolor).length() > 50)
                {
                    cout << "Kolor produktu jest za dlugi!" << endl;
                }
            } while ((Piora[id].kolor).length() > 50);
            break;
        }
        case 6:
        {
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
            break;
        }
        case 7:
        {
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
                    cout << "liczba w magazynie nie moze byc mniejsza 0" << endl;
                }
            } while (odpowiedz == 0 || Piora[id].liczba_w_magazynie < 0);
            break;
        }
        case 8:
        {
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
                    cout << "Cena jesnostkowa nie moze byc mniejsza lub rowna 0" << endl;
                }
            } while (odpowiedz == 0 || Piora[id].cena_jednostkowa <= 0);
            break;
        }
        case 9:
        {
            int wybor_data;
            do {
                cout << "Czy jest zaplanowana dostawa produktu(Wybierz numer z dobra odpowiedzia):\n1. Tak;\n2. Nie.\n";
                cin >> wybor_data;
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
                if (wybor_data != 1 && wybor_data != 2)
                {
                    cout << "Takiego wybor nie istnieje" << endl;
                }
            } while (odpowiedz == 0 || (wybor_data != 1 && wybor_data != 2));
            dodanie_dostawy(Piora, id, wybor_data);
            break;
        }
        case 10:
        {
            if ((Piora[id].data_dostawy).dzien == 0)
            {
                cout << "Nie mozna zmienic ilosc sztuk w dostawie jezeli nie jest ona zaplanowana! Zmien date dostawy." << endl;
                break;
            }
            else {
                do {
                    cout << "Podaj ilosc sztuk w dostawie: ";
                    cin >> Piora[id].ilosc_sztuk_w_dostawie;
                    if (cin.fail())
                    {
                        cin.clear();
                        cout << "Zle wpisales odpowiedz!" << endl;
                        odpowiedz = 0;
                        cin.ignore();
                        continue;
                    }
                    else {
                        odpowiedz = 1;
                    }
                    if (Piora[id].ilosc_sztuk_w_dostawie <= 0)
                    {
                        cout << "Ilosc sztuk w dostawie nie moze byc mniejsza lub rownac sie 0" << endl;
                    }
                } while (odpowiedz == 0 || Piora[id].ilosc_sztuk_w_dostawie <= 0);
                break;
            }
        }
        case 11:
        {
            wczytywanie_danych(Piora, id);
            break;
        }
        default:
            cout << "Takiego wyboru nie istnieje!" << endl;
            break;
        }
    } while (wybor_zmiany < 1 || wybor_zmiany > 11 || odpowiedz == 0);
}