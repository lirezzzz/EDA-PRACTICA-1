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
    // pre: --
    // post: TODO
    size_t llegirDades(const string &path);

    // pre: --
    // post: TODO
    vector<MunicipiResult> municipisPerComarca(int codiComarca) const;

    // pre: --
    // post: TODO
    list<Establiment> establimentsPerMunicipi(const string &codiMunicipi) const;

    // pre: --
    // post: TODO
    MaximMunicipiResults maximMunicipi() const;

private:
    vector<Comarca> a_comarques; // cada comarca conté els seus municipis
};

#endif // ESTABLIMENTS_H
