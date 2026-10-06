#ifndef ESTABLIMENTS_H
#define ESTABLIMENTS_H


using namespace std;

class Establiments {
public:
    size_t llegirDades(const string &path);
    vector<MunicipiResult> municipisPerComarca(int codiComarca) const;
    list<Establiment> establimentsPerMunicipi(const string &codiMunicipi) const;
    MaximMunicipiResults maximMunicipi() const;

private:

};

#endif
