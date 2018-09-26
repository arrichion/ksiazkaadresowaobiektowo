#include <iostream>
#include "Uzytkownicy.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

Uzytkownicy::Uzytkownicy(){
    liczbaUzytkownikow=0;
    idZalogowanego=0;
    zalogowano = false;
    plikUzytkownicy.odczytZPlikuUzytkownicy(uzytkownicy, liczbaUzytkownikow);
}

Uzytkownicy::~Uzytkownicy(){
    uzytkownicy.clear();
}

int Uzytkownicy::getLiczbaUzytkownikow(){
    return liczbaUzytkownikow;
}

void Uzytkownicy::setLiczbaUzytkownikow(int nowaLiczbaUzytkownikow){
    liczbaUzytkownikow=nowaLiczbaUzytkownikow;
}

int Uzytkownicy::getIDZalogowanego(){
    return idZalogowanego;
}
void Uzytkownicy::setIDZalogowanego(int noweIDZalogowanego){
    idZalogowanego=noweIDZalogowanego;
}

bool Uzytkownicy::getZalogowano(){
    return zalogowano;
}
void Uzytkownicy::setZalogowano(int noweZalogowano){
    zalogowano=noweZalogowano;
}

vector<Uzytkownik> Uzytkownicy::getUzytkownicy(){
    return uzytkownicy;
}
void Uzytkownicy::setUzytkownicy(vector<Uzytkownik> nowiUzytkownicy){
    uzytkownicy=nowiUzytkownicy;
}

void Uzytkownicy::wprowadzDaneUzytkownika(){
    fstream plik;
    Uzytkownik dodawanyUzytkownik;
    string ustawianaNazwa, ustawianeHaslo;
    bool powtorzonaNazwa=false;

    cin.clear();
    cin.sync();

    cout<<"Utworz nazwe: ";
    getline(cin, ustawianaNazwa);
    dodawanyUzytkownik.setNazwa(ustawianaNazwa);
    for(int i=0; i<liczbaUzytkownikow; ++i) {
        if(dodawanyUzytkownik.getNazwa()==uzytkownicy[i].getNazwa()) {
            powtorzonaNazwa=true;
            cout<<"Podana nazwa uzytkownika jest juz zajeta.";
        }
    }
    if(!powtorzonaNazwa) {
        cout<<"Utworz haslo: ";
        getline(cin, ustawianeHaslo);
        dodawanyUzytkownik.setHaslo(ustawianeHaslo);
        if(liczbaUzytkownikow==0)
            dodawanyUzytkownik.setID(1);
        else
            dodawanyUzytkownik.setID(uzytkownicy[liczbaUzytkownikow-1].getID()+1);

        uzytkownicy.push_back(dodawanyUzytkownik);
        plik.open("uzytkownicy.txt",ios::out | ios::app);

        plik<<uzytkownicy[liczbaUzytkownikow].getID()<<"|";
        plik<<uzytkownicy[liczbaUzytkownikow].getNazwa()<<"|";
        plik<<uzytkownicy[liczbaUzytkownikow].getHaslo()<<"|"<<endl;

        plik.close();

        ++liczbaUzytkownikow;
    }
}

void Uzytkownicy::zmienHaslo(){
    string noweHaslo="";

    cout<<"Podaj nowe haslo: ";
    getline(cin,noweHaslo);
    for(int i=0; i<liczbaUzytkownikow; ++i)
        if(uzytkownicy[i].getID()==idZalogowanego) {
            uzytkownicy[i].setHaslo(noweHaslo);
            break;
        }
    plikUzytkownicy.zapisDoPlikuUzytkownicy(uzytkownicy, liczbaUzytkownikow);
    cout<<endl<<"Haslo zostalo zmienione";
    Sleep(1000);
}

void Uzytkownicy::logowanie(){
    string nazwa, haslo;
    bool znalezionoUzytkownika=false;

    cout<<"Podaj nazwe: ";
    getline(cin,nazwa);
    cout<<"Podaj haslo: ";
    getline(cin,haslo);
    cout<<endl;
    for(int i=0; i<liczbaUzytkownikow; ++i)
        if(uzytkownicy[i].getNazwa()==nazwa) {
            znalezionoUzytkownika=true;
            idZalogowanego=uzytkownicy[i].getID();
            if(uzytkownicy[i].getHaslo()==haslo) {
                zalogowano=true;
                cout<<"Zalogowano";
            } else
                cout<<"Bledne haslo";
            Sleep(1000);
        }
    if(znalezionoUzytkownika==false) {
        cout<<"Nie ma takiego uzytkownika.";
        Sleep(1000);
    }
}

void Uzytkownicy::wylogowanie(){
    zalogowano=false;
    //osoby.clear();
    //liczbaOsob=0;
    cout<<"Wylogowano";
}
