#include <iostream>
#include <cstring>
using namespace std;

class Abonati{
    private:
    char*nume, *prenume, *telefon;
    int varsta, durataAbonament, nrCartiImprumutate;
    public:

// Constructor cu parametri
    Abonati(const char *var_nume, const char *var_prenume, const char *var_telefon, const int var_varsta, const int var_durataAbonament, const int var_nrCartiImprumutate){
        this->nume = new char[strlen(var_nume)+1];
        strcpy(this->nume,var_nume);

        this->prenume = new char[strlen(var_prenume)+1];
        strcpy(this->prenume,var_prenume);

        this->telefon = new char[strlen(var_telefon)+1];
        strcpy(this->telefon,var_telefon);
       
        this->varsta = var_varsta;

        this->durataAbonament = var_durataAbonament;

        this->nrCartiImprumutate = var_nrCartiImprumutate;
    }

// Constructor de copiere
    Abonati(const Abonati& nou){
        this->nume = new char[strlen(nou.nume)+1];
        strcpy(nume,nou.nume);

        this->prenume = new char[strlen(nou.prenume)+1];
        strcpy(prenume,nou.prenume);

        this->telefon = new char[strlen(nou.telefon)+1];
        strcpy(telefon,nou.telefon);

        this->varsta = nou.varsta;

        this->durataAbonament = nou.durataAbonament;

        this->nrCartiImprumutate = nou.nrCartiImprumutate;
    }

// Getters
    char* getNume() const{
        return nume;
    }
    char* getPrenume() const{
        return prenume;
    }
    char* getTelefon() const{
        return telefon;
    }
    int getVarsta() const{
        return varsta;
    }
    int getDurataAbonament() const{
        return durataAbonament;
    }
    int getNrCartiImprumutate() const{
        return nrCartiImprumutate;
    }

// Setters
    void setNume(const char* nume){
        delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    void setPrenume(const char* prenume){
        delete[] this->prenume;
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);
    }
    void setTelefon(const char* telefon){
        delete[] this->telefon;
        this->telefon = new char[strlen(telefon)+1];
        strcpy(this->telefon,telefon);
    }
    void setVarsta(const int varsta){
        this->varsta = varsta;
    }
    void setDurataAbonament(const int durataAbonament){
        this->durataAbonament = durataAbonament;
    }
    void setNrCartiImprumutate(const int nrCartiImprumutate){
        this->nrCartiImprumutate = nrCartiImprumutate;
    }
// Verifica daca abonamentul expira in urmatoarea luna
    void alertaReinnoire(){
        if (this -> durataAbonament <= 1)
            cout<<"Abonatul trebuie sa reinnoiasca abonamentul"<<endl;
        else
            cout<<"Abonatul nu trebuie sa reinnoiasca abonamentul"<<endl;
    }

// Calcualre scor de fidelitate pe baza duratei abonamentului, nr. de carti imprumutate si vartei
    void scorIncredere() const {
        double scorIncredere = 0;
        if (durataAbonament > 12) scorIncredere += 40;
        else scorIncredere += (durataAbonament * 3);
        if (nrCartiImprumutate > 10) scorIncredere += 30;
        else scorIncredere += (nrCartiImprumutate * 2);
        if (varsta > 60) scorIncredere += 30;
        else scorIncredere += (varsta * 0.5);
        cout << "Scor incredere: " << scorIncredere << endl;
    }

// Destructor
    ~Abonati(){
        cout<<nume<<" "<<prenume<<" "<<telefon<<" "<<varsta<<" "<<durataAbonament<<" "<<nrCartiImprumutate << endl;
        delete[] nume;
        delete[] prenume;
        delete[] telefon;
    }
};