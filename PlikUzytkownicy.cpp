#include <iostream>
#include "PlikUzytkownicy.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

void PlikUzytkownicy::odczytZPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &liczbaUzytkownikow){
    plik.open("uzytkownicy.txt", ios::in);

    if(plik.good()) {
        while (getline(plik, linia)) {
            uzytkownicy.push_back(odczytanyUzytkownik);
            znak=' ';
            for(int i=0; znak!='|' || nrDanej!=1; ++i) {
                znak=linia[i];
                if(znak=='|')
                    nrDanej+=1;
                else {
                    switch (nrDanej) {
                    case 1:
                        nrIDstr+=znak;
                        if(linia[i+1]=='|') {
                            uzytkownicy[liczbaUzytkownikow].setID(atoi(nrIDstr.c_str()));
                            nrIDstr="";
                        }
                        break;
                    case 2:
                        uzytkownicy[liczbaUzytkownikow].setNazwa(uzytkownicy[liczbaUzytkownikow].getNazwa()+=znak);
                        break;
                    case 3:
                        uzytkownicy[liczbaUzytkownikow].setHaslo(uzytkownicy[liczbaUzytkownikow].getHaslo()+=znak);
                        break;
                    }
                }
                if(nrDanej==4) {
                    nrDanej=1;
                    ++liczbaUzytkownikow;
                }
            }
        }
    }
    plik.close();
}

void PlikUzytkownicy::zapisDoPlikuUzytkownicy(vector<Uzytkownik> &uzytkownicy, int &liczbaUzytkownikow){
    plik.open("uzytkownicy.txt",ios::out);

    for(int i=0; i<liczbaUzytkownikow; ++i) {
        plik<<uzytkownicy[i].getID()<<"|";
        plik<<uzytkownicy[i].getNazwa()<<"|";
        plik<<uzytkownicy[i].getHaslo()<<"|"<<endl;
    }

    plik.close();
}

void PlikUzytkownicy::dodajUzytkownikaDoPlikuUzytkownicy(Uzytkownik dodawanyUzytkownik){
    plik.open("uzytkownicy.txt",ios::out | ios::app);

    plik<<dodawanyUzytkownik.getID()<<"|";
    plik<<dodawanyUzytkownik.getNazwa()<<"|";
    plik<<dodawanyUzytkownik.getHaslo()<<"|"<<endl;

    plik.close();
}
