#ifndef ESTABLIMENT_H
#define ESTABLIMENT_H

#include <string>

using namespace std;

/// Un establiment turístic (una fila del fitxer CSV).
/// Només guardem els camps que necessitem per mostrar-lo a l'opció 03.
class Establiment {
public:
    // pre: cert
    // post: establiment buit (cadenes buides, places i estances a 0)
    Establiment();

    // pre: places >= 0, estances >= 0
    // post: establiment amb les dades indicades
    Establiment(const string &nom, const string &carrer, const string &numero,
                const string &numInscripcio, int places, int estances);

    // pre: cert
    // post: retorna el rètol (nom) de l'establiment
    string nom() const;

    // pre: cert
    // post: retorna el nom de la via (carrer)
    string carrer() const;

    // pre: cert
    // post: retorna el número de la via
    string numero() const;

    // pre: cert
    // post: retorna el número d'inscripció
    string numInscripcio() const;

    // pre: cert
    // post: retorna el total de places
    int places() const;

    // pre: cert
    // post: retorna el total d'estances
    int estances() const;

private:
    string a_nom;           // Rètol
    string a_carrer;        // Nom de la via
    string a_numero;        // Número
    string a_numInscripcio; // Número inscripció
    int a_places;           // Total places
    int a_estances;         // Total estances
};

#endif // ESTABLIMENT_H
