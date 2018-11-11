#include <iostream>
#include "Adresaci.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

Adresaci::Adresaci(int idZalogowanegoUzytkownika){
    liczbaAdresatow=0;
    plikAdresaci.odczytZPlikuAdresaci(adresaci, liczbaAdresatow, idZalogowanegoUzytkownika);
}

Adresaci::~Adresaci(){
    adresaci.clear();
}

int Adresaci::getLiczbaAdresatow(){
    return liczbaAdresatow;
}

void Adresaci::setLiczbaAdresatow(int nowaLiczbaAdresatow){
    liczbaAdresatow = nowaLiczbaAdresatow;
}

vector<Adresat> Adresaci::getAdresaci(){
    return adresaci;
}

void Adresaci::setAdresaci(vector<Adresat> nowiAdresaci){
    adresaci = nowiAdresaci;
}

void Adresaci::wyswietlAdresata(int nrAdresata){
    cout<<adresaci[nrAdresata].getImie()<<" "<<adresaci[nrAdresata].getNazwisko()<<endl;
    cout<<adresaci[nrAdresata].getAdres()<<endl;
    cout<<"ID: "<<adresaci[nrAdresata].getID()<<endl<<endl;
}

void Adresaci::wprowadzDaneAdresata(int idZalogowanegoUzytkownika){
    fstream plik;
    Adresat dodawanyAdresat;
    string wprowadzaneImie, wprowadzaneNazwisko, wprowadzanyAdres;

    cin.clear();
    cin.sync();

    dodawanyAdresat.setIDuzytkownika(idZalogowanegoUzytkownika);
    cout<<"Podaj imie: ";
    getline(cin, wprowadzaneImie);
    dodawanyAdresat.setImie(wprowadzaneImie);
    cout<<"Podaj nazwisko: ";
    getline(cin, wprowadzaneNazwisko);
    dodawanyAdresat.setNazwisko(wprowadzaneNazwisko);
    cout<<"Podaj adres: ";
    getline(cin, wprowadzanyAdres);
    dodawanyAdresat.setAdres(wprowadzanyAdres);
    //if(plikAdresaci.getIDostatniegoAdresataWPliku()==0)
        //dodawanyAdresat.setID(1);
    //else{
        dodawanyAdresat.setID(plikAdresaci.getIDostatniegoAdresataWPliku()+1);
        plikAdresaci.setIDostatniegoAdresataWPliku(dodawanyAdresat.getID());
    //}


    adresaci.push_back(dodawanyAdresat);

    plik.open("adresaci.txt",ios::out | ios::app);

    plik<<adresaci[liczbaAdresatow].getID()<<"|";
    plik<<adresaci[liczbaAdresatow].getIDuzytkownika()<<"|";
    plik<<adresaci[liczbaAdresatow].getImie()<<"|";
    plik<<adresaci[liczbaAdresatow].getNazwisko()<<"|";
    plik<<adresaci[liczbaAdresatow].getAdres()<<"|"<<endl;

    plik.close();

    ++liczbaAdresatow;
}

void Adresaci::wyszukajAdresataPoImieniu(){
    string wyszukiwaneImie;
    bool znalezionoAdresataWKsiazce = false;

    cout<<"Podaj szukane imie: ";
    cin>>wyszukiwaneImie;
    cout<<endl;
    for(int i=0; i<liczbaAdresatow; ++i)
        if(adresaci[i].getImie()==wyszukiwaneImie) {
            wyswietlAdresata(i);
            znalezionoAdresataWKsiazce=true;
        }
    if(znalezionoAdresataWKsiazce==false)
        cout<<endl<<"Brak osob o tym imieniu.";
}

void Adresaci::wyszukajAdresataPoNazwisku(){
    string wyszukiwaneNazwisko;
    bool znalezionoAdresataWKsiazce = false;

    cout<<"Podaj szukane nazwisko: ";
    cin>>wyszukiwaneNazwisko;
    cout<<endl;
    for(int i=0; i<liczbaAdresatow; ++i)
        if(adresaci[i].getNazwisko()==wyszukiwaneNazwisko) {
            wyswietlAdresata(i);
            znalezionoAdresataWKsiazce=true;
        }
    if(znalezionoAdresataWKsiazce==false)
        cout<<endl<<"Brak osob o tym nazwisku.";
}

