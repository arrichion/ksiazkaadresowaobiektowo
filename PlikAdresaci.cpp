#include <iostream>
#include "PlikAdresaci.h"
#include "Adresat.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

PlikAdresaci::PlikAdresaci(){
    nrDanej=0;
    idOstatniegoAdresataWPliku=0;
}

PlikAdresaci::~PlikAdresaci(){

}

int PlikAdresaci::getIDostatniegoAdresataWPliku(){
    return idOstatniegoAdresataWPliku;
}

void PlikAdresaci::setIDostatniegoAdresataWPliku(int noweIDostatniegoUzytkownikaWPliku){
    idOstatniegoAdresataWPliku=noweIDostatniegoUzytkownikaWPliku;
}

void PlikAdresaci::odczytZPlikuAdresaci(vector<Adresat> &adresaci, int &liczbaAdresatow, int idZalogowanegoUzytkownika){
    plik.open("adresaci.txt", ios::in);

    if(plik.good()) {
        while (getline(plik, linia)) {
            Adresat *nowyAdresat = new Adresat();
            znak=' ';
            for(int i=0; znak!='|' || nrDanej!=0; ++i) {
                znak=linia[i];
                if(znak=='|')
                    nrDanej+=1;
                else {
                    switch (nrDanej) {
                    case 0:
                        nrIDstr+=znak;
                        if(linia[i+1]=='|') {
                            nowyAdresat->setID(atoi(nrIDstr.c_str()));
                            nrIDstr="";
                        }
                        break;
                    case 1:
                        nrIDstr+=znak;
                        if(linia[i+1]=='|') {
                            nowyAdresat->setIDuzytkownika(atoi(nrIDstr.c_str()));
                            nrIDstr="";
                        }
                        break;
                    case 2:
                        nowyAdresat->setImie(nowyAdresat->getImie()+=znak);
                        break;
                    case 3:
                        nowyAdresat->setNazwisko(nowyAdresat->getNazwisko()+=znak);
                        break;
                    case 4:
                        nowyAdresat->setAdres(nowyAdresat->getAdres()+=znak);
                        break;
                    }
                }
                if(nrDanej==5) {
                    if(nowyAdresat->getIDuzytkownika()==idZalogowanegoUzytkownika){
                        adresaci.push_back(*nowyAdresat);
                        ++liczbaAdresatow;
                    }
                    nrDanej=0;
                }
            }
            idOstatniegoAdresataWPliku=nowyAdresat->getID();
        }
    }
    plik.close();
}

void PlikAdresaci::zapisDoPlikuAdresaci(vector<Adresat> &adresaci, int &liczbaAdresatow, int idUsuwanegoAlboEdytowanegoAdresata, char stosowanaFuncjaUsuniecieAlboEdycja, int idZalogowanegoUzytkownika){
    plik.open("adresaci.txt",ios::in);
    plikTymczasowy.open("adresaciTymczasowi.txt",ios::out);

    if(plik.good()) {
        while (getline(plik, linia)) {
                for(int i=0; linia[i]!='|'; ++i)
                        nrIDpobieranyZPlikuStr+=linia[i];
                nrIDpobieranyZPliku = atoi(nrIDpobieranyZPlikuStr.c_str());
                nrIDpobieranyZPlikuStr="";
                getch();
                if(nrIDpobieranyZPliku == idUsuwanegoAlboEdytowanegoAdresata){
                    switch(stosowanaFuncjaUsuniecieAlboEdycja){
                    case 'e':
                        for(int i=0; i<liczbaAdresatow; ++i)
                            if(adresaci[i].getID()==idUsuwanegoAlboEdytowanegoAdresata){
                                plikTymczasowy<<adresaci[i].getID()<<"|";
                                plikTymczasowy<<adresaci[i].getIDuzytkownika()<<"|";
                                plikTymczasowy<<adresaci[i].getImie()<<"|";
                                plikTymczasowy<<adresaci[i].getNazwisko()<<"|";
                                plikTymczasowy<<adresaci[i].getAdres()<<"|"<<endl;
                                break;
                            }
                        break;
                    case 'u':
                        break;
                    }
                }
                else
                    plikTymczasowy<<linia<<endl;
        }
    }

    plik.close();
    remove("adresaci.txt");
    plikTymczasowy.close();
    rename("adresaciTymczasowi.txt", "adresaci.txt");
}

void PlikAdresaci::dodajAdresataDoPlikuAdresaci(Adresat dodawanyAdresat){
    plik.open("adresaci.txt",ios::out | ios::app);

    plik<<dodawanyAdresat.getID()<<"|";
    plik<<dodawanyAdresat.getIDuzytkownika()<<"|";
    plik<<dodawanyAdresat.getImie()<<"|";
    plik<<dodawanyAdresat.getNazwisko()<<"|";
    plik<<dodawanyAdresat.getAdres()<<"|"<<endl;

    plik.close();
}
