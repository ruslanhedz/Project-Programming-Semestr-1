#include <iostream>
#include "Header.h"

using namespace std;

void dodanie_dostawy(Produkt*& Piora, int id, int wybor_programu)
{
    int zmiana_sztuk = 0; 
    SYSTEMTIME data_z_windows;
    GetSystemTime(&data_z_windows);
    int ocena_daty_dostawy = 0;
    int odpowiedz = 1;
    switch (wybor_programu)
    {
    case 1:
    {
        if (Piora[id].data_dostawy.dzien != 0)
        {
            zmiana_sztuk = 1;
            int czy_zmieniac; //Zmienna dla sprawdzenia czy chcesz zmieniæ datê dostawy produktu, kiedy ona ju¿ jest zaplanowana
            do {
                cout << "Dla produktu " << Piora[id].nazwa << " juz jest zaplanowana dostawa, czy chcesz ja zmienic? 1. Tak; 2. Nie." << endl;
                wypisywanie_daty(Piora, id);
                cin >> czy_zmieniac;
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
                if (czy_zmieniac < 1 || czy_zmieniac > 2)
                {
                    cout << "Takiego wyboru nie ma!" << endl;
                }
            } while (odpowiedz == 0 || czy_zmieniac < 1 || czy_zmieniac > 2);
            if (czy_zmieniac == 2)
            {
                break;
            }
        }
        do {
            do {
                cout << "Podaj dzien doswawy(od 1 do 31): ";
                cin >> (Piora[id].data_dostawy).dzien;
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
            } while (odpowiedz == 0);
            do {
                cout << "Podaj miesiac dostawy(od 1 do 12): ";
                cin >> (Piora[id].data_dostawy).miesiac;
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
            } while (odpowiedz == 0);
            do {
                cout << "Podaj rok dostawy: ";
                cin >> (Piora[id].data_dostawy).rok;
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
            } while (odpowiedz == 0);
            /*Sprawdzamy czy nie jest data dostawy wczesniejsza od dzisiaj albo wpisany nie istniejacy miesiac*/
            if (((Piora[id].data_dostawy).rok < data_z_windows.wYear) || (((Piora[id].data_dostawy).miesiac < data_z_windows.wMonth) && ((Piora[id].data_dostawy).rok == data_z_windows.wYear)) || (((Piora[id].data_dostawy).rok == data_z_windows.wYear) && (Piora[id].data_dostawy).miesiac == data_z_windows.wMonth) && ((Piora[id].data_dostawy).dzien < data_z_windows.wDay) || Piora[id].data_dostawy.miesiac > 12)
            {
                cout << "Nie mozna zaplanowac dostawe na termin wczesniejszy od dzisiaj albo wpisales nie istniejacy miesiac!" << endl;
                ocena_daty_dostawy = 1;
                continue;
            }
            else
            {
                ocena_daty_dostawy = 0;
            }
            /*Sparwdzamy czy jest wpisany rok przestepny*/
            if (!((((Piora[id].data_dostawy).rok % 4 == 0) && ((Piora[id].data_dostawy).rok % 100 != 0)) || ((Piora[id].data_dostawy).rok % 400 == 0)))
            {
                if ((Piora[id].data_dostawy).miesiac == 2)
                {
                    if ((Piora[id].data_dostawy).dzien >= 29 || (Piora[id].data_dostawy).dzien < 1)
                    {
                        cout << "Takiego dnia miesiaca nie istnieje!" << endl;
                        ocena_daty_dostawy = 1;
                        continue;
                    }
                    else {
                        ocena_daty_dostawy = 0;
                    }
                }
            }
            /*Sprawdzamy czy nie jest wpisany dobry dzien dla lutego*/
            if (Piora[id].data_dostawy.miesiac == 2 && Piora[id].data_dostawy.dzien >= 30)
            {
                cout << "Takiego dnia miesiaca nie istnieje!" << endl;
                ocena_daty_dostawy = 1;
                continue;
            }
            else {
                ocena_daty_dostawy = 0;
            }
            //sprawdzamy date dla miesiacow ktore maja 30 dni
            if ((Piora[id].data_dostawy).miesiac == 4 || (Piora[id].data_dostawy).miesiac == 6 || (Piora[id].data_dostawy).miesiac == 9 || (Piora[id].data_dostawy).miesiac == 11)
            {
                if ((Piora[id].data_dostawy).dzien > 30 || (Piora[id].data_dostawy).dzien < 1)
                {
                    cout << "Takiego dnia miesiaca nie istnieje!" << endl;
                    ocena_daty_dostawy = 1;
                    continue;
                }
                else {
                    ocena_daty_dostawy = 0;
                }
            }
            // sprawdzamy date dla miesiacow ktore maja 31 dni
            else if ((Piora[id].data_dostawy).dzien > 31 || (Piora[id].data_dostawy).dzien < 1)
            {
                cout << "Takiego dnia miesiaca nie istnieje!" << endl;
                ocena_daty_dostawy = 1;
                continue;
            }
            else {
                ocena_daty_dostawy = 0;
            }
        } while (ocena_daty_dostawy == 1);
        if (zmiana_sztuk == 1)
        {
            int wybor;
            do {
                cout << "Zmieniles date dostawy pruduktu, czy trzeba zmienic ilosc sztuk w dostawie? 1. Tak; 2. Nie." << endl;
                cout << "Ilosc sztuk w nastepnej dostawie: " << Piora[id].ilosc_sztuk_w_dostawie << endl;
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
                if (wybor != 1 && wybor != 2)
                {
                    cout << "Takiego wyboru nie istnieje! Wpisz swoj wybor jeszcze raz." << endl;
                }
            } while ((wybor != 1 && wybor != 2) || odpowiedz == 0);
            if (wybor == 2)
            {
                break;
            }
        }
        do {
            cout << "Podaj ilosc sztuk w dostawie: ";
            cin >> Piora[id].ilosc_sztuk_w_dostawie;
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
            if (Piora[id].ilosc_sztuk_w_dostawie <= 0)
            {
                cout << "Nie mozna zamowic mniej lub 0 sztuk!" << endl;
            }
            cin.ignore(1000, '\n');
        } while (odpowiedz == 0 || Piora[id].ilosc_sztuk_w_dostawie <= 0);
        break;
    }
    case 2:
        if (Piora[id].data_dostawy.dzien != 0)
        {
            int czy_zmieniac;
            do {
                cout << "Dla produktu " << Piora[id].nazwa << " juz jest zaplanowana dostawa, czy chcesz ja usunac? 1. Tak; 2. Nie." << endl;
                wypisywanie_daty(Piora, id);
                cin >> czy_zmieniac;
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
                if (czy_zmieniac < 1 || czy_zmieniac > 2)
                {
                    cout << "Takiego wyboru nie ma!" << endl;
                }
            } while (odpowiedz == 0 || czy_zmieniac < 1 || czy_zmieniac > 2);
            if (czy_zmieniac == 2)
            {
                break;
            }
        }
        Piora[id].data_dostawy.dzien = 0;
        Piora[id].data_dostawy.miesiac = 0;
        Piora[id].data_dostawy.rok = 0;
        Piora[id].ilosc_sztuk_w_dostawie = 0;
        break;
    }
}

