// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#include "Establiment.h"

Establiment::Establiment() : a_places(0), a_estances(0) {}

Establiment::Establiment(const string &nom, const string &carrer, const string &numero,
                         const string &numInscripcio, int places, int estances)
    : a_nom(nom), a_carrer(carrer), a_numero(numero),
      a_numInscripcio(numInscripcio), a_places(places), a_estances(estances) {}

string Establiment::nom() const {
    return a_nom;
}

string Establiment::carrer() const {
    return a_carrer;
}

string Establiment::numero() const {
    return a_numero;
}

string Establiment::numInscripcio() const {
    return a_numInscripcio;
}

int Establiment::places() const {
    return a_places;
}

int Establiment::estances() const {
    return a_estances;
}
