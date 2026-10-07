// Diego Cortés i Oriol Sala
// Usuari u6112490
// Exercici 1

#include "Municipi.h"

Municipi::Municipi() {}

Municipi::Municipi(const string &codi, const string &nom) : a_codi(codi), a_nom(nom) {}

string Municipi::codi() const { 
    return a_codi; 
}

string Municipi::nom() const { 
    return a_nom; 
}

size_t Municipi::nEstabliments() const {
    return a_establiments.size();
}

const list<Establiment> &Municipi::establiments() const { 
    return a_establiments; 
}

void Municipi::afegirEstabliment(const Establiment &e) {
    a_establiments.push_back(e);
    
}
