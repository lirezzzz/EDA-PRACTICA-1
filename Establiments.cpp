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

    // Esborrar dades anteriors
    a_comarques.clear();

    ifstream fitxer(path);
    if (!fitxer.is_open()) return 0;

    string linia;
    // Saltar la capçalera
    getline(fitxer, linia);

    size_t filesLlegides = 0;

    while (!fitxer.eof()) {

        vector<string> camps = tokens(linia, ',', true);

        // Places i estances poden venir buides → nombre() ja les tracta (0)
        int places   = nombre(camps[COL_PLACES]);
        int estances = nombre(camps[COL_ESTANCES]);

        Establiment establiment(
            camps[COL_RETOL],
            camps[COL_NOM_VIA],
            camps[COL_NUMERO],
            camps[COL_NUM_INSCRIPCIO],
            places,
            estances
        );

        // Codi de comarca sense stoi
        int codiComarca = nombre(camps[COL_CODI_COMARCA]);

        size_t posComarca = 0;
        while (posComarca < a_comarques.size() &&
               a_comarques[posComarca].codi() != codiComarca) {
            posComarca++;
        }

        if (posComarca == a_comarques.size()) {
            a_comarques.push_back(Comarca(codiComarca, camps[COL_COMARCA]));
        }

        a_comarques[posComarca].afegirEstabliment(
            camps[COL_CODI_MUNICIPI],
            camps[COL_MUNICIPI],
            establiment
        );

        filesLlegides++;
        getline(fitxer, linia)
    }

    return filesLlegides;
}


    // 10. Retornar el nombre de línies llegides
    return filesLlegides;
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
