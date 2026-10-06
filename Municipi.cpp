#include "Municipi.h"

Municipi::Municipi() {}

Municipi::Municipi(const string &codi, const string &nom) : a_codi(codi), a_nom(nom) {}

string Municipi::codi() const { return a_codi; }

string Municipi::nom() const { return a_nom; }

size_t Municipi::nEstabliments() const {
    // TODO
    return 0;
}

const list<Establiment> &Municipi::establiments() const { return a_establiments; }

void Municipi::afegirEstabliment(const Establiment &e) {
    // TODO
}
