#include <iostream>
#include "Uzytkownik.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

Uzytkownik::Uzytkownik(){
    nazwa="";
    haslo="";
    id=0;
}
Uzytkownik::~Uzytkownik(){

}

string Uzytkownik::getNazwa(){
    return nazwa;
}

void Uzytkownik::setNazwa(string nowaNazwa){
    nazwa=nowaNazwa;
}

string Uzytkownik::getHaslo(){
    return haslo;
}
void Uzytkownik::setHaslo(string noweHaslo){
    haslo=noweHaslo;
}

int Uzytkownik::getID(){
    return id;
}

void Uzytkownik::setID(int noweID){
    id=noweID;
}
