#include <iostream>
#include "Uzytkownik.h"
#include <vector>

using namespace std;

class Uzytkownicy{
    private:
    int liczbaUzytkownikow=0, idZalogowanego=0;
    bool zalogowano = false;

    public:
    vector<Uzytkownik> uzytkownicy;

    public:
    int getLiczbaUzytkownikow();
    void setLiczbaUzytkownikow(int nowaLiczbaUzytkownikow);

    int getIDZalogowanego();
    void setIDZalogowanego(int noweIDZalogowanego);

    bool getZalogowano();
    void setZalogowano(int noweZalogowano);

    vector<Uzytkownik> getUzytkownicy();
    void setUzytkownicy(vector<Uzytkownik> nowiUzytkownicy);

    void wprowadzDaneUzytkownika(vector<Uzytkownik> &uzytkownicy, int &liczbaUzytkownikow);
    void zmienHaslo(vector<Uzytkownik> &uzytkownicy, int idZalogowanego, int liczbaUzytkownikow);
    void logowanie(vector<Uzytkownik> uzytkownicy, int liczbaUzytkownikow, bool &zalogowano, int &idZalogowanego);
    void wylogowanie(bool &zalogowano);
};
