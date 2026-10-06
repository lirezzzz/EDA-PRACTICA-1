#include <algorithm>
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
    getline(f, linia);              
    getline(f, linia);              
    while (!f.eof()) {
        vector<string> camps = tokens(linia, ',', true);
        if (camps.size() == 33) {   // Oriol aixo es perdescartar linees buides o malament formades
            Establiment e(camps[COL_RETOL], 
                        camps[COL_NOM_VIA], 
                        camps[COL_NUMERO],
                        camps[COL_NUM_INSCRIPCIO],
                        textANumero(camps[COL_PLACES]), 
                        textANumero(camps[COL_ESTANCES]));
            int codiComarca = textANumero(camps[COL_CODI_COMARCA]);
            if (a_comarques[codiComarca].codi() == 0)       // primer cop que surt
                a_comarques[codiComarca] = Comarca(codiComarca, camps[COL_COMARCA]);
            a_comarques[codiComarca].afegirEstabliment(camps[COL_CODI_MUNICIPI], camps[COL_MUNICIPI], e);
            n++;
        }
        getline(f, linia);          // següent línia
    }
    return n;
}

vector<MunicipiResult> Establiments::municipisPerComarca(int codiComarca) const {
    vector<MunicipiResult> resultat;
    if (codiComarca < 1 || codiComarca >= (int)a_comarques.size()) return resultat;
    for (const Municipi &m : a_comarques[codiComarca].municipis())
        resultat.push_back({m.nom(), m.nEstabliments()});
    sort(resultat.begin(), resultat.end(),
         [](const MunicipiResult &a, const MunicipiResult &b) { return a.nom < b.nom; });
    return resultat;
}

list<Establiment> Establiments::establimentsPerMunicipi(const string &codiMunicipi) const {
    for (const Comarca &c : a_comarques) {
        int pos = c.cercaDicotomica(codiMunicipi);
        if (pos != -1) return c.municipis()[pos].establiments();
    }
    return list<Establiment>();
}

MaximMunicipiResults Establiments::maximMunicipi() const {
    MaximMunicipiResults resultat;
    for (const Comarca &c : a_comarques) {
        const Municipi *millor = nullptr;
        for (const Municipi &m : c.municipis())
            if (millor == nullptr || m.nEstabliments() >= millor->nEstabliments())
                millor = &m;
        if (millor != nullptr)
            resultat.push_back({c.nom(), millor->nom(), millor->nEstabliments()});
    }
    sort(resultat.begin(), resultat.end(),
         [](const MaximMunicipiResult &a, const MaximMunicipiResult &b) {
             if (a.nEstabliments != b.nEstabliments) return a.nEstabliments > b.nEstabliments;
             return a.municipi < b.municipi;
         });
    return resultat;
}
