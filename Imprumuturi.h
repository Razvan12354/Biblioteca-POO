#include <iostream>
#include <cstring>
using namespace std;

class Imprumuturi{
	private:
	char *CNP, *idCarte, *dataImprumut;
	int perioadaZile;
	bool esteReturnata;
	Carti *carteImprumutata;
	Abonati *abonatAsociat;
	static float taxaPenalizarePeZi;
	public:

// Constructor cu parametri
	Imprumuturi(Abonati& a, Carti& c, const char* var_dataImprumut, const int var_perioada){

		this->abonatAsociat = &a;

		this->CNP = new char[strlen(a.getCNP())+1];
		strcpy(this->CNP, a.getCNP());

		this->idCarte = new char[strlen(c.getIdCarte())+1];
		strcpy(this->idCarte, c.getIdCarte());
		this->dataImprumut = new char[strlen(var_dataImprumut)+1];
		strcpy(this->dataImprumut, var_dataImprumut);

		this->esteReturnata = false;

		this->perioadaZile = var_perioada;

		this->carteImprumutata = &c;

		int stocActual = c.getStocDisponibil();
		if (stocActual > 0) {

			c.setStocDisponibil(stocActual - 1);
			int nrCurentCarti = a.getNrCartiImprumutate();
			a.setNrCartiImprumutate(nrCurentCarti + 1);

			cout << "Imprumut realizat cu succes pentru cartea " << c.getTitlu() << " cu ID " << c.getIdCarte() << ". Stoc ramas: " << c.getStocDisponibil() << endl << endl;
		} else {
			cout << "ATENTIE: Stoc epuizat pentru cartea " << c.getTitlu() << " cu ID " << c.getIdCarte() << "! Imprumut realizat FARA stoc." << endl << endl;
		}
	}
	
// Constructor de copiere
	Imprumuturi(const Imprumuturi& nou){
		this->CNP = new char[strlen(nou.CNP)+1];
		strcpy(this->CNP, nou.CNP);

		this->idCarte = new char[strlen(nou.idCarte)+1];
		strcpy(this->idCarte, nou.idCarte);
		this->dataImprumut = new char[strlen(nou.dataImprumut)+1];
		strcpy(this->dataImprumut, nou.dataImprumut);

		this->perioadaZile = nou.perioadaZile;

		this->esteReturnata = nou.esteReturnata;

		this->carteImprumutata = nou.carteImprumutata;

		this->abonatAsociat = nou.abonatAsociat;
	}

// Getters
	inline char* getCNP() const{ return CNP; }
	inline char* getIdCarte() const{ return idCarte; }
	inline char* getDataImprumut() const{ return dataImprumut; }
	inline int getPerioadaZile() const{ return perioadaZile; }

// Setters
	inline void setCNP(const char* CNP){
		delete[] this->CNP;
		this->CNP = new char[strlen(CNP)+1];
		strcpy(this->CNP, CNP);
	}
	inline void setIdCarte(const char* id){
		delete[] this->idCarte;
		this->idCarte = new char[strlen(id)+1];
		strcpy(this->idCarte, id);
	}
	inline void setDataImprumut(const char* data){
		delete[] this->dataImprumut;
		this->dataImprumut = new char[strlen(data)+1];
		strcpy(this->dataImprumut, data);
	}
	inline void setPerioadaZile(const int perioada){ this->perioadaZile = perioada; 
	}

// operator=
	Imprumuturi& operator=(const Imprumuturi& nou){
		delete[] CNP;
		delete[] idCarte;
		delete[] dataImprumut;

		this->CNP = new char[strlen(nou.CNP)+1];
		strcpy(this->CNP, nou.CNP);

		this->idCarte = new char[strlen(nou.idCarte)+1];
		strcpy(this->idCarte, nou.idCarte);
		this->dataImprumut = new char[strlen(nou.dataImprumut)+1];
		strcpy(this->dataImprumut, nou.dataImprumut);

		this->perioadaZile = nou.perioadaZile;

		this->esteReturnata = nou.esteReturnata;

		this->carteImprumutata = nou.carteImprumutata;

		this->abonatAsociat = nou.abonatAsociat;

		return *this;
	}

// Supraincarcarea operatorului << ca functie prietena 
	friend ostream& operator<<(ostream& out, const Imprumuturi& i) {
    out << "Imprumut: " << i.CNP << " a luat '" << i.idCarte 
        << "' la data de " << i.dataImprumut;
    return out;
}
// Finalizare imprumutului fara a specifica zilele scurse
	void finalizeazaImprumut() {
		if (this->esteReturnata == false) {
			this->esteReturnata = true;
			abonatAsociat->setNrCartiImprumutate(abonatAsociat->getNrCartiImprumutate() - 1);
			int stocNou = carteImprumutata->getStocDisponibil() + 1;
			carteImprumutata->setStocDisponibil(stocNou);
			cout << "Cartea cu ID " << idCarte << " a fost returnata in termenul de " << perioadaZile << " zile de catre abonatul cu CNP " << CNP << ". Stoc nou: " << stocNou << endl << endl;
    	}
		else {
			cout << "Cartea cu ID " << idCarte << " a fost deja returnata de catre abonatul cu CNP " << CNP << endl << endl;
		}
	}

// Finalizare imprumutului specificand zilele scurse (SUPRAINCARCARE)
	void finalizeazaImprumut(int zileReale) {
    if (this->esteReturnata == false){
		this->esteReturnata = true;
		abonatAsociat->setNrCartiImprumutate(abonatAsociat->getNrCartiImprumutate() - 1);
		int stocNou = carteImprumutata->getStocDisponibil() + 1;
		carteImprumutata->setStocDisponibil(stocNou);
		cout << "Cartea cu ID " << idCarte << " a fost returnata in termenul de " << zileReale << " zile de catre abonatul cu CNP " << CNP << ". Stoc nou: " << stocNou << endl;
		cout << "Termen stabilit: " << perioadaZile << " zile." << endl;
		if (zileReale > perioadaZile) {
				cout << "Returnare cu INTARZIERE de " << (zileReale - perioadaZile) << " zile!" << endl << endl;
				if (abonatAsociat->scorIncredere() < 50) {
					double penalizare = taxaPenalizarePeZi * (zileReale - perioadaZile);
					cout << "Abonatul are un scor de incredere de " << abonatAsociat->scorIncredere() << ". Penalizare aplicata!" << endl;
				} else {
				double penalizare = 0.75 * taxaPenalizarePeZi * (zileReale - perioadaZile);
				cout << "Abonatul are un scor de incredere de " << abonatAsociat->scorIncredere() << ". Penalizare redusa aplicata!" << endl;
				abonatAsociat->adaugaPenalizare(penalizare);
		} 
	}
		else {
			cout << "Returnare la timp." << endl << endl;
		}
	}
	else {
		cout << "Cartea cu ID " << idCarte << " a fost deja returnata de catre abonatul cu CNP " << CNP << endl << endl;
	}
}

	static void setTaxaPenalizare(float taxa) {
		taxaPenalizarePeZi = taxa;
		cout << "Taxa de penalizare pe zi a fost setata la: " << taxaPenalizarePeZi << " RON." << endl << endl;
	}

	// Destructor
	~Imprumuturi(){
			cout << "Destructor: " << CNP << " " << idCarte << " " << dataImprumut << " " << perioadaZile << endl;
			delete[] CNP;
			delete[] idCarte;
			delete[] dataImprumut;
		}
};

float Imprumuturi::taxaPenalizarePeZi = 0.5;