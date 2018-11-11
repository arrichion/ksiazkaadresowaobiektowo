#include <iostream>
#include "Adresat.h"
#include "Plik.h"
#include <vector>
#include <fstream>

using namespace std;

class PlikAdresaci :public Plik{
private:
    fstream plik;
    fstream plikTymczasowy;
    string linia, nrIDstr, nrIDpobieranyZPlikuStr;
    char znak;
    char znakStosowanejFunkcjiUsuniecieAlboEdycja;
    int nrDanej, nrIDpobieranyZPliku, idOstatniegoAdresataWPliku;
    Adresat odczytanyAdresat;

public:
    PlikAdresaci();
    ~PlikAdresaci();

    int getIDostatniegoAdresataWPliku();
    void setIDostatniegoAdresataWPliku(int noweIDostatniegoUzytkownikaWPliku);

    void odczytZPlikuAdresaci(vector<Adresat> &adresaci, int &liczbaAdresatow, int idZalogowanegoUzytkownika);
    void zapisDoPlikuAdresaci(vector<Adresat> &adresaci, int &liczbaAdresatow, int idUsuwanegoAlboEdytowanegoAdresata, char znakStosowanejFunkcjiUsuniecieAlboEdycja, int idZalogowanegoUzytkownika);
    void dodajAdresataDoPlikuAdresaci(Adresat dodawanyAdresat);
};
