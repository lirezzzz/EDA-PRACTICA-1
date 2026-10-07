// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef MUNICIPIRESULT_H
#define MUNICIPIRESULT_H

#include <string>

using namespace std;

/// Resultat de l'opció 02: un municipi i el seu nombre d'establiments.
class MunicipiResult {
public:
    MunicipiResult(const string &nom, size_t nEstabliments);
    // pre: cert
    // post: resultat amb el nom del municipi i el seu nombre d'establiments

    string nom() const;
    // pre: cert
    // post: retorna el nom del municipi

    size_t nEstabliments() const;
    // pre: cert
    // post: retorna el nombre d'establiments del municipi

private:
    string a_nom;
    size_t a_nEstabliments;
};

#endif // MUNICIPIRESULT_H
