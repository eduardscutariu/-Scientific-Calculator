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

#ifndef EXTENDEDCALCULATOR_H
#define EXTENDEDCALCULATOR_H

#include "Calculator.h"

class ExtendedCalculator : public Calculator {
public:
    void adaugaInIstoric(double valoare) override;
    void afiseazaIstoric() override;
    void salveazaVariabile(std::string numeFisier) override;
    void incarcaVariabile(std::string numeFisier) override;
};

#endif


