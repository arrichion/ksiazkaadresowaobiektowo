#ifndef ADRESACI_H
#define ADRESACI_H

#include <iostream>
#include "PlikAdresaci.h"
#include <vector>

using namespace std;

class Adresaci {
private:
    int liczbaAdresatow;
    vector<Adresat> adresaci;
    PlikAdresaci plikAdresaci;

public:
    Adresaci(int idZalogowanegoUzytkownika);
    ~Adresaci();

    int getLiczbaAdresatow();
    void setLiczbaAdresatow(int nowaLiczbaAdresatow);

    vector<Adresat> getAdresaci();
    void setAdresaci(vector<Adresat> nowiAdresaci);

    void wprowadzDaneAdresata(int idZalogowanegoUzytkownika);
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void wyswietlAdresata(int nrAdresata);
    void wyswietlListeAdresatow();
    void usunAdresata(int idZalogowanegoUzytkownika);
    void edytujAdresata(int idZalogowanegoUzytkownika);
};

#endif
