#include <iostream>
#include "PlikUzytkownicy.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

void PlikUzytkownicy::odczytZPlikuUzytkownicy(Uzytkownicy &users){
    plik.open("uzytkownicy.txt", ios::in);

    if(plik.good()) {
        while (getline(plik, linia)) {
            users.uzytkownicy.push_back(odczytanyUzytkownik);
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
                            users.uzytkownicy[users.liczbaUzytkownikow].setID(atoi(nrIDstr.c_str()));
                            nrIDstr="";
                        }
                        break;
                    case 2:
                        users.uzytkownicy[users.liczbaUzytkownikow].setNazwa(users.uzytkownicy[users.liczbaUzytkownikow].getNazwa()+=znak);
                        break;
                    case 3:
                        users.uzytkownicy[users.liczbaUzytkownikow].setHaslo(users.uzytkownicy[users.liczbaUzytkownikow].getHaslo()+=znak);
                        break;
                    }
                }
                if(nrDanej==4) {
                    nrDanej=1;
                    ++users.liczbaUzytkownikow;
                }
            }
        }
    }
    plik.close();
}

void PlikUzytkownicy::zapisDoPlikuUzytkownicy(Uzytkownicy &users){
    plik.open("uzytkownicy.txt",ios::out);

    for(int i=0; i<users.liczbaUzytkownikow; ++i) {
        plik<<users.uzytkownicy[i].getID()<<"|";
        plik<<users.uzytkownicy[i].getNazwa()<<"|";
        plik<<users.uzytkownicy[i].getHaslo()<<"|"<<endl;
    }

    plik.close();
}
