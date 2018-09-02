#include <iostream>
#include "Uzytkownik.h"
#include <vector>

using namespace std;

class PlikUzytkownicy;

class Uzytkownicy {
private:
    int liczbaUzytkownikow, idZalogowanego;
    bool zalogowano;
    vector<Uzytkownik> uzytkownicy;

public:
    Uzytkownicy();
    ~Uzytkownicy();

    int getLiczbaUzytkownikow();
    void setLiczbaUzytkownikow(int nowaLiczbaUzytkownikow);

    int getIDZalogowanego();
    void setIDZalogowanego(int noweIDZalogowanego);

    bool getZalogowano();
    void setZalogowano(int noweZalogowano);

    vector<Uzytkownik> getUzytkownicy();
    void setUzytkownicy(vector<Uzytkownik> nowiUzytkownicy);

    void wprowadzDaneUzytkownika();
    void zmienHaslo(Uzytkownicy &, PlikUzytkownicy &);
    void logowanie();
    void wylogowanie();

    friend class PlikUzytkownicy;
    friend void odczytZPlikuUzytkownicy(Uzytkownicy &);
    friend void zapisDoPlikuUzytkownicy(Uzytkownicy &, PlikUzytkownicy &);
};
