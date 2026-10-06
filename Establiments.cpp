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
    a_comarques.resize(44);

    size_t n = 0;
    ifstream f(path);
    if (f.fail()) return 0;

    string linia;
    getline(f, linia); // capçalera
    getline(f, linia);
    while (!f.eof()) {
        string numInscripcio, retol, nomVia, numero, municipi, codiMunicipi, comarca;
        int codiComarca = 0, places = 0, estances = 0;

        long primer = 0, ultim = 0;
        int col = 0;
        while (ultim != string::npos) {
            string t = token(linia, ',', true, primer, ultim);
            if (col == COL_NUM_INSCRIPCIO) numInscripcio = t;
            else if (col == COL_RETOL) retol = t;
            else if (col == COL_NOM_VIA) nomVia = t;
            else if (col == COL_NUMERO) numero = t;
            else if (col == COL_MUNICIPI) municipi = t;
            else if (col == COL_CODI_MUNICIPI) codiMunicipi = t;
            else if (col == COL_COMARCA) comarca = t;
            else if (col == COL_CODI_COMARCA) codiComarca = textANumero(t);
            else if (col == COL_PLACES) places = textANumero(t);
            else if (col == COL_ESTANCES) estances = textANumero(t);
            col++;
        }

        if (col == 33) {
            Establiment e(retol, nomVia, numero, numInscripcio, places, estances);
            if (a_comarques[codiComarca].codi() == 0)
                a_comarques[codiComarca] = Comarca(codiComarca, comarca);
            a_comarques[codiComarca].afegirEstabliment(codiMunicipi, municipi, e);
            n++;
        }
        getline(f, linia);
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
