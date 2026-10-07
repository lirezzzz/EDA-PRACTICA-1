// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef ESTABLIMENT_H
#define ESTABLIMENT_H

#include <string>

using namespace std;

/// Un establiment turístic (una fila del fitxer CSV).
/// Només guardem els camps que necessitem per mostrar-lo a l'opció 03.
class Establiment {
public:
    Establiment();
    // pre: cert
    // post: establiment buit (cadenes buides, places i estances a 0)

    Establiment(const string &nom, const string &carrer, const string &numero,
                const string &numInscripcio, int places, int estances);
    // pre: places >= 0, estances >= 0
    // post: establiment amb les dades indicades

    string nom() const;
    // pre: cert
    // post: retorna el rètol (nom) de l'establiment

    string carrer() const;
    // pre: cert
    // post: retorna el nom de la via (carrer)

    string numero() const;
    // pre: cert
    // post: retorna el número de la via

    string numInscripcio() const;
    // pre: cert
    // post: retorna el número d'inscripció

    int places() const;
    // pre: cert
    // post: retorna el total de places

    int estances() const;
    // pre: cert
    // post: retorna el total d'estances

private:
    string a_nom;           // Rètol
    string a_carrer;        // Nom de la via
    string a_numero;        // Número
    string a_numInscripcio; // Número inscripció
    int a_places;           // Total places
    int a_estances;         // Total estances
};

#endif // ESTABLIMENT_H
