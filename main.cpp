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
    // post: s'ha mostrat el menú per cout
    cout << endl;
    cout << "01: Llegir dades" << endl;
    cout << "02: Codi comarca -> municipis" << endl;
    cout << "03: Codi municipi -> establiments" << endl;
    cout << "04: Municipi amb mes establiments" << endl;
    cout << "0: Acabar" << endl;
    cout << "Opcio: ";
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
    int codi;
    cin >> codi;
    mostrarTitol("02: Codi comarca -> municipis");
    cout << "Codi de comarca: " << codi << endl;
    for (const MunicipiResult &m : establiments.municipisPerComarca(codi))
        cout << m.nom << " => " << m.nEstabliments << endl;
}

string formatNumero(const string &numero) {
    // pre: cert
    // post: retorna numero; si comença per dígit, s'omple amb zeros a l'esquerra fins a 5 caràcters
    if (numero.empty() || numero[0] < '0' || numero[0] > '9' || numero.length() >= 5)
        return numero;
    return string(5 - numero.length(), '0') + numero;
}

void opcioEstablimentsPerMunicipi(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de municipi i mostra els seus establiments
    string codi;
    cin >> codi;
    mostrarTitol("03: Codi municipi -> establiments");
    cout << "Codi de municipi: " << codi << endl;
    for (const Establiment &e : establiments.establimentsPerMunicipi(codi))
        cout << e.nom() << " | " << e.carrer() << " | num: " << formatNumero(e.numero())
             << " | Número inscripció: " << e.numInscripcio()
             << " | places: " << e.places() << " | estances: " << e.estances() << endl;
}

void opcioMaximMunicipi(const Establiments &establiments) {
    // pre: cert
    // post: mostra, per cada comarca, el municipi amb més establiments
    mostrarTitol("04: Municipi amb mes establiments");
    for (const MaximMunicipiResult &r : establiments.maximMunicipi())
        cout << r.comarca << " | " << r.municipi << " => " << r.nEstabliments << endl;
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
            default: cout << "Opcio incorrecta" << endl;
        }
        mostrarMenu();
        cin >> opcio;
    }
    return 0;
}