//Funkcja która s³u¿y dla dodania produktów do bazy
void dodanie_dostawy_produktow(Produkt*& Piora, int* wolne_miejsce)
{
    int odpowiedz = 1;
    int ilosc_produktow = 0;
    int ilosc_ocena = 0;
    int id_good = -1;
    do {
        cout << "Podaj liczbe produktow dla ktorych jest zaplanowana dostawa(Nie ilosc sztuk, a produktow!): ";
        cin >> ilosc_produktow;
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
        if (ilosc_produktow <= 0 || ilosc_produktow > *wolne_miejsce)
        {
            cout << "Nie mozna zaplanowac dostawe dla ilosci mniejszej lub rownej 0 albo wiekszej niz jest dodane do bazy" << endl;
            do {
                cout << "Czy chesz sprobowac dodac dostawe dla ilosci mniejszej?" << endl;
                cout << "1. Tak; 2. Nie" << endl;
                cin >> ilosc_ocena;
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
                if (ilosc_ocena < 1 || ilosc_ocena > 2)
                {
                    cout << "Takiego wyboru nie ma!" << endl;
                }
            } while (ilosc_ocena < 1 || ilosc_ocena > 2 || odpowiedz == 0);
        }
        else {
            ilosc_ocena = 0;
        }
    } while (odpowiedz == 0 || ilosc_ocena == 1);
    cin.ignore(1000, '\n');
    if (ilosc_ocena != 2)
    {
        int* id = new int[ilosc_produktow];
        string nazwa;
        for (int i = 0; i < ilosc_produktow; i++)
        {
            int ocena_nazwy_produktu = 0;
            bool czy_powtarza = false;
            do {
                cout << "Podaj nazwe " << i + 1 << " produktu: ";
                getline(cin, nazwa);
                for (int k = 0; k < *wolne_miejsce; k++)
                {
                    if (nazwa == Piora[k].nazwa)
                    {
                        for (int q = 0; q < i; q++)
                        {
                            ocena_nazwy_produktu = 0;
                            if (id[q] == k)
                            {
                                cout << "Juz wpisywales ten produkt!" << endl;
                                czy_powtarza = true;
                                break;
                            }
                            else {
                                czy_powtarza = false;
                            }
                        }
                        if (czy_powtarza) break;
                        if (!czy_powtarza)
                        {
                            cout << "Produkt znaleziono!" << endl;
                            id[i] = k;
                            break;
                        }
                    }
                    else if (k == ((*wolne_miejsce) - 1) && (nazwa != Piora[k].nazwa))
                    {
                        do {
                            cout << "Takiego produktu nie istnieje. MoZliwie wpisales zle go nazwe albo produkt nie jest dodany." << endl;
                            cout << "Wybierz co program powienien robic dalej:\n1. Zapytac nazwe tego produkktu jeszcze raz;\n2. Pominac ten produkt." << endl;
                            cin >> ocena_nazwy_produktu;
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
                            if (ocena_nazwy_produktu < 1 || ocena_nazwy_produktu > 2)
                            {
                                cout << "Takiego wyboru nie istnieje" << endl;
                            }
                        } while (odpowiedz == 0 || ocena_nazwy_produktu < 1 || ocena_nazwy_produktu > 2);
                        cin.ignore(1000, '\n');
                        if (ocena_nazwy_produktu == 2)
                        {
                            id[i] = -1;
                            break;
                        }
                    }
                }
            } while (ocena_nazwy_produktu == 1 || czy_powtarza);
        }
        int p = 0;
        for (int i = 0; i < ilosc_produktow; i++)
        {
            if (id[i] >= 0)
            {
                p += 1;
                id_good = id[i];
            }
            if (p >= 2)
            {
                break;
            }
        }
        if (p == 1)
        {
            cout << "Znaleziono tylko jeden produkt o nazwie: " << Piora[id_good].nazwa << endl;
            dodanie_dostawy(Piora, id_good, 1);
        }
        else if (p == 0)
        {
            cout << "Nie wybrano zadnego produktu! Sprobuj jeszcze raz" << endl;
        }
        else {
            id_good = -1;
            int zaplanowana_dostawa;
            do {
                cout << "Czy data dostawy produktow jest zaplanowana na ten sam dzieñ?\n1. Tak;\n2. Nie." << endl;
                cin >> zaplanowana_dostawa;
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
                switch (zaplanowana_dostawa)
                {
                case 1:
                {
                    for (int i = 0; i < ilosc_produktow; i++)
                    {
                        if (id[i] >= 0)
                        {
                            id_good = id[i];
                            break;
                        }
                    }
                    cout << "Dodaj dostawe dla " << Piora[id_good].nazwa << "." << endl;
                    dodanie_dostawy(Piora, id_good, 1);
                    for (int i = 0; i < ilosc_produktow; i++)
                    {
                        if (id[i] >= 0 && id[i] != id_good)
                        {
                            if (Piora[id[i]].data_dostawy.dzien != 0)
                            {
                                int czy_zmieniac;
                                do {
                                    cout << "Dla produktu " << Piora[id[i]].nazwa << " juz jest zaplanowana dostawa, czy chcesz ja zmienic? 1. Tak; 2. Nie." << endl;
                                    wypisywanie_daty(Piora, id[i]);
                                    cin >> czy_zmieniac;
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
                                    if (czy_zmieniac < 1 || czy_zmieniac > 2)
                                    {
                                        cout << "Takiego wyboru nie istnieje!" << endl;
                                    }
                                } while (odpowiedz == 0 || czy_zmieniac < 1 || czy_zmieniac > 2);
                                if (czy_zmieniac == 2)
                                {
                                    continue;
                                }
                                else {
                                    Piora[id[i]].data_dostawy = Piora[id_good].data_dostawy;
                                    int czy_trzeba;
                                    do {
                                        cout << "Czy trzeba zmienic ilosc sztuk w dostawie? 1. Tak; 2. Nie." << endl;
                                        cin >> czy_trzeba;
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
                                        switch (czy_trzeba)
                                        {
                                        case 1:
                                            do {
                                                cout << "podaj ilosc sztuk w dostawie: ";
                                                cin >> Piora[id[i]].ilosc_sztuk_w_dostawie;
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
                                                if (Piora[id[i]].ilosc_sztuk_w_dostawie <= 0)
                                                {
                                                    cout << "Nie mozna zamowic 0 i mniej sztuk" << endl;
                                                }
                                            } while (odpowiedz == 0 || Piora[id[i]].ilosc_sztuk_w_dostawie <= 0);
                                            break;
                                        case 2:
                                            break;
                                        default:
                                            cout << "Takiego wyboru nie ma!" << endl;
                                            break;
                                        }
                                    } while ((czy_trzeba != 1 && czy_trzeba != 2) || odpowiedz == 0);
                                }
                            }
                            else {
                                Piora[id[i]].data_dostawy = Piora[id_good].data_dostawy;
                                do {
                                    cout << "podaj ilosc sztuk w dostawie dla prduktu " << Piora[id[i]].nazwa << ": ";
                                    cin >> Piora[id[i]].ilosc_sztuk_w_dostawie;
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
                                    if (Piora[id[i]].ilosc_sztuk_w_dostawie <= 0)
                                    {
                                        cout << "Nie mozna zamowic 0 lub mniej produktow" << endl;
                                    }
                                } while (odpowiedz == 0 || Piora[id[i]].ilosc_sztuk_w_dostawie <= 0);
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    for (int i = 0; i < ilosc_produktow; i++)
                    {
                        if (id[i] >= 0)
                        {
                            cout << "Podaj dostawe dla produktu " << Piora[id[i]].nazwa << "." << endl;
                            dodanie_dostawy(Piora, id[i], 1);
                        }
                    }
                }
                default:
                {
                    cout << "Takiego wyboru nie ma!" << endl;
                    break;
                }
                }
            } while (zaplanowana_dostawa < 1 || zaplanowana_dostawa > 2 || odpowiedz == 0);
        }
        delete[]id;
    }
}