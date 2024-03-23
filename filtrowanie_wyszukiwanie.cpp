#include <iostream>
#include "Header.h"

using namespace std;

/*Funkcja ktora zaytuje uzytkownika co on chce zorbic z produktem. Jako argumenty przyjmuje wskaznik tablicy, idex elementu
, wskaznik rozmiaru i wskaznik zmiennej przechowujacej index wolnego miejsca*/
void warianty_dla_filtrowania(Produkt*& Piora, int id, int* rozmiar, int* wolne_miejsce)
{
    int odpowiedz = 1;
    int wybor_programu;
    do {
        cout << "Co chcesz zrobic nad danym produktem:\n1. Wyswietlenie danych;\n2. Usuniecie produktu;\n3. Zmienic dane produktu;\n4. Dodac dostawe produktu;\n5. Nic." << endl;
        cin >> wybor_programu;
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
        cin.ignore(1000, '\n');
        switch (wybor_programu)
        {
        case 1:
        {
            wypisywanie_danych(Piora, id);
            break;
        }
        case 2:
        {
            usuniecie(Piora, id, rozmiar, wolne_miejsce);
            break;
        }
        case 3:
        {
            zmiana_danych(Piora, id);
            break;
        }
        case 4:
            dodanie_dostawy(Piora, id, 1);
            break;
        case 5:
            break;
        default:
            cout << "Takiego wyboru nie ma!" << endl;
            break;
        }
    } while (odpowiedz == 0 || wybor_programu < 1 || wybor_programu > 5);
}

/*Fukcja szuka element za pomoca nazwy produktu i nazwy producenta. W razie wyboru filtrowania za pomoca nazwy producenta funkcja
wypisze nazwy wszystkich produktow od danego producenta. Jako argumenty przyjmuje wskaznik tablicy, wskznik rozmiaru i wskaznik
zmiennej przechowujacej index wolnego miejsca w tablice glownej*/
void filtrowanie(Produkt*& Piora, int* rozmiar, int* wolne_miejsce)
{
    int odpowiedz = 1;
    int kryterium;
    int rozmiar_pomoc = 1;
    int wolne_miejsce_pomoc = 0;
    int* id = new int[rozmiar_pomoc];
    int wybor_produktu;
    do {
        cout << "Podaj kryterium za ktorym checesz wyszukiwac produkt:\n1. Nazwa;\n2. Producent." << endl;
        cin >> kryterium;
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
        switch (kryterium)
        {
        case 1:
        {
            int wybor;
            do {
                string nazwa;
                cout << "Podaj nazwe produktu: " << endl;
                getline(cin, nazwa);
                for (int i = 0; i < *wolne_miejsce; i++)
                {
                    if (nazwa == Piora[i].nazwa)
                    {
                        cout << "Produkt znaleziono!" << endl;
                        wolne_miejsce_pomoc += 1;
                        id[0] = i;
                        wybor_produktu = 1;
                        wybor = 0;
                        break;
                    }
                    else if (i == (*wolne_miejsce - 1) && nazwa != Piora[i].nazwa)
                    {
                        do {
                            cout << "Produktu o takiej nazwie nie znaleziono. Czy chcesz sprobowac jeszcze raz? 1. Tak; 2. Nie." << endl;
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
                            cin.ignore(1000, '\n');
                            if (wybor < 1 || wybor > 2)
                            {
                                cout << "Takigo wyboru nie ma!" << endl;
                            }
                        } while (odpowiedz == 0 || wybor < 1 || wybor > 2);
                    }
                }
            } while (wybor == 1);
            break;
        }
        case 2:
        {
            int wybor = 0;
            do {
                string producent;
                cout << "Podaj nazwe producenta: ";
                getline(cin, producent);
                for (int i = 0; i < *wolne_miejsce; i++)
                {
                    if (producent == Piora[i].producent)
                    {
                        if (rozmiar_pomoc == wolne_miejsce_pomoc)
                        {
                            zwiekszanie_tablicy_id(id, &rozmiar_pomoc);
                        }
                        id[wolne_miejsce_pomoc] = i;
                        wolne_miejsce_pomoc += 1;
                    }
                }
                if (wolne_miejsce_pomoc == 0)
                {
                    do {
                        cout << "Nie znaleziono zadnego produktu! Chcesz sprobowac jescze raz? 1. Tak; 2. Nie." << endl;
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
                            cout << "Takiego wyboru nie ma!" << endl;
                        }
                    } while (odpowiedz == 0 || wybor < 1 || wybor > 2);
                }
                else
                {
                    wybor = 0;
                }
            } while (wybor == 1);
            if (wybor != 2)
            {
                cout << "Znaleziono " << wolne_miejsce_pomoc << " produkty/ow od danego producenta." << endl;
                cout << "Nazwy Produktow to: " << endl;
                for (int i = 0; i < wolne_miejsce_pomoc; i++)
                {
                    cout << i + 1 << ". " << Piora[id[i]].nazwa << endl;
                }
                if (rozmiar_pomoc > 1)
                {
                    do {
                        cout << "Jaki produkt jest ci potrzebny?(Wpisz numer po jakim jest dobra odpowiedz ";
                        cin >> wybor_produktu;
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
                        if (wybor_produktu < 1 || wybor_produktu > wolne_miejsce_pomoc)
                        {
                            cout << "Takiego wyboru nie ma!" << endl;
                        }
                    } while (odpowiedz == 0 || wybor_produktu < 1 || wybor_produktu > wolne_miejsce_pomoc);
                    cin.ignore(1000, '\n');
                }
                else {
                    wybor_produktu = 1;
                }
                break;
            }
        }
        default:
            cout << "Takiego wyboru nie ma!" << endl;
            break;
        }
    } while (odpowiedz == 0 || kryterium < 1 || kryterium > 2);
    if (wolne_miejsce_pomoc != 0)
    {
        warianty_dla_filtrowania(Piora, id[wybor_produktu - 1], rozmiar, wolne_miejsce);
    }
}