void Adresaci::wyswietlListeAdresatow(){
    if(liczbaAdresatow==0)
        cout<<"W ksiazce nie ma aktualnie zadnych zapisanych osob.";
    else
        for(int i=0; i<liczbaAdresatow; ++i)
            wyswietlAdresata(i);
}

void Adresaci::usunAdresata(int idZalogowanegoUzytkownika){
    int nrIDusuwanegoAdresata;
    char wybor;
    bool znalezionoAdrestaWKsiazce = false;
    vector <Adresat>::iterator itr;

    cout<<"Podaj nr ID osoby, ktora chcesz usunac: ";
    cin>>nrIDusuwanegoAdresata;

    for(int i=0; i<liczbaAdresatow; ++i)
        if(adresaci[i].getID()==nrIDusuwanegoAdresata) {
            znalezionoAdrestaWKsiazce = true;
            itr = adresaci.begin()+i;
            cout<<"Czy na pewno chcesz usunac "<<adresaci[i].getImie()<<" "<<adresaci[i].getNazwisko()<<"? (t/n)";
            wybor=getch();
            switch(wybor) {
            case 't':
                cout<<endl<<"Usunieto "<<adresaci[i].getImie()<<" "<<adresaci[i].getNazwisko()<<" z ksiazki.";
                adresaci.erase(itr);
                --liczbaAdresatow;
                plikAdresaci.zapisDoPlikuAdresaci(adresaci, liczbaAdresatow, nrIDusuwanegoAdresata, 'u', idZalogowanegoUzytkownika);
                break;
            case 'n':
                cout<<endl<<adresaci[i].getImie()<<" "<<adresaci[i].getNazwisko()<<" pozostal w ksiazce.";
                break;
            }
            break;
        }
    if(znalezionoAdrestaWKsiazce==false)
        cout<<"Nie ma w ksiazce adresaci o podanym ID.";
        Sleep(1000);
}

void Adresaci::edytujAdresata(int idZalogowanegoUzytkownika){
    int nrIDedytowanegoAdresata;
    char wybor;
    string noweImie, noweNazwisko, nowyAdres;
    bool znalezionoAdrestaWKsiazce = false;

    cout<<"Podaj nr ID osoby, ktora chcesz edytowac: ";
    cin>>nrIDedytowanegoAdresata;

    for(int i=0; i<liczbaAdresatow; ++i) {
        if(adresaci[i].getID()==nrIDedytowanegoAdresata) {
            znalezionoAdrestaWKsiazce = true;
            cout<<endl<<adresaci[i].getImie()<<" "<<adresaci[i].getNazwisko()<<endl;
            cout<<adresaci[i].getAdres()<<endl;

            cout<<endl;
            cout<<"1. Edytuj imie."<<endl;
            cout<<"2. Edytuj nazwisko."<<endl;
            cout<<"3. Edytuj adres."<<endl;

            wybor = getch();
            cout<<endl;

            cin.clear();
            cin.sync();
            switch(wybor) {
            case '1':
                cout<<"Podaj nowe imie: ";
                getline(cin, noweImie);
                adresaci[i].setImie(noweImie);
                break;
            case '2':
                cout<<"Podaj nowe nazwisko: ";
                getline(cin, noweNazwisko);
                adresaci[i].setNazwisko(noweNazwisko);
                break;
            case '3':
                cout<<"Podaj nowy adres: ";
                getline(cin, nowyAdres);
                adresaci[i].setAdres(nowyAdres);
                break;
            }
            plikAdresaci.zapisDoPlikuAdresaci(adresaci, liczbaAdresatow, nrIDedytowanegoAdresata, 'e', idZalogowanegoUzytkownika);
            break;
        }
    }
    if(znalezionoAdrestaWKsiazce==false)
        cout<<"Nie ma w ksiazce adresaci o podanym ID.";
        Sleep(1000);
}
