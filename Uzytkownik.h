#include <iostream>

using namespace std;

class Uzytkownik{
    private:
    string nazwa="", haslo="";
    int id=0;

    public:
    string getNazwa();
    void setNazwa(string nowaNazwa);

    string getHaslo();
    void setHaslo(string noweHaslo);

    int getID();
    void setID(int noweID);
};
