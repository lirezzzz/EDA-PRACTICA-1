// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef MAXIMMUNICIPIRESULT_H
#define MAXIMMUNICIPIRESULT_H

#include <string>

using namespace std;

/// Un element del resultat de l'opció 04: el municipi amb més establiments d'una comarca.
class MaximMunicipiResult {
public:
    MaximMunicipiResult(const string &comarca, const string &municipi, size_t nEstabliments);
    // pre: cert
    // post: resultat amb el nom de la comarca, el del municipi i el seu nombre d'establiments

    string comarca() const;
    // pre: cert
    // post: retorna el nom de la comarca

    string municipi() const;
    // pre: cert
    // post: retorna el nom del municipi

    size_t nEstabliments() const;
    // pre: cert
    // post: retorna el nombre d'establiments del municipi

private:
    string a_comarca;
    string a_municipi;
    size_t a_nEstabliments;
};

#endif // MAXIMMUNICIPIRESULT_H
