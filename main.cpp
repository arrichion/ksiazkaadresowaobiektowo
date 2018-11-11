#include <iostream>
#include "Uzytkownicy.h"
#include "Adresaci.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    char wybor;
    Uzytkownicy uzytkownicy;

    while(!uzytkownicy.getZalogowano()) {
        cout<<"-----KSIAZKA ADRESOWA------"<<endl<<endl;
        cout<<"1. Logowanie."<<endl;
        cout<<"2. Rejestracja."<<endl;
        cout<<"0. Wyjdz z programu."<<endl;

        wybor=getch();
        cout<<endl;

        switch(wybor) {
        case '1':
            uzytkownicy.logowanie();
            while(uzytkownicy.getZalogowano()) {
                Adresaci adresaci(uzytkownicy.getIDZalogowanego());
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
                case '1':
                    adresaci.wprowadzDaneAdresata(uzytkownicy.getIDZalogowanego());
                    break;
                case '2':
                    adresaci.wyszukajAdresataPoImieniu();
                    getch();
                    break;
                case '3':
                    adresaci.wyszukajAdresataPoNazwisku();
                    getch();
                    break;
                case '4':
                    adresaci.wyswietlListeAdresatow();
                    getch();
                    break;
                case '5':
                    adresaci.usunAdresata(uzytkownicy.getIDZalogowanego());
                    break;
                case '6':
                    adresaci.edytujAdresata(uzytkownicy.getIDZalogowanego());
                    break;
                case '7':
                    uzytkownicy.zmienHaslo();
                    break;
                case '0':
                    uzytkownicy.wylogowanie();
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
            uzytkownicy.wprowadzDaneUzytkownika();
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
