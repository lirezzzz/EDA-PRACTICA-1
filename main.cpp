// NOM COGNOMS
// Usuari u1XXXXXXX
// Exercici 1

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Establiments.h"

using namespace std;

void mostrarTitol(const string &titol) {
    // pre: cert
    // post: s'ha mostrat per cout el títol emmarcat amb asteriscs
    string linia(titol.length() + 4, '*');
    cout << linia << endl;
    cout << "* " << titol << " *" << endl;
    cout << linia << endl;
}

void mostrarMenu() {
    // pre: cert
    // post: s'ha mostrat el menú per cerr (no forma part de la sortida)
    cerr << endl;
    cerr << "01: Llegir dades" << endl;
    cerr << "02: Codi comarca -> municipis" << endl;
    cerr << "03: Codi municipi -> establiments" << endl;
    cerr << "04: Municipi amb mes establiments" << endl;
    cerr << "0: Acabar" << endl;
    cerr << "Opcio: ";
}

void opcioLlegirDades(Establiments &establiments) {
    // pre: cert
    // post: llegeix el path del fitxer CSV, el carrega a establiments i mostra el nombre de línies llegides
    string path;
    cin >> path;
    size_t n = establiments.llegirDades(path);
    mostrarTitol("01: Llegir dades");
    cout << "Numero de linies: " << n << endl;
}

void opcioMunicipisPerComarca(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de comarca i mostra els seus municipis amb el nombre d'establiments
    // TODO
}

void opcioEstablimentsPerMunicipi(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de municipi i mostra els seus establiments
    // TODO
}

void opcioMaximMunicipi(const Establiments &establiments) {
    // pre: cert
    // post: mostra, per cada comarca, el municipi amb més establiments
    MaximMunicipiResults resultat = establiments.maximMunicipi();
    mostrarTitol("04: Municipi amb mes establiments");
    for (size_t i = 0; i < resultat.size(); i++)
        cout << resultat[i].comarca << " | " << resultat[i].municipi << " => "
             << resultat[i].nEstabliments << endl;
}

int main() {
    Establiments establiments;
    int opcio;

    mostrarMenu();
    cin >> opcio;
    while (opcio != 0) {
        switch (opcio) {
            case 1: opcioLlegirDades(establiments); break;
            case 2: opcioMunicipisPerComarca(establiments); break;
            case 3: opcioEstablimentsPerMunicipi(establiments); break;
            case 4: opcioMaximMunicipi(establiments); break;
            default: cerr << "Opcio incorrecta" << endl;
        }
        mostrarMenu();
        cin >> opcio;
    }
    return 0;
}
