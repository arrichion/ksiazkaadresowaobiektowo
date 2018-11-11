#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <vector>

using namespace std;

class Adresat {
private:
    string imie, nazwisko, adres;
    int id, idUzytkownika;

public:
    Adresat();
    ~Adresat();

    string getImie();
    void setImie(string noweImie);

    string getNazwisko();
    void setNazwisko(string noweNazwisko);

    string getAdres();
    void setAdres(string nowyAdres);

    int getID();
    void setID(int noweID);

    int getIDuzytkownika();
    void setIDuzytkownika(int noweIDuzytkownika);
};

#endif
