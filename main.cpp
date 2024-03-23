#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    int sparwdzenie_zapisu = 0;
    int odpowiedz = 1;
    int rozmiar_tablicy = 1;
    int wolne_miejsce = 0;
    Produkt* Piora;
    Piora = new Produkt[rozmiar_tablicy];
    wcztywanie_z_pliku(Piora, &rozmiar_tablicy, &wolne_miejsce);
    int wybor_programu = -1;
    do {
        cout << "MENU" << endl;
        cout << "Zeby poroszac sie po menu wpisuj liczby pod ktorymi jest potrzebny ci program" << endl;
        cout << "1. Wyswietlic dane produktu;" << endl;
        cout << "2. Dodac produkt do bazy;" << endl;
        cout << "3. Usunac produkt z bazy;" << endl;
        cout << "4. Zmienic dane produktu;" << endl;
        cout << "5. Dodanie dostawy produktow(produkty powinny zostac juz dodane do bazy przed dodaniem ich dodstawy);" << endl;
        cout << "6. Filtorwanie za pomoca nazwy/producenta;" << endl;
        cout << "7. Wypisanie wszysrkich produktow ktore sa w bazie;" << endl;
        cout << "8. Wyszukiwanie za pomoca wyrazen regularnych;" << endl;
        cout << "9. Zapisac baze do pliku;" << endl;
        cout << "0. Zakonczyc prace." << endl;
        cin >> wybor_programu;
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
        switch (wybor_programu)
        {
        case 1:
            wypisywanie_danych_produktu(Piora, &rozmiar_tablicy, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 2:
            dodanie_produktu(Piora, &rozmiar_tablicy, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 3:
            ususniecie_produktu(Piora, &rozmiar_tablicy, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 4:
            zmiana_danych_produktu(Piora, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 5:
            dodanie_dostawy_produktow(Piora, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 6:
            filtrowanie(Piora, &rozmiar_tablicy, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 7:
            wyswietlenie_wszystkich_produktow(*&Piora, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 8:
            wyszukiwanie_za_pomoca_wyrazen_regurarnych(Piora, &rozmiar_tablicy, &wolne_miejsce);
            sparwdzenie_zapisu = 0;
            break;
        case 9:
            zapisywanie_do_pliku(Piora, &wolne_miejsce);
            sparwdzenie_zapisu = 1;
            break;
        case 0:
            break;
        default:
            cout << "Takiego wyboru nie ma!" << endl;
            break;
        }
    } while (wybor_programu != 0 || odpowiedz == 0);
    if (sparwdzenie_zapisu == 0)
    {
        zapisywanie_do_pliku(Piora, &wolne_miejsce);
    }
    delete[]Piora;
    return 0;
}
