// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#include "MunicipiResult.h"

MunicipiResult::MunicipiResult(const string &nom, size_t nEstabliments)
    : a_nom(nom), a_nEstabliments(nEstabliments) {}

string MunicipiResult::nom() const {
    return a_nom;
}

size_t MunicipiResult::nEstabliments() const {
    return a_nEstabliments;
}
