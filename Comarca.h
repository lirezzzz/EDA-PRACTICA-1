#ifndef COMARCA_H
#define COMARCA_H

#include <string>
#include <vector>
#include "Municipi.h"

using namespace std;

/// Una comarca amb el vector dels seus municipis.
class Comarca {
public:
    // pre: --
    // post: comarca buida (codi 0, sense nom ni municipis)
    Comarca();

    // pre: codi és el codi IDESCAT de la comarca
    // post: comarca amb el codi i nom indicats i sense municipis
    Comarca(int codi, const string &nom);

    // pre: --
    // post: retorna el codi IDESCAT de la comarca
    int codi() const;

    // pre: --
    // post: retorna el nom de la comarca
    string nom() const;

    // pre: --
    // post: retorna cert si la comarca no té cap municipi
    bool buida() const;

    // pre: --
    // post: retorna els municipis de la comarca
    const vector<Municipi> &municipis() const;

    // pre: el municipi codiMunicipi pertany a aquesta comarca
    // post: e s'ha afegit al final dels establiments del municipi codiMunicipi;
    //       si el municipi no existia, s'ha creat amb el nom nomMunicipi
    void afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                           const Establiment &e);

private:
    int a_codi;                  // Codi Comarca (IDESCAT)
    string a_nom;                // Comarca
    vector<Municipi> a_municipis;
};

#endif // COMARCA_H
