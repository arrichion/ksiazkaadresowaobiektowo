#include <iostream>
#include "Adresat.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

Adresat::Adresat(){
    imie="";
    nazwisko="";
    adres="";
    id=0;
    idUzytkownika=0;
}
Adresat::~Adresat(){

}

string Adresat::getImie(){
    return imie;
}

void Adresat::setImie(string noweImie){
    imie=noweImie;
}

string Adresat::getNazwisko(){
    return nazwisko;
}

void Adresat::setNazwisko(string noweNazwisko){
    nazwisko=noweNazwisko;
}

string Adresat::getAdres(){
    return adres;
}
void Adresat::setAdres(string nowyAdres){
    adres=nowyAdres;
}

int Adresat::getID(){
    return id;
}

void Adresat::setID(int noweID){
    id=noweID;
}

int Adresat::getIDuzytkownika(){
    return idUzytkownika;
}

void Adresat::setIDuzytkownika(int noweIDuzytkownika){
    idUzytkownika=noweIDuzytkownika;
}
