#include "Biblioteka.h"

Ksiazka::Ksiazka(string autor, string tytul, int id, int ilosc) : autor(autor), tytul(tytul), id(id), ilosc_egz(ilosc) {}

void Ksiazka::wyswietl()
{
    cout << "Autor: " << autor << endl;
    cout << "Tytul: " << tytul << endl;
    cout << "ID: " << id << endl;
    cout << "Ilosc dostepnych egzemplarzy: " << ilosc_egz << endl << endl;
}

//Uzytkownik::Uzytkownik(string imie, string naz, int id) : imie(imie), nazwisko(naz), id(id), ile_wolnych(5), lista_wyp{0,0,0,0,0}{}

Uzytkownik::Uzytkownik(string imie, string naz, int id) : imie(imie), nazwisko(naz), id(id), ile_wolnych(5)
{
    lista_wyp[0] = 0;
    lista_wyp[1] = 0;
    lista_wyp[2] = 0;
    lista_wyp[3] = 0;
    lista_wyp[4] = 0;
}


void Uzytkownik::wyswietl()
{
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "ID: " << id << endl;
    cout << "Ile jeszce: " << ile_wolnych << endl;
    cout << "ID ksiazek: ";
    for (int i = 0; i < 5; i++) cout << lista_wyp[i] << " ";
    cout << endl;
}

Biblioteka::Biblioteka() {}

void Biblioteka::aktualizuj()
{
    ilosc_ksiazek = 0;
    for (int i = 0; i < ksiazki.size(); i++)
        ilosc_ksiazek += ksiazki[i]->ilosc_egz;
}

void Biblioteka::wypozycz(int uzyt, int ks)
{
    for (int i = 0; i < 5; i++)
    {
        if (uzytkownicy[uzyt]->lista_wyp[i] == 0)
        {
            uzytkownicy[uzyt]->lista_wyp[i] = ksiazki[ks]->id;
            uzytkownicy[uzyt]->ile_wolnych -= 1;
            ksiazki[ks]->ilosc_egz -= 1;
            break;
        }
    }
}
int Biblioteka::szukaj_uzytkownika(int uz_id)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i]->id == uz_id) return i;
    }
    return -1;
}
int Biblioteka::szukaj_ksiazki(int ks_id)
{
    for (int i = 0; i < ksiazki.size(); i++)
    {
        if (ksiazki[i]->id == ks_id) return i;
    }
    return -1;
}

void Biblioteka::dostepne_ksiazki()
{
    if (ilosc_ksiazek > 0)
        for (unsigned int i = 0; i < ksiazki.size(); i++)
        {
            if (ksiazki[i]->ilosc_egz != 0)
                ksiazki[i]->wyswietl();
        }
    else
        cout << "Brak dostepnych ksiazek" << endl;
}

void Biblioteka::dodaj_ksiazke(string autor, string tytul, int id, int ilosc)
{
    ksiazki.push_back(new Ksiazka(autor, tytul, id, ilosc));
}

void Biblioteka::dodaj_uzytkownika(string imie, string nazwisko, int id)
{
    uzytkownicy.push_back(new Uzytkownik(imie, nazwisko, id));
}

bool Biblioteka::czy_mozna_wypozyczyc(int uz_pos, int ks_pos)
{

    if ((uzytkownicy[uz_pos]->ile_wolnych > 0) && (ksiazki[ks_pos]->ilosc_egz > 0)) return true;
    return false;
}

void Biblioteka::menu()
{
    cout << "1. Wypozyczalnia" << endl;
    cout << "2. Dostepne ksiazki" << endl;
    cout << "3. Wyjdz" << endl;
    cout << "Wybor: ";
    int a;
    cin >> a;
    system("cls");

    switch (a)
    {
        aktualizuj();
    case 1:
        int uz, ks, uz_id, ks_id, ile;
        cout << "Podaj id uzytkownika: ";
        cin >> uz_id;
        uz = szukaj_uzytkownika(uz_id);
        if (uz > -1)
        {
            cout << "Podaj ilosc ksiazek do wypozyczenia: ";
            cin >> ile;

            if (ile <= uzytkownicy[uz]->ile_wolnych && ile <= ilosc_ksiazek)
            {
                int i = 0;
                while (i != ile)
                {
                    cout << "Podaj id ksiazki nr " << i + 1 << " do wypozyczenia: ";
                    cin >> ks_id;
                    system("cls");
                    ks = szukaj_ksiazki(ks_id);

                    if (ks != -1 && czy_mozna_wypozyczyc(uz, ks))
                    {
                        wypozycz(uz, ks);
                        aktualizuj();



                        cout << "Ksiazka zostala wypozyczona" << endl;
                        i++;
                    }
                    else
                        cout << "Nie mozna wypozyczyc ksiazki" << endl;

                }
            }
            else
            {
                cout << "Brak sztuk" << endl;
                break;
            }

        }
        else
        {
            cout << "Taki uzytkownik nie istnieje" << endl;
            break;
        }

        break;
    case 2:
        dostepne_ksiazki();
        break;

    case 3:
        exit(0);
    default:
        cout << "Niepoprawny wybor";
        break;
    }
}
