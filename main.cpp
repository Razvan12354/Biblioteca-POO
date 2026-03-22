#include <iostream>
#include "Abonati.h"
#include "Carti.h"
#include "Imprumuturi.h"

using namespace std;

int main() {
    Abonati ab1("Popescu", "Ion", "0722111222", 25, 10, 2);
    cout << "Nume: " << ab1.getNume() << " " << ab1.getPrenume() << endl;

    ab1.setVarsta(65);
    ab1.setDurataAbonament(2);

    ab1.alertaReinnoire();
    ab1.scorIncredere();

    Abonati ab2 = ab1; 
    cout << "Copie abonat creat cu succes." << endl;

    Carti c1("Mara", "Ioan Slavici", "Editura Litera", 1906, 320);

    cout << "Carte: " << c1.getTitlu() << " de " << c1.getAutor() << endl;

    c1.setAnAparitie(2020);
    c1.setEditura("Art");

    Carti c2 = c1;

    Imprumuturi imp1(ab1.getNume(), c1.getTitlu(), "15.03.2024", 14);

    cout << "Data imprumut: " << imp1.getDataImprumut() << endl;

    imp1.setPerioadaZile(21);

    imp1.afiseazaScadenta();

    imp1.afiseazaScadenta(5);

    Imprumuturi imp2 = imp1;

    cout << c1 << endl;

    afiseazaInfoScurt(c1);


    return 0;
}