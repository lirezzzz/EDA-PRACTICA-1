// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef MUNICIPI_H
#define MUNICIPI_H

#include <string>
#include <list>
#include "Establiment.h"

using namespace std;

/// Un municipi amb la llista dels seus establiments, en l'ordre del fitxer CSV.
class Municipi {
public:
    Municipi();
    // pre: cert
    // post: municipi buit, sense cap establiment

    Municipi(const string &codi, const string &nom);
    // pre: codi és el codi idescat del municipi i nom, el nom del poble
    // post: municipi amb el codi i nom indicats i sense establiments

    string codi() const;
    // pre: cert
    // post: retorna el codi idescat del municipi

    string nom() const;
    // pre: cert
    // post: retorna el nom del municipi

    size_t nEstabliments() const;
    // pre: cert
    // post: retorna el numero d'establiments del municipi

    const list<Establiment> &establiments() const;
    // pre: cert
    // post: retorna la llista d'establiments en l'ordre del fitxer (relatiu, ja es podrà ordenar)

    void afegirEstabliment(const Establiment &e);
    // pre: cert
    // post: e s'ha afegit al final de la llista d'establiments amb un pushback

private:
    string a_codi;                    // Codi Municipi (IDESCAT)
    string a_nom;                     // Municipi
    list<Establiment> a_establiments; // en ordre del fitxer
};

#endif // MUNICIPI_H
