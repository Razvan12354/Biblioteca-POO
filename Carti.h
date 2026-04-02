#include <iostream>
#include <cstring>
using namespace std;

class Carti{
    private:
    char*titlu, *autor, *idCarte;
    int anAparitie, stocDisponibil;
    static int nrTotalCarti;
    public:

// Constructor cu parametri
    Carti(const char *var_titlu, const char *var_autor, const char *var_idCarte, const int var_anAparitie, const int var_stocDisponibil){
        this->titlu = new char[strlen(var_titlu)+1];
        strcpy(this->titlu,var_titlu);

        this->autor = new char[strlen(var_autor)+1];
        strcpy(this->autor,var_autor);

        this->idCarte = new char[strlen(var_idCarte)+1];
        strcpy(this->idCarte,var_idCarte);

        this->anAparitie = var_anAparitie;

        this->stocDisponibil = var_stocDisponibil;

        nrTotalCarti++;
    }

// Constructor de copiere
    Carti(const Carti& nou){
        this->titlu = new char[strlen(nou.titlu)+1];
        strcpy(titlu,nou.titlu);

        this->autor = new char[strlen(nou.autor)+1];
        strcpy(autor,nou.autor);

        this->idCarte = new char[strlen(nou.idCarte)+1];
        strcpy(idCarte,nou.idCarte);

        this->anAparitie = nou.anAparitie;

        this->stocDisponibil = nou.stocDisponibil;

        nrTotalCarti++;
    }
    

// Getters
    inline char* getTitlu() const{
        return titlu;
    }
    inline char* getAutor() const{
        return autor;
    }
    inline char* getIdCarte() const{
        return idCarte;
    }
    inline int getAnAparitie() const{
        return anAparitie;
    }
    inline int getStocDisponibil() const{
        return stocDisponibil;
    }
    inline static int getNrTotalCarti() {
         return nrTotalCarti; 
    }

// Setters
    inline void setTitlu(const char* titlu){
        delete[] this->titlu;
        this->titlu = new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);
    }
    inline void setAutor(const char* autor){
        delete[] this->autor;
        this->autor = new char[strlen(autor)+1];
        strcpy(this->autor,autor);
    }
    inline void setIdCarte(const char* id){
        delete[] this->idCarte;
        this->idCarte = new char[strlen(id)+1];
        strcpy(this->idCarte,id);
    }
    inline void setAnAparitie(const int anAparitie){
        this->anAparitie = anAparitie;
    }
    inline void setStocDisponibil(const int stocDisponibil){
        this->stocDisponibil = stocDisponibil;
    }

// operator=
    Carti& operator=(const Carti& nou){
        delete[] titlu;
        delete[] autor;
        delete[] idCarte;

        this->titlu = new char[strlen(nou.titlu)+1];
        strcpy(titlu,nou.titlu);

        this->autor = new char[strlen(nou.autor)+1];
        strcpy(autor,nou.autor);

        this->idCarte = new char[strlen(nou.idCarte)+1];
        strcpy(idCarte,nou.idCarte);

        this->anAparitie = nou.anAparitie;

        this->stocDisponibil = nou.stocDisponibil;

        return *this;
    }

// Declarare functie prietena
    friend void afiseazaInfoScurt(const Carti& c);
    
// Supraincarcarea operatorului << ca functie prietena 
    friend ostream& operator<<(ostream& out, const Carti& c) {
        out<< " " << c.titlu << " " << c.autor << " " << c.anAparitie << " " << c.stocDisponibil;
        return out;
    }

// Destructor
    ~Carti(){
        cout << "Destructor: " << titlu <<" " << autor << " " << anAparitie << " " << stocDisponibil << endl;
        delete[] titlu;
        delete[] autor;
        delete[] idCarte;
        nrTotalCarti--;
    }
};
// Implementarea functiei prietene
void afiseazaInfoScurt(const Carti& c) {
    cout << c.titlu << " a aparut in anul " << c.anAparitie << "." << endl;
}

int Carti::nrTotalCarti = 0;