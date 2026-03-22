#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class Imprumuturi{
	private:
	char* numeAbonat, *titluCarte, *dataImprumut;
	int perioadaZile;
	public:

	Imprumuturi(const char* var_nume, const char* var_titlu, const char* var_dataImprumut, const int var_perioada){
		this->numeAbonat = new char[strlen(var_nume)+1];
		strcpy(this->numeAbonat, var_nume);

		this->titluCarte = new char[strlen(var_titlu)+1];
		strcpy(this->titluCarte, var_titlu);

		this->dataImprumut = new char[strlen(var_dataImprumut)+1];
		strcpy(this->dataImprumut, var_dataImprumut);

		this->perioadaZile = var_perioada;
	}

	Imprumuturi(const Imprumuturi& other){
		this->numeAbonat = new char[strlen(other.numeAbonat)+1];
		strcpy(this->numeAbonat, other.numeAbonat);

		this->titluCarte = new char[strlen(other.titluCarte)+1];
		strcpy(this->titluCarte, other.titluCarte);

		this->dataImprumut = new char[strlen(other.dataImprumut)+1];
		strcpy(this->dataImprumut, other.dataImprumut);

		this->perioadaZile = other.perioadaZile;
	}

	char* getNumeAbonat() const{ return numeAbonat; }
	char* getTitluCarte() const{ return titluCarte; }
	char* getDataImprumut() const{ return dataImprumut; }
	int getPerioadaZile() const{ return perioadaZile; }

	void setNumeAbonat(const char* nume){
		delete[] this->numeAbonat;
		this->numeAbonat = new char[strlen(nume)+1];
		strcpy(this->numeAbonat, nume);
	}
	void setTitluCarte(const char* titlu){
		delete[] this->titluCarte;
		this->titluCarte = new char[strlen(titlu)+1];
		strcpy(this->titluCarte, titlu);
	}
	void setDataImprumut(const char* data){
		delete[] this->dataImprumut;
		this->dataImprumut = new char[strlen(data)+1];
		strcpy(this->dataImprumut, data);
	}
	void setPerioadaZile(const int perioada){ this->perioadaZile = perioada; }


	~Imprumuturi(){
		cout << numeAbonat << " " << titluCarte << " " << dataImprumut << " " << perioadaZile << endl;
		delete[] numeAbonat;
		delete[] titluCarte;
		delete[] dataImprumut;
	}
    
    void afiseazaScadenta() const{
        struct tm tm_imprumut = {0};
        int d = 0, m = 0, y = 0;
        struct tm data_struct = {0};
        if (sscanf(dataImprumut, "%d.%d.%d", &d, &m, &y) == 3){
            data_struct.tm_mday = d;
            data_struct.tm_mon = m - 1;
            data_struct.tm_year = y - 1900;

            time_t timp_secunde = mktime(&data_struct);
            timp_secunde += (perioadaZile * 24 * 60 * 60);

            struct tm *data_finala = localtime(&timp_secunde);

            cout << "Carte: " << titluCarte << endl;
            cout << "Data scadentei: " << data_finala->tm_mday << "." << data_finala->tm_mon + 1 << "." << (data_finala->tm_year + 1900) << endl;

            time_t acum = time(0);
            if (acum > timp_secunde) {
                int zile_intarziere = (int)(difftime(acum, timp_secunde) / 86400);
                cout << "Status: Intarziat cu " << zile_intarziere << " zile." << endl;
            } else {
                cout << "Status: In termen." << endl;
            }
        }
    }

    void afiseazaScadenta(int zileBonus) const{
        struct tm tm_imprumut = {0};
        int d = 0, m = 0, y = 0;
        struct tm data_struct = {0};
        if (sscanf(dataImprumut, "%d.%d.%d", &d, &m, &y) == 3){
            data_struct.tm_mday = d + zileBonus;
            data_struct.tm_mon = m - 1;
            data_struct.tm_year = y - 1900;

            time_t timp_secunde = mktime(&data_struct);
            timp_secunde += (perioadaZile * 24 * 60 * 60);

            struct tm *data_finala = localtime(&timp_secunde);

            cout << "Carte: " << titluCarte << endl;
            cout << "Data scadentei: " << data_finala->tm_mday << "." << data_finala->tm_mon + 1 << "." << (data_finala->tm_year + 1900) << endl;

            time_t acum = time(0);
            if (acum > timp_secunde) {
                int zile_intarziere = (int)(difftime(acum, timp_secunde) / 86400);
                cout << "Status: Intarziat cu " << zile_intarziere << " zile." << endl;
            } else {
                cout << "Status: In termen." << endl;
            }
        }
    }

};
