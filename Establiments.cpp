// NOM COGNOMS
// Usuari u1XXXXXXX
// Exercici 1

#include "Establiments.h"
#include "eines.h"
#include <fstream>

// Columnes del CSV que ens interessen (comptant des de 0)
const int COL_NUM_INSCRIPCIO = 1;
const int COL_RETOL = 3;
const int COL_NOM_VIA = 6;
const int COL_NUMERO = 7;
const int COL_MUNICIPI = 13;
const int COL_CODI_MUNICIPI = 14;
const int COL_COMARCA = 15;
const int COL_CODI_COMARCA = 16;
const int COL_PLACES = 24;
const int COL_ESTANCES = 25;

// pre: cert
// post: retorna el número format pels dígits de s (ignora qualsevol altre caràcter); si no n'hi ha cap, retorna 0
static int textANumero(const string &s) {
    int n = 0;
    for (char c : s)
        if (c >= '0' && c <= '9')
            n = n * 10 + (c - '0');
    return n;
}

size_t Establiments::llegirDades(const string &path) {
    a_comarques.clear();
    a_comarques.resize(44);         // una posició per cada codi de comarca (1..43)

    ifstream f(path);
    if (f.fail()) return 0;

    size_t n = 0;
    string linia;
    getline(f, linia);              // capçalera: la descartem
    getline(f, linia);              // primera línia de dades
    while (!f.eof()) {
        vector<string> camps = tokens(linia, ',', true);
        if (camps.size() == 33) {   // descartem línies buides o mal formades
            Establiment e(camps[COL_RETOL], camps[COL_NOM_VIA], camps[COL_NUMERO],
                          camps[COL_NUM_INSCRIPCIO],
                          textANumero(camps[COL_PLACES]), textANumero(camps[COL_ESTANCES]));

            int codiComarca = textANumero(camps[COL_CODI_COMARCA]);
            Comarca &comarca = a_comarques[codiComarca];    // accés directe O(1)
            if (comarca.codi() == 0)                        // primer cop que surt
                comarca = Comarca(codiComarca, camps[COL_COMARCA]);

            comarca.afegirEstabliment(camps[COL_CODI_MUNICIPI], camps[COL_MUNICIPI], e);
            n++;
        }
        getline(f, linia);          // següent línia
    }
    return n;
}

vector<MunicipiResult> Establiments::municipisPerComarca(int codiComarca) const {
    vector<MunicipiResult> resultat;
    // TODO (ordenat pel nom del municipi ascendentment)
    return resultat;
}

list<Establiment> Establiments::establimentsPerMunicipi(const string &codiMunicipi) const {
    list<Establiment> resultat;
    // TODO (en l'ordre del fitxer)
    return resultat;
}

MaximMunicipiResults Establiments::maximMunicipi() const {
    MaximMunicipiResults resultat;
    // TODO (ordenat per nEstabliments descendent; en cas d'empat, pel nom del municipi ascendent)
    return resultat;
}
