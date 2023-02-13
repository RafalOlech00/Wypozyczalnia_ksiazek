#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<vector>

using namespace std;

class Ksiazka
{

public:
    Ksiazka(string, string, int, int); // w kolejnosci : autor,tytul,id,ilosc
    void wyswietl(); // wyswietla wszystkie parametry ksiazki
    const string autor;
    const string tytul;
    const int id;
    unsigned int ilosc_egz;
};

class Biblioteka;
class Uzytkownik
{
    friend class Biblioteka;
public:
    Uzytkownik(string, string, int);//w kolejnosci: imie, nazwisko, id
    void wyswietl();



private:
    const string imie;
    const string nazwisko;
    const int id;
    enum { SIZE = 5 };
    unsigned int ile_wolnych;
    int lista_wyp[SIZE];


};

class Biblioteka
{
public:
    Biblioteka();
    void menu(); // Menu wystwieltajace 3 opcje: 1.wypozyczalnia 2. dostepne ksiazki(pokazuje ich wszystkie parametry) 3. wyjscie z programu, wybranie innej opcji spowoduje wyswietleniem sie infromacji o bledzie
    void aktualizuj(); // aktualizowanie ilosci dostepnych ksiazek w bibliotece
    int szukaj_uzytkownika(int);//@param id uzytkownika, @return pozycja uzytkownika w vectorze(jesli nie istnieje zwraca -1)
    int szukaj_ksiazki(int); //@param id ksiazki, @return pozycja ksiazki w vectorze(jesli nie istnieje zwraca -1)
    bool czy_mozna_wypozyczyc(int, int); //@param1 pozycja uzytkownika w vectorze, @param2 pozycja ksiaski w vectorze
    void dostepne_ksiazki(); // wyswietla liste dostepnych ksiazek(ilosciowo wiekszych od 0)
    void dodaj_ksiazke(string, string, int, int); // w kolejnosci: autor,tytul,id,ilosc
    void dodaj_uzytkownika(string, string, int); //w kolejnosci: imie, nazwisko, id
    void wypozycz(int, int); // @param1 pozycja uzytkownika w vectorze uzytkownicy(nie jest to jego id) @param2 pozycja ksiazki w vectorze ksiarzki(nie jest to jej id)



private:
    vector<Ksiazka*> ksiazki;
    vector<Uzytkownik*> uzytkownicy;
    unsigned int ilosc_ksiazek;


};



#endif // BIBLIOTEKA_H_INCLUDED
