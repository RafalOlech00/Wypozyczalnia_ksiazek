// Napisz program w c++ ktory bedzie zawiera³ klase class Ksiazka
// - tytul;
// - autor;
// - ilosc_egz;
// - id;
// - klase class Uzytkownik;
// - imie;
// - nazwisko;
// -lista_wyp[5] = { 0, 0, 0, 0, 0 };
// Program ma zawierac menu:
// - 1. Wypozyczalnia
// - 2. wyswietl wszystkie ksiazki dostêpne(maja byc sztywno wpisane w programie)
// w wypozyczalni prosisz o podanie id uzytkownika pytasz ile chce ksiazek i potem pytasz jakie ksiazki chce(id tych ksiazek)
// jak wypozyczy np ksiazke numer 2 to do jego konta(tablica 5 elementowa bo moze byc max 5 ksiazek dopisujesz ze ma 1 ksiazke wiecej
// a ze stanu ksiazek odejmujesz 1 + warunki typu nie moze wiecej niz 5 ksiazek wypozyczyc, i jak na stanie sa 2 sztuki to nie mozna 
// wypozyczyc 3 sztuk - BRAK SZTUK.

#include <iostream>
#include<cstdio>
#include "Biblioteka.h"

using namespace std;

int main()
{
    Biblioteka biblioteka;
    biblioteka.dodaj_uzytkownika("Jan", "Nowak", 3);
    biblioteka.dodaj_uzytkownika("Adam", "Kowalski", 4);
    biblioteka.dodaj_ksiazke("Rafal", "Olech", 2, 1);
    biblioteka.dodaj_ksiazke("Mateusz", "Zajac", 7, 2);
    biblioteka.aktualizuj();
    while (true)
    {
        biblioteka.menu();
        cin.ignore();
        cout << "Wcisnij enter:";
        getchar();
        system("cls");
    }

    return 0;
}
