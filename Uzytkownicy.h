#include <iostream>
#include "PlikUzytkownicy.h"
#include <vector>

using namespace std;

class Uzytkownicy {
private:
    int liczbaUzytkownikow, idZalogowanego;
    bool zalogowano;
    vector<Uzytkownik> uzytkownicy;
    PlikUzytkownicy plikUzytkownicy;

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
    void zmienHaslo();
    void logowanie();
    void wylogowanie();
};
