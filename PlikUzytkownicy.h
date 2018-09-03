#include <iostream>
#include "Plik.h"
#include <vector>
#include <fstream>

using namespace std;

class PlikUzytkownicy :public Plik{
private:
    fstream plik;
    string linia, nrIDstr;
    char znak;
    int nrDanej=1;
    Uzytkownik odczytanyUzytkownik;

public:
        void odczytZPlikuUzytkownicy(Uzytkownicy &);
        void zapisDoPlikuUzytkownicy(Uzytkownicy &);
};
