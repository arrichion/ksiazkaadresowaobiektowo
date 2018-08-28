#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "Uzytkownicy.h"
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

int Uzytkownicy::getLiczbaUzytkownikow(){
    return liczbaUzytkownikow;
}

void Uzytkownicy::setLiczbaUzytkownikow(int nowaLiczbaUzytkownikow){
    liczbaUzytkownikow=nowaLiczbaUzytkownikow;
}

int getIDZalogowanego(){
    return idZalogowanego;
}
void setIDZalogowanego(int noweIDZalogowanego){
    idZalogowanego=noweIDZalogowanego;
}

bool getZalogowano(){
    return zalogowano;
}
void setZalogowano(int noweZalogowano){
    zalogowano=noweZalogowano;
}

vector<Uzytkownik> getUzytkownicy(){
    return uzytkownicy;
}
void setUzytkownicy(vector<Uzytkownik> nowiUzytkownicy){
    uzytkownicy=nowiUzytkownicy;
}

void Uzytkownicy::wprowadzDaneUzytkownika(vector<Uzytkownik> &uzytkownicy, int &liczbaUzytkownikow){
    fstream plik;
    Uzytkownik dodawanyUzytkownik;
    bool powtorzonaNazwa=false;

    cin.clear();
    cin.sync();

    cout<<"Utworz nazwe: ";
    getline(cin, dodawanyUzytkownik.nazwa);
    for(int i=0; i<liczbaUzytkownikow; ++i) {
        if(dodawanyUzytkownik.nazwa==uzytkownicy[i].nazwa) {
            powtorzonaNazwa=true;
            cout<<"Podana nazwa uzytkownika jest juz zajeta.";
        }
    }
    if(!powtorzonaNazwa) {
        cout<<"Utworz haslo: ";
        getline(cin, dodawanyUzytkownik.haslo);
        if(liczbaUzytkownikow==0)
            dodawanyUzytkownik.id=1;
        else
            dodawanyUzytkownik.id=uzytkownicy[liczbaUzytkownikow-1].id+1;

        uzytkownicy.push_back(dodawanyUzytkownik);
        plik.open("uzytkownicy.txt",ios::out | ios::app);

        plik<<uzytkownicy[liczbaUzytkownikow].id<<"|";
        plik<<uzytkownicy[liczbaUzytkownikow].nazwa<<"|";
        plik<<uzytkownicy[liczbaUzytkownikow].haslo<<"|"<<endl;

        plik.close();

        ++liczbaUzytkownikow;

    }

}

void Uzytkownicy::zmienHaslo(vector<Uzytkownik> &uzytkownicy, int idZalogowanego, int liczbaUzytkownikow){
    string noweHaslo="";

    cout<<"Podaj nowe haslo: ";
    cin>>noweHaslo;
    for(int i=0; i<liczbaUzytkownikow; ++i)
        if(uzytkownicy[i].id==idZalogowanego) {
            uzytkownicy[i].haslo=noweHaslo;
            break;
        }
    //zapisDoPlikuUzytkownicy(uzytkownicy, liczbaUzytkownikow);
    cout<<endl<<"Haslo zostalo zmienione";
    Sleep(1000);
}

void Uzytkownicy::logowanie(vector<Uzytkownik> uzytkownicy, int liczbaUzytkownikow, bool &zalogowano, int &idZalogowanego){
    string nazwa, haslo;
    bool znalezionoUzytkownika=false;

    cout<<"Podaj nazwe: ";
    cin>>nazwa;
    cout<<"Podaj haslo: ";
    cin>>haslo;
    cout<<endl;
    for(int i=0; i<liczbaUzytkownikow; ++i)
        if(uzytkownicy[i].nazwa==nazwa) {
            znalezionoUzytkownika=true;
            idZalogowanego=uzytkownicy[i].id;
            if(uzytkownicy[i].haslo==haslo) {
                zalogowano=true;
                cout<<"Zalogowano";
            } else
                cout<<"Bledne haslo";
            Sleep(1000);
        }
    if(znalezionoUzytkownika==false) {
        cout<<endl<<"Nie ma takiego uzytkownika.";
        Sleep(1000);
    }
}

void Uzytkownicy::wylogowanie(bool &zalogowano){
    zalogowano=false;
    //osoby.clear();
    //liczbaOsob=0;
    cout<<"Wylogowano";
}
