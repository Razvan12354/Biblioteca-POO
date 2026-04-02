#include <iostream>
#include "Abonati.h"
#include "Carti.h"
#include "Imprumuturi.h"

using namespace std;

int main() {
    cout << "------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    cout << "----- validare CNP si Telefon -----" << endl;
    Abonati ab_invalid1("Chivu", "Rares", "999999", "0722111222", 25, 12); //CNP invalid
    Abonati ab_invalid2("Popescu", "Ana", "123", "0700", 20, 6); // CNP si telefon invalid
    Abonati ab1("Trandafir", "Marius", "1941202415705", "0788776655", 30, 12); //  valid
    cout << "------------------------------------------------------------" << endl;
    cout << "----- Operator<< si scor de incredere -----" << endl;
    cout << ab1 << endl;
    cout << "Scor incredere: " << ab1.scorIncredere() << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "----- Sistem de penalizari -----" << endl;
    ab1.adaugaPenalizare(10.5);
    ab1.platestePenalizare(5.0);
    ab1.prelungireAbonament(6);
    ab1.trecereTimp(2);
    cout << "------------------------------------------------------------" << endl;
    cout << "----- operator= -----" << endl;
    Abonati ab2("Vasile", "Gheorghe", "6020202998877", "0744555666", 40, 10);
    ab2 = ab1;
    cout << "Dupa ab2 = ab1, ab2 este: " << ab2 << endl << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    Carti c1("Ion", "Liviu Rebreanu", "C101", 1920, 2);
    Carti c2("Baltagul", "Mihail Sadoveanu", "C102", 1930, 1);
    
    cout << c1;
    cout << c1.getStocDisponibil() << endl;
    cout << "----- functie prietena afiseazaInfoScurt -----" << endl;
    afiseazaInfoScurt(c1);

    cout << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "----- Verificare poateImprumuta (respinge in caz ca abonatul are datorii / nu are abonament) -----" << endl;
    if (ab1.poateImprumuta()) {
        cout << "Abonatul poate face imprumuturi." << endl;
    } else {
        cout << "Abonatul are datorii/abonamentul expirat." << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "----- Creare imprumut 1 -> scade stocul la Ion de la 2 la 1 -----" << endl;
    Imprumuturi imp1(ab1, c1, "02.04.2026", 14);
    cout << "Stoc Ion dupa imprumut: " << c1.getStocDisponibil() << endl;
    cout << "Carti in posesia lui ab1: " << ab1.getNrCartiImprumutate() << endl << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "----- Returnare cu intarziere -> genereaza penalizari -----" << endl;
    Imprumuturi::setTaxaPenalizare(1.5);
    imp1.finalizeazaImprumut(20);
    
    cout << "Balanta penalizari ab1 dupa intarziere: " << ab1.getBalantaPenalizari() << " RON" << endl;
    cout << "Stoc Ion dupa returnare: " << c1.getStocDisponibil() << endl;
    cout << "Carti in posesia lui ab1: " << ab1.getNrCartiImprumutate() << endl << endl;

    cout << "------------------------------------------------------------" << endl;
    cout << "----- Test stoc epuizat -----" << endl;
    Imprumuturi imp2(ab2, c2, "02.04.2026", 7); // c2 are stoc 1 -> devine 0
    Imprumuturi imp3(ab1, c2, "02.04.2026", 7); // c2 are stoc 0 -> va afisa ATENTIE
    
    // Testare operator= pentru Imprumuturi
    Imprumuturi imp4 = imp2; // Constructor copiere
    imp4 = imp1;            // Operator=
    
    cout << endl << "------------------------------------------------------------" << endl;
    
    return 0;
}