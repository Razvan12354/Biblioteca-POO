#include <iostream>
#include <cstring>
using namespace std;

class Carti{
    private:
    char*titlu, *autor, *editura;
    int anAparitie, nrPagini;
    public:

// Constructor cu parametri
    Carti(const char *var_titlu, const char *var_autor, const char *var_editura, const int var_anAparitie, const int var_nrPagini){
        this->titlu = new char[strlen(var_titlu)+1];
        strcpy(this->titlu,var_titlu);

        this->autor = new char[strlen(var_autor)+1];
        strcpy(this->autor,var_autor);

        this->editura = new char[strlen(var_editura)+1];
        strcpy(this->editura,var_editura);

        this->anAparitie = var_anAparitie;

        this->nrPagini = var_nrPagini;
    }

// Constructor de copiere
    Carti(const Carti& nou){
        this->titlu = new char[strlen(nou.titlu)+1];
        strcpy(titlu,nou.titlu);

        this->autor = new char[strlen(nou.autor)+1];
        strcpy(autor,nou.autor);

        this->editura = new char[strlen(nou.editura)+1];
        strcpy(editura,nou.editura);

        this->anAparitie = nou.anAparitie;

        this->nrPagini = nou.nrPagini;
    }

// Getters
    char* getTitlu() const{
        return titlu;
    }
    char* getAutor() const{
        return autor;
    }
    char* getEditura() const{
        return editura;
    }
    int getAnAparitie() const{
        return anAparitie;
    }
    int getNrPagini() const{
        return nrPagini;
    }

// Setters
    void setTitlu(const char* titlu){
        delete[] this->titlu;
        this->titlu = new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);
    }
    void setAutor(const char* autor){
        delete[] this->autor;
        this->autor = new char[strlen(autor)+1];
        strcpy(this->autor,autor);
    }
    void setEditura(const char* editura){
        delete[] this->editura;
        this->editura = new char[strlen(editura)+1];
        strcpy(this->editura,editura);
    }
    void setAnAparitie(const int anAparitie){
        this->anAparitie = anAparitie;
    }
    void setNrPagini(const int nrPagini){
        this->nrPagini = nrPagini;
    }

// Declarare functie prietena
    friend void afiseazaInfoScurt(const Carti& c);
// Supraincarcarea operatorului << ca functie prietena 
    friend ostream& operator<<(ostream& out, const Carti& c) {
        out<< " " << c.titlu << " " << c.autor << " " << c.editura;
        return out;
    }
// Destructor
    ~Carti(){
        cout<<titlu<<" "<<autor<<" "<<editura<<" "<<anAparitie<<" "<<nrPagini<<endl;
        delete[] titlu;
        delete[] autor;
        delete[] editura;
    }
};
// Implementarea functiei prietene
void afiseazaInfoScurt(const Carti& c) {
    cout << "INFO PRIETENA: " << c.titlu << " a aparut in anul " << c.anAparitie << "." << endl;
}