#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include "Coada.h"
#include "Stiva.h"

class Calculator {
private:
    std::map<std::string, double> variabile;
    static double ultimulRezultat;
    std::string ultimaExpresie;
    const double PI = 3.14159265358979323846;
    std::vector<double> istoric;  // vector 
    int dimensiuneIstoric;
    char* nume;

    int prioritate(char oper);

public:
    Calculator();
    ~Calculator();

    Coada laPostfixat(std::string expr);
    double calculeaza(Coada postfixat);
    double evalueaza(std::string expr);

    static double obtineUltimulRezultat();
    string obtineUltimaExpresie();
    void seteazaUltimaExpresie(std::string expr);
    void stergeSpatii(std::string& str);
    virtual void adaugaInIstoric(double valoare);
    virtual void afiseazaIstoric();

    friend std::istream& operator>>(std::istream& is, Calculator& calc);
    friend std::ostream& operator<<(std::ostream& os, const Calculator& calc);

    bool operator==(const Calculator& calc) const;
    bool operator<(const Calculator& calc) const;
    Calculator operator!() const;

    virtual void seteazaVariabila(std::string nume, double valoare);
    double obtineVariabila(std::string nume);
    virtual void salveazaVariabile(std::string numeFisier);
    virtual void incarcaVariabile(std::string numeFisier);
};

#endif
