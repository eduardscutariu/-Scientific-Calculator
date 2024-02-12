#include "ExtendedCalculator.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

void ExtendedCalculator::adaugaInIstoric(double valoare) {
    cout << "Adaugam " << valoare << " in istoric." << std::endl;
    Calculator::adaugaInIstoric(valoare);
}

void ExtendedCalculator::afiseazaIstoric() {
    cout << "Istoricul este: ";
    Calculator::afiseazaIstoric();
}

void ExtendedCalculator::salveazaVariabile(std::string numeFisier) {
    cout << "Salvam variabilele in fisierul " << numeFisier << "." << std::endl;
    Calculator::salveazaVariabile(numeFisier);
}

void ExtendedCalculator::incarcaVariabile(std::string numeFisier) {
    cout << "Incarcam variabilele din fisierul " << numeFisier << "." << std::endl;
    Calculator::incarcaVariabile(numeFisier);
}