/*Fukcja wyszukuje jakiekolwiek slowo albo wyrazenie, ktore wpisze uszytkownik, u wszystkich chatakterystykach wszytkich
produktow. Jako argumenty przyjmuje wskaznik tablicy, wskaznik zmiennej przechowujaca rozmiar tablicy i wskaznik zmiennej
przechowujacej index wolnego miejsca*/
void wyszukiwanie_za_pomoca_wyrazen_regurarnych(Produkt*& Piora, int* rozmiar, int* wolne_miejsce)
{
    int odpowiedz = 1;
    string charakterystyki[10];
    charakterystyki[0] = "nazwa";
    charakterystyki[1] = "Producent";
    charakterystyki[2] = "rozdzaj stalowki";
    charakterystyki[3] = "napelnianie";
    charakterystyki[4] = "kolor";
    charakterystyki[5] = "waga";
    charakterystyki[6] = "liczba w magazynie";
    charakterystyki[7] = "cena jednostkowa";
    charakterystyki[8] = "data dostawy";
    charakterystyki[9] = "ilosc sztuk w dostawie";
    int rozmiar_linie = 1;
    int wolne_linie = 0;
    int* linie = new int[rozmiar_linie];
    string wyrazenie;
    cout << "Podaj wyrazenie regularne za pomoca ktorego chcesz szukac produkty: ";
    getline(cin, wyrazenie);
    zapisywanie_do_pliku(Piora, wolne_miejsce);
    fstream plik;
    plik.open("baza danych.txt", fstream::in);
    string linia;
    /*Kazdy produkt zajmuje 12 wierszy w pliku(to wynika z charakterystyk ktore ma w strukturze(data dostawy zajmuje
    3 wirszy)). W bazie mamy ilosc proutku rowna indexowi nastepnego wolengo miejsca. Stad wynika ze pliku po zapisaniu
    bazy bedzie wolne_miejsce * 12 wierszy*/
    for (int i = 1; i <= ((*wolne_miejsce) * 12); i++)
    {
        getline(plik, linia);
        if (linia.length() < wyrazenie.length())
        {
            continue;
        }
        else {
            int t = 0;
            int shodnosc = 0;
            for (int k = 0; k < linia.length(); k++)
            {
                if ((wyrazenie[t] != linia[k]) && shodnosc == 0)
                {
                    if (linia.length() == wyrazenie.length())
                    {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                else if ((wyrazenie[t] != linia[k]) && shodnosc != 0)
                {
                    shodnosc = 0;
                    t = 0;
                }
                else if (wyrazenie[t] == linia[k])
                {
                    shodnosc++;
                    t++;
                }
                if (shodnosc == wyrazenie.length())
                {
                    if (rozmiar_linie == wolne_linie)
                    {
                        zwiekszanie_tablicy_id(linie, &rozmiar_linie);
                    }
                    linie[wolne_linie] = i;
                    wolne_linie++;
                    break;
                }
            }
        }
    }
    if (wolne_linie == 0)
    {
        cout << "Nic nie znaleziono o tym wyrazeniu" << endl;
    }
    else {
        int* id = new int[wolne_linie];
        int* cechy = new int[wolne_linie];
        int* id_konieczne = new int[wolne_linie];
        for (int i = 0; i < wolne_linie; i++)
        {
            if (linie[i] % 12 != 0)
            {
                id[i] = linie[i] / 12;
            }
            else if (linie[i] % 12 == 0)
            {
                id[i] = (linie[i] / 12) - 1;
            }
            cechy[i] = linie[i] - (12 * id[i]);
        }
        int k = 0;
        for (int i = 0; i < wolne_linie; i++)
        {
            if (cechy[i] <= 8 || ((cechy[i] > 8 && cechy[i] <= 12) && Piora[id[i]].data_dostawy.dzien != 0))
            {
                break;
            }
            else if (i == wolne_linie - 1)
            {
                k = -1;
            }
        }
        if (k < 0)
        {
            cout << "Nic nie znaleziono o tym wyrazeniu" << endl;
        }
        else {
            cout << "Znaleziono te wyrazenie w nastepujacych elementach: " << endl;
            k = 0;
            for (int i = 0; i < wolne_linie; i++)
            {
                if ((cechy[i] > 8 && cechy[i] <= 12) && Piora[id[i]].data_dostawy.dzien == 0)
                {
                    continue;
                }
                id_konieczne[k] = id[i];
                cout << k + 1 << ". " << "W elemencie o nazwie " << Piora[id[i]].nazwa << " w charakterystyce ";
                if (cechy[i] <= 7)
                {
                    cout << charakterystyki[cechy[i] - 1] << "." << endl;
                    cout << charakterystyki[cechy[i] - 1] << " produktu: \42";
                    if (cechy[i] == 1)
                    {
                        cout << Piora[id[i]].nazwa;
                    }
                    else if (cechy[i] == 2)
                    {
                        cout << Piora[id[i]].producent;
                    }
                    else if (cechy[i] == 3)
                    {
                        cout << Piora[id[i]].rodzaj_stalowki;
                    }
                    else if (cechy[i] == 4)
                    {
                        cout << Piora[id[i]].napelnianie;
                    }
                    else if (cechy[i] == 5)
                    {
                        cout << Piora[id[i]].kolor;
                    }
                    else if (cechy[i] == 6)
                    {
                        cout << Piora[id[i]].waga;
                    }
                    else if (cechy[i] == 7)
                    {
                        cout << Piora[id[i]].liczba_w_magazynie;
                    }
                    else if (cechy[i] == 8)
                    {
                        cout << Piora[id[i]].cena_jednostkowa;
                    }
                    cout << "\42." << endl;
                }
                else if (cechy[i] > 8 && cechy[i] < 12)
                {
                    cout << charakterystyki[8] << endl;
                    cout << charakterystyki[8] << " produktu: \42";
                    wypisywanie_daty(Piora, id[i]);
                    cout << "\42." << endl;
                }
                else if (cechy[i] == 12)
                {
                    cout << charakterystyki[9] << endl;
                    cout << charakterystyki[9] << " produktu: \42";
                    cout << Piora[id[i]].ilosc_sztuk_w_dostawie << "\42." << endl;
                }
                k++;
            }
            delete[]id;
            int wybor_produktu = 0;
            do {
                cout << "Wybierz potrzebny ci produkt: ";
                cin >> wybor_produktu;
                if (cin.fail())
                {
                    cin.clear();
                    cout << "Zle wpisales odpowiedz" << endl;
                    odpowiedz = 0;
                    cin.ignore(1000, '\n');
                    continue;
                }
                else {
                    odpowiedz = 1;
                }
                if (wybor_produktu < 1 || wybor_produktu > k)
                {
                    "Takiego produktu nie ma!";
                }
            } while (odpowiedz == 0 || wybor_produktu < 1 || wybor_produktu > k);
            cin.ignore(1000, '\n');
            warianty_dla_filtrowania(Piora, id_konieczne[wybor_produktu - 1], rozmiar, wolne_miejsce);
        }
        delete[]id_konieczne;
        delete[]cechy;
    }
    plik.close();
    delete[]linie;
}