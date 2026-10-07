// NOM COGNOMS
// Usuari u1XXXXXXX
// Exercici 1

#ifndef ESTABLIMENTS_H
#define ESTABLIMENTS_H

#include <string>
#include <vector>
#include <list>
#include "Comarca.h"

using namespace std;

/// Resultat de l'opció 02: un municipi i el seu nombre d'establiments.
struct MunicipiResult {
    string nom;
    size_t nEstabliments;
};

/// Un element del resultat de l'opció 04.
struct MaximMunicipiResult {
    string comarca;
    string municipi;
    size_t nEstabliments;
};

/// Resultat de l'opció 04: per cada comarca, el municipi amb més establiments.
typedef vector<MaximMunicipiResult> MaximMunicipiResults;

class Establiments {
public:
    size_t llegirDades(const string &path);
    // pre: path és el camí d'un fitxer CSV amb una línia de capçalera, separador ',' i camps entre cometes
    // post: s'han eliminat les dades carregades prèviament i aquest Establiments conté els establiments
    //       del fitxer agrupats per comarca i municipi; retorna el nombre de files de dades llegides
    //       (0 si el fitxer no s'ha pogut obrir)

    vector<MunicipiResult> municipisPerComarca(int codiComarca) const;
    // pre: cert
    // post: TODO

    list<Establiment> establimentsPerMunicipi(const string &codiMunicipi) const;
    // pre: cert
    // post: TODO

    MaximMunicipiResults maximMunicipi() const;
    // pre: cert
    // post: TODO

private:
    vector<Comarca> a_comarques; // cada comarca conté els seus municipis
};

#endif // ESTABLIMENTS_H
