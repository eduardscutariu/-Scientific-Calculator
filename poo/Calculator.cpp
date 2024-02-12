#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;



double Calculator::ultimulRezultat = 0.0;

Calculator::Calculator() : dimensiuneIstoric(0), nume(new char[11]) {
    strcpy(nume, "Calculator");
}


int Calculator::prioritate(char oper) {
    switch (oper) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
    case '#':
        return 3;
    default:
        return -1;
    }
}

Coada Calculator::laPostfixat(std::string expr) {
    stergeSpatii(expr);
    Stiva oper;
    Coada rezultat;
    for (size_t i = 0; i < expr.length(); i++) {
        if (isdigit(expr[i]) || expr[i] == '.') {
            string numStr;
            int dotCount = 0;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    dotCount++;
                    if (dotCount > 1) {
                        throw "Numar invalid";
                    }
                }
                numStr += expr[i++];
            }
            i--;
            rezultat.adauga(Token(stod(numStr)));
        }

        else if (isalpha(expr[i])) {
            string varName;
            while (i < expr.length() && isalpha(expr[i])) {
                varName += expr[i++];
            }
            i--;
            if (variabile.count(varName) > 0) {
                rezultat.adauga(Token(variabile[varName]));
            }
            else {
                throw "Variabila nu exista";
            }
        }
        else if (expr[i] == '(' || expr[i] == '[') {
            oper.adauga(Token(expr[i]));
        }
        else if (expr[i] == ')' || expr[i] == ']') {
            while (!oper.esteGoala() && oper.vede().oper != '(' && oper.vede().oper != '[') {
                rezultat.adauga(Token(oper.scoate()));
            }
            if (oper.esteGoala()) {
                throw "Paranteze sau paranteze drepte nepotrivite";
            }
            oper.scoate();
        }
        else {
            while (!oper.esteGoala() && oper.vede().oper != '(' && oper.vede().oper != '[' &&
                prioritate(oper.vede().oper) >= prioritate(expr[i])) {
                rezultat.adauga(Token(oper.scoate()));
            }
            oper.adauga(Token(expr[i]));
        }
    }
    while (!oper.esteGoala()) {
        rezultat.adauga(Token(oper.scoate()));
    }

    return rezultat;
}

double Calculator::calculeaza(Coada postfixat) {
    Stiva valori;
    while (!postfixat.esteGoala()) {
        Token token = postfixat.scoate();
        if (token.tip == NUMAR) {
            valori.adauga(token);
        }
        else {
            double valoare1 = valori.scoate().valoare;
            double valoare2 = valori.scoate().valoare;
            switch (token.oper) {
            case '+':
                valori.adauga(Token(valoare2 + valoare1));
                break;
            case '-':
                valori.adauga(Token(valoare2 - valoare1));
                break;
            case '*':
                valori.adauga(Token(valoare2 * valoare1));
                break;
            case '/':
                if (valoare1 == 0) {
                    throw "Impartire la zero";
                }
                valori.adauga(Token(valoare2 / valoare1));
                break;
            case '^':
                valori.adauga(Token(pow(valoare2, valoare1)));
                break;
            case '#':
                valori.adauga(Token(pow(valoare2, 1 / valoare1)));
                break;
            }
        }
    }
    double rezultat = valori.vede().valoare;
    if (rezultat == 0) {
        rezultat = 0;
    }
    return rezultat;
}

double Calculator::evalueaza(std::string expr) {
    Coada postfixat = laPostfixat(expr);
    ultimulRezultat = calculeaza(postfixat);
    return ultimulRezultat;
}
double Calculator::obtineUltimulRezultat() {
    return ultimulRezultat;
}

string Calculator::obtineUltimaExpresie() {
    return this->ultimaExpresie;
}

void Calculator::seteazaUltimaExpresie(std::string expr) {
    if (expr.empty()) {
        throw "Expresia nu poate fi goala";
    }
    this->ultimaExpresie = expr;
}

void Calculator::stergeSpatii(std::string& str) {
    string nouaExpr;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            nouaExpr += str[i];
        }
    }
    str = nouaExpr;
}

void Calculator::adaugaInIstoric(double valoare) {
    istoric.push_back(valoare);
}

void Calculator::afiseazaIstoric() {
    for (double valoare : istoric) {
        cout << valoare << endl;
    }
}

istream& operator>>(std::istream& is, Calculator& calc) {
    string expr;
    getline(is, expr);
    calc.seteazaUltimaExpresie(expr);
    return is;
}

ostream& operator<<(std::ostream& os, const Calculator& calc) {
    os << "Calculator: " << calc.nume << ", Ultima Expresie: " << calc.ultimaExpresie << ", Ultimul Rezultat: " << calc.ultimulRezultat;
    return os;
}

bool Calculator::operator==(const Calculator& calc) const {
    return this->ultimaExpresie == calc.ultimaExpresie;
}

bool Calculator::operator<(const Calculator& calc) const {
    return this->ultimulRezultat < calc.ultimulRezultat;
}

Calculator Calculator::operator!() const {
    Calculator rezultat = *this;
    rezultat.ultimulRezultat = -ultimulRezultat;
    return rezultat;
}
Calculator::~Calculator() {
    if (nume) {
        delete[] nume;
    }
}

void Calculator::seteazaVariabila(std::string nume, double valoare) {
    variabile[nume] = valoare;
}

double Calculator::obtineVariabila(std::string nume) {
    if (variabile.count(nume) > 0) {
        return variabile[nume];
    }
    else {
        throw "Variabila nu exista";
    }
}

void Calculator::salveazaVariabile(std::string numeFisier) {
    ofstream fisier(numeFisier, ios::binary);
    for (const auto& pereche : variabile) {
        size_t lungime = pereche.first.size();
        fisier.write(reinterpret_cast<const char*>(&lungime), sizeof(lungime));
        fisier.write(pereche.first.c_str(), lungime);
        fisier.write(reinterpret_cast<const char*>(&pereche.second), sizeof(double));
    }
    fisier.close();
}

void Calculator::incarcaVariabile(std::string numeFisier) {
    ifstream fisier(numeFisier, ios::binary);
    while (fisier.peek() != EOF) {
        size_t lungime;
        fisier.read(reinterpret_cast<char*>(&lungime), sizeof(lungime));
        string nume(lungime, ' ');
        fisier.read(&nume[0], lungime);
        double valoare;
        fisier.read(reinterpret_cast<char*>(&valoare), sizeof(double));
        variabile[nume] = valoare;
    }
    fisier.close();
}

