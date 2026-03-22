#include <iostream>
#include "Abonati.h"
#include "Carti.h"
#include "Imprumuturi.h"

using namespace std;

int main() {
    // =====TESTARE CLASA ABONATI=====
    // Instantierea unui obiect folosind constructorul cu parametri
    Abonati ab1("Popescu", "Ion", "0722111222", 25, 10, 2);
    
    // Testare Getters
    cout << "Nume: " << ab1.getNume() << " " << ab1.getPrenume() << endl;

    // Testare metode de modificare (Setters)
    ab1.setVarsta(65);
    ab1.setDurataAbonament(2);

    // Apelarea functiilor clasei Abonati
    ab1.alertaReinnoire();
    ab1.scorIncredere();

    // Testare constructor de copiere
    Abonati ab2 = ab1; 
    cout << "Copie abonat creat cu succes." << endl;

    // =====TESTARE CLASA CARTI=====
    Carti c1("Mara", "Ioan Slavici", "Editura Litera", 1906, 320);

    cout << "Carte: " << c1.getTitlu() << " de " << c1.getAutor() << endl;

    // Modificarea atributelor prin Setters
    c1.setAnAparitie(2020);
    c1.setEditura("Art");

    // Testare constructor de copiere
    Carti c2 = c1;

    // Testare operatorul <<
    cout << "Afisare obiect folosind operator<< : " << c1 << endl;

    // Testare functie prietena
    afiseazaInfoScurt(c1);

    // =====TESTARE CLASA IMPRUMUTURI=====
    // Crearea unui imprumut folosind date din obiectele anterioare
    Imprumuturi imp1(ab1.getNume(), c1.getTitlu(), "15.03.2024", 14);

    cout << "Data imprumut: " << imp1.getDataImprumut() << endl;

    // Modificare perioada de imprumut
    imp1.setPerioadaZile(21);

    // 1. Apel fara parametri
    imp1.afiseazaScadenta();

    // 2. Apel cu parametru de zile bonus
    imp1.afiseazaScadenta(5);

    // Testare constructor de copiere pentru imprumuturi
    Imprumuturi imp2 = imp1;

    return 0;
}