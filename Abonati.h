#include <iostream>
#include <cstring>
using namespace std;

class Abonati{
    private:
    char*nume, *prenume, *telefon, *CNP;
    int varsta, durataAbonament, nrCartiImprumutate;
    double balantaPenalizari;
    static int nrTotalAbonati;
    public:

// Constructor cu parametri
    Abonati(const char *var_nume, const char *var_prenume, const char *var_CNP, const char *var_telefon, const int var_varsta, const int var_durataAbonament){
        this->nume = new char[strlen(var_nume)+1];
        strcpy(this->nume,var_nume);

        this->prenume = new char[strlen(var_prenume)+1];
        strcpy(this->prenume,var_prenume);

        if (CNPValid(var_CNP)) {
            this->CNP = new char[14];
            strcpy(this->CNP, var_CNP);
        } else {
            this->CNP = new char[8];
            strcpy(this->CNP, "Invalid");
            cout << "CNP introdus pentru " << var_nume << " este invalid!" << endl << endl;
        }

        if (telefonValid(var_telefon)) {
        this->telefon = new char[strlen(var_telefon) + 1];
        strcpy(this->telefon, var_telefon);
    }
        else {
        this->telefon = new char[8];
        strcpy(this->telefon, "Invalid");
        cout << "Numarul de telefon introdus pentru " << var_nume << " este invalid!" << endl << endl;
    }
       
        this->varsta = var_varsta;

        this->durataAbonament = var_durataAbonament;

        this->nrCartiImprumutate = 0;

        this->balantaPenalizari = 0.0;

        nrTotalAbonati++;
    }

// Constructor de copiere
    Abonati(const Abonati& nou){
        this->nume = new char[strlen(nou.nume)+1];
        strcpy(nume,nou.nume);

        this->prenume = new char[strlen(nou.prenume)+1];
        strcpy(prenume,nou.prenume);

        this->CNP = new char[strlen(nou.CNP)+1];
        strcpy(this->CNP, nou.CNP);

        this->telefon = new char[strlen(nou.telefon)+1];
        strcpy(telefon,nou.telefon);

        this->varsta = nou.varsta;

        this->durataAbonament = nou.durataAbonament;

        this->nrCartiImprumutate = nou.nrCartiImprumutate;

        this->balantaPenalizari = nou.balantaPenalizari;

        nrTotalAbonati++;
    }

// Getters
    inline char* getNume() const{
        return nume;
    }
    inline char* getPrenume() const{
        return prenume;
    }

    inline char* getCNP() const{
        return CNP;
    }

    inline char* getTelefon() const{
        return telefon;
    }
    inline int getVarsta() const{
        return varsta;
    }
    inline int getDurataAbonament() const{
        return durataAbonament;
    }
    inline int getNrCartiImprumutate() const{
        return nrCartiImprumutate;
    }
    static int getNrTotalAbonati() {
        return nrTotalAbonati;
    }
    inline double getBalantaPenalizari() const {
        return balantaPenalizari;
    }

// Setters
    inline void setNume(const char* nume){
        delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    inline void setPrenume(const char* prenume){
        delete[] this->prenume;
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);
    }
    
    inline void setCNP(const char* CNP){
        if (CNPValid(CNP)) {
        delete[] this->CNP;
        this->CNP = new char[strlen(CNP) + 1];
        strcpy(this->CNP, CNP);
    } else {
        cout << "CNP-ul " << CNP << " este invalid. Modificarea nu a fost efectuata." << endl << endl;
    }
    }

    inline void setTelefon(const char* telefon){
        if (telefonValid(telefon)) {
        delete[] this->telefon;
        this->telefon = new char[strlen(telefon) + 1];
        strcpy(this->telefon, telefon);
    } else {
        cout << "Numarul de telefon " << telefon << " este invalid. Modificarea nu a fost efectuata." << endl << endl;
    }
    }
    inline void setVarsta(const int varsta){
        this->varsta = varsta;
    }
    inline void setDurataAbonament(const int durataAbonament){
        this->durataAbonament = durataAbonament;
    }
    inline void setNrCartiImprumutate(const int nrCartiImprumutate){
        this->nrCartiImprumutate = nrCartiImprumutate;
    }

// operator=
Abonati& operator=(const Abonati& nou){
    delete[] nume;
    delete[] prenume;
    delete[] CNP;
    delete[] telefon;

    this->nume = new char[strlen(nou.nume)+1];
    strcpy(nume,nou.nume);

    this->prenume = new char[strlen(nou.prenume)+1];
    strcpy(prenume,nou.prenume);

    this->CNP = new char[strlen(nou.CNP)+1];
    strcpy(this->CNP, nou.CNP);

    this->telefon = new char[strlen(nou.telefon)+1];
    strcpy(this->telefon,nou.telefon);

    this->varsta = nou.varsta;
    this->durataAbonament = nou.durataAbonament;
    this->nrCartiImprumutate = nou.nrCartiImprumutate;
    this->balantaPenalizari = nou.balantaPenalizari;
    
    return *this;
}


// Verificare numar telefon valid
bool telefonValid(const char* tel) {
    if (strlen(tel) != 10) return false;
    for (int i = 0; i < strlen(tel); i++) {
        if (tel[i] < '0' || tel[i] > '9') return false;
    }
    return true;
}

// Verificare CNP valid
bool CNPValid(const char* cnp) {
    if (strlen(cnp) != 13) return false;
        
    for (int i = 0; i < 13; i++) {
        if (cnp[i] < '0' || cnp[i] > '9') return false;
    }

    return true;
}

// Conditie pentru a efectua un imprumut, apelare in main
bool poateImprumuta() const {
    if (balantaPenalizari > 0) return false;
    if (durataAbonament <= 0) return false;
    return true;
}

// Adauga o suma la balanta de penalizare
void adaugaPenalizare(double suma){
    this->balantaPenalizari += suma;
    cout << "Balanta de penalizari a abonatului " << nume << " " << prenume << ", cu CNP " << CNP << ", a fost incarcat cu suma de " << suma << " RON. Balanta de penalizari curenta: " << balantaPenalizari << " RON." << endl << endl;
}

// Scade suma din balanta de penalizare
void platestePenalizare(double suma){
    if (suma > balantaPenalizari) {
        cout << "Suma de " << suma << " RON depaseste balanta de penalizari curenta de " << balantaPenalizari << " RON pentru abonatul " << nume << " " << prenume << ". Plata nu a fost efectuata." << endl << endl;
    } else {
        this->balantaPenalizari -= suma;
        cout << "Abonatul " << nume << " " << prenume << ", cu CNP " << CNP << ", a efectuat o plata de " << suma << " RON. Balanta de penalizari curenta: " << balantaPenalizari << " RON." << endl << endl;
    }
}


// Calcualre scor de fidelitate pe baza duratei abonamentului, nr. de carti imprumutate si varstei
double scorIncredere() const {
    double scorIncredere = 0;
    if (durataAbonament > 12) scorIncredere += 40;
    else scorIncredere += (durataAbonament * 3);

    if (nrCartiImprumutate > 0) scorIncredere += 30 - nrCartiImprumutate;
    else scorIncredere += 0;

    if (varsta > 60) scorIncredere += 30;
    else scorIncredere += (varsta * 0.5);

    return scorIncredere;
}

// Pelungire abonament cu un numar de luni
void prelungireAbonament(int luni){
    durataAbonament += luni;
    cout << "Abonatului " << nume << " " << prenume << " i-a fost prelungita durata abonamentului cu " << luni << " luni." << endl;
    cout << "Durata curenta a abonamentului: " << durataAbonament << " luni." << endl << endl;
}

// Scadere luni din durata abonamentului
void trecereTimp(int luni) {
    if (this->durataAbonament >= luni) {
        this->durataAbonament -= luni;
        cout << "Au trecut " << luni << " luni, iar durata abonamentului pentru " << nume << " " << prenume << " a fost scazuta la " << durataAbonament << " luni." << endl;
    } else {
        this->durataAbonament = 0;
        cout << "Au trecut " << luni << " luni, dar durata abonamentului pentru " << nume << " " << prenume << " era sub numarul de luni indicat. Abonament scazut la 0." << endl;
    }

    if (this->durataAbonament == 0 && this->nrCartiImprumutate > 0) {
        double penalizareExtra = 10 * this->nrCartiImprumutate;
        this->adaugaPenalizare(penalizareExtra);
        cout << "Abonament expirat cu " << nrCartiImprumutate << " carti nereturnate!" << endl;
        cout << "S-a aplicat o penalizare de " << penalizareExtra << " RON." << endl << endl;
    }

    cout << "Noul scor de incredere: " << this->scorIncredere() << "/100" << endl;
    cout << "---------------------------------------" << endl << endl;
}

// Supraincarcarea operatorului << ca functie prietena 
friend ostream& operator<<(ostream& out, const Abonati& a) {
    out << "Abonat: " << a.nume << " " << a.prenume 
        << " (Varsta: " << a.varsta << ", Carti: " << a.nrCartiImprumutate << ")";
    return out;
}


// Destructor
    ~Abonati(){
        cout<<"Destructor: "<<nume<<" "<<prenume<<" "<<CNP<<" "<<telefon<<" "<<varsta<<" "<<durataAbonament<<" "<<nrCartiImprumutate << endl;
        delete[] nume;
        delete[] prenume;
        delete[] telefon;
        delete[] CNP;
        nrTotalAbonati--;
    }
};

int Abonati::nrTotalAbonati = 0;