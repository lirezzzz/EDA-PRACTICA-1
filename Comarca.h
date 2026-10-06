#ifndef COMARCA_H
#define COMARCA_H

#include <string>
#include <vector>
#include "Municipi.h"
#include "Establiment.h"

using namespace std;

/// Una comarca amb el vector dels seus municipis.
class Comarca {
public:
    Comarca();
    // pre: cert
    // post: comarca buida (codi 0, sense nom ni municipis)

    Comarca(int codi, const string &nom);
    // pre: codi és el codi IDESCAT de la comarca
    // post: comarca amb el codi i nom indicats i sense municipis

    int codi() const;
    // pre: cert
    // post: retorna el codi IDESCAT de la comarca

    string nom() const;
    // pre: cert
    // post: retorna el nom de la comarca

    bool buida() const;
    // pre: cert
    // post: retorna cert si la comarca no té cap municipi

    const vector<Municipi> &municipis() const;
    // pre: cert
    // post: retorna els municipis de la comarca

    void afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                           const Establiment &e);
    // pre: el municipi codiMunicipi pertany a aquesta comarca
    // post: e s'ha afegit al final dels establiments del municipi codiMunicipi;
    //       si el municipi no existia, s'ha creat amb el nom nomMunicipi

private:
    int a_codi;                  // Codi Comarca (IDESCAT)
    string a_nom;                // Comarca
    vector<Municipi> a_municipis;
};

#endif // COMARCA_H
