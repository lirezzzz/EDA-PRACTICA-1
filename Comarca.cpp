#include "Comarca.h"

Comarca::Comarca() : a_codi(0) {}

Comarca::Comarca(int codi, const string &nom) : a_codi(codi), a_nom(nom) {}

int Comarca::codi() const {
    return a_codi;
}

string Comarca::nom() const {
    return a_nom;
}

bool Comarca::buida() const {
    return a_municipis.empty();
}

const vector<Municipi> &Comarca::municipis() const {
    return a_municipis;
}

void Comarca::afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                                const Establiment &e) {
    // TODO: buscar el municipi codiMunicipi dins a_municipis (crear-lo si no hi és)
    //       i afegir-hi l'establiment e
}
