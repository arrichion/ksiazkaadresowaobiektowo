#include <iostream>
#include <vector>

using namespace std;

class Uzytkownik {
private:
    string nazwa, haslo;
    int id;

public:
    Uzytkownik();
    ~Uzytkownik();

    string getNazwa();
    void setNazwa(string nowaNazwa);

    string getHaslo();
    void setHaslo(string noweHaslo);

    int getID();
    void setID(int noweID);
};
