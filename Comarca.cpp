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

int Comarca::cercaDicotomica(const string &codiMunicipi) const {
    int pos;
    return cercaDicotomica(codiMunicipi, pos);
}

int Comarca::cercaDicotomica(const string &codiMunicipi, int &pos) const {
    int esq = 0;
    int dre = int(a_municipis.size()) - 1;
    while (esq <= dre) {
        int mig = esq + (dre - esq) / 2;
        const string &codiMig = a_municipis[mig].codi();
        if (codiMig == codiMunicipi) {
            pos = mig;
            return mig;
        }
        if (codiMig < codiMunicipi) {
            esq = mig + 1;
        } else {
            dre = mig - 1;
        }
    }
    pos = esq;
    return -1;
}

bool Comarca::existeix(const string &codiMunicipi) const {
    return cercaDicotomica(codiMunicipi) != -1;
}

void Comarca::afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                                const Establiment &e) {
 int pos;

  if (cercaDicotomica(codiMunicipi, pos) == -1) // no existeix: pos es on ha d'anar per mantenir l'ordre
  {
    a_municipis.insert(a_municipis.begin() + pos, Municipi(codiMunicipi, nomMunicipi));
  }
  a_municipis[pos].afegirEstabliment(e);
}
