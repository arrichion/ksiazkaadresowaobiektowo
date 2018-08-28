#include <iostream>
#include "Uzytkownicy.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    char wybor;
    Uzytkownicy uzytkownicy2;

    while(!uzytkownicy2.getZalogowano()) {
        cout<<"-----KSIAZKA ADRESOWA------"<<endl<<endl;
        cout<<"1. Logowanie."<<endl;
        cout<<"2. Rejestracja."<<endl;
        cout<<"0. Wyjdz z programu."<<endl;

        wybor=getch();
        cout<<endl;

        switch(wybor) {
        case '1':
            uzytkownicy2.logowanie(uzytkownicy2.uzytkownicy, uzytkownicy2.getLiczbaUzytkownikow, uzytkownicy2.getZalogowano(), uzytkownicy2.getIDZalogowanego());
            //odczytZPlikuKsiazka(osoby, liczbaOsob, idZalogowanego);
            while(uzytkownicy2.getZalogowano()) {
                system("cls");
                cout<<"-----KSIAZKA ADRESOWA------"<<endl<<endl;
                cout<<"1. Wprowadz dane osoby."<<endl;
                cout<<"2. Wyszukaj osobe po imieniu."<<endl;
                cout<<"3. Wyszukaj osobe po nazwisku."<<endl;
                cout<<"4. Wyswietl wszystkie osoby z ksiazki."<<endl;
                cout<<"5. Usun osobe."<<endl;
                cout<<"6. Edytuj osobe."<<endl;
                cout<<"7. Zmien haslo."<<endl;
                cout<<"0. Wyloguj sie."<<endl;

                wybor=getch();
                cout<<endl;

                switch(wybor) {
                /*case '1':
                    wprowadzDane(osoby, liczbaOsob, idZalogowanego);
                    break;
                case '2':
                    wyszukajPoImieniu(osoby, liczbaOsob);
                    getch();
                    break;
                case '3':
                    wyszukajPoNazwisku(osoby, liczbaOsob);
                    getch();
                    break;
                case '4':
                    wyswietlListeOsob(osoby, liczbaOsob);
                    getch();
                    break;
                case '5':
                    usunOsobe(osoby, liczbaOsob);
                    break;
                case '6':
                    edytujOsobe(osoby, liczbaOsob);
                    break;*/
                case '7':
                    uzytkownicy2.zmienHaslo(uzytkownicy2.getUzytkownicy(), uzytkownicy2.getIDZalogowanego(), uzytkownicy2.getLiczbaUzytkownikow);
                    break;
                case '0':
                    uzytkownicy2.wylogowanie(uzytkownicy2.getZalogowano());
                    break;
                default:
                    cout<<"Nie ma takiej opcji.";
                    Sleep(1000);
                    break;
                }
                system("cls");
            }
            break;
        case '2':
            uzytkownicy2.wprowadzDaneUzytkownika(uzytkownicy2.getUzytkownicy(), uzytkownicy2.getLiczbaUzytkownikow);
            getch();
            break;
        case '0':
            cout<<"Zegnaj :(";
            Sleep(1000);
            exit(0);
            break;
        default:
            cout<<"Nie ma takiej opcji.";
            Sleep(1000);
            break;
        }
        system("cls");
    }

    return 0;
}
