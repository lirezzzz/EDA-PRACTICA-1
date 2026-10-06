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

size_t Establiments::llegirDades(const string &path) {
    // TODO: esborrar les dades anteriors, obrir el fitxer, saltar la capçalera,
    //       i per cada línia fer tokens(linia, ',', true) i guardar l'establiment.
    //       Compte: places i estances poden venir buides (valen 0).
    return 0;
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
