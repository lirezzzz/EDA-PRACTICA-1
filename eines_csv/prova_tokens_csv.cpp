#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "eines.h"

using namespace std;

int main() {
   ifstream f;
   string linia;
   vector<string> items;
   string fitxer = "prova_tokens.csv";
   f.open(fitxer);
   if (!f.fail()) {
      getline(f, linia);
      while (!f.eof()) {
         items = tokens(linia, ';', false);
         cout << linia << endl;
         for (auto i : items) {
            cout << "\t[" << i << "]" << endl;
         }
         getline(f, linia);
      }
   }
   return 0;
}
