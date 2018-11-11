#include <iostream>
#include "Uzytkownik.h"
#include "Plik.h"
#include <vector>
#include <fstream>

using namespace std;

class PlikUzytkownicy :public Plik{
private:
    fstream plik;
    string linia, nrIDstr;
    char znak;
    int nrDanej;
    Uzytkownik odczytanyUzytkownik;

public:
    PlikUzytkownicy();
    ~PlikUzytkownicy();

    void odczytZPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &liczbaUzytkownikow);
    void zapisDoPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &liczbaUzytkownikow);
    void dodajUzytkownikaDoPlikuUzytkownicy(Uzytkownik dodawanyUzytkownik);
};
