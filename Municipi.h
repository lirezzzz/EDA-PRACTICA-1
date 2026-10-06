#ifndef MUNICIPI_H
#define MUNICIPI_H

#include <string>
#include <list>
#include "Establiment.h"

using namespace std;

/// Un municipi amb la llista dels seus establiments,
/// en l'ordre relatiu en què apareixen al fitxer CSV.
class Municipi {
public:
    // pre: --
    // post: municipi buit, sense establiments
    Municipi();

    // pre: codi és el codi IDESCAT del municipi
    // post: municipi amb el codi i nom indicats i sense establiments
    Municipi(const string &codi, const string &nom);

    // pre: --
    // post: retorna el codi IDESCAT del municipi
    string codi() const;

    // pre: --
    // post: retorna el nom del municipi
    string nom() const;

    // pre: --
    // post: retorna el nombre d'establiments del municipi
    size_t nEstabliments() const;

    // pre: --
    // post: retorna la llista d'establiments en l'ordre del fitxer
    const list<Establiment> &establiments() const;

    // pre: --
    // post: e s'ha afegit al final de la llista d'establiments
    void afegirEstabliment(const Establiment &e);

private:
    string a_codi;                    // Codi Municipi (IDESCAT)
    string a_nom;                     // Municipi
    list<Establiment> a_establiments; // en ordre del fitxer
};

#endif // MUNICIPI_H
