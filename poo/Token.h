#ifndef TOKEN_H
#define TOKEN_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
enum TipToken { NUMAR, OPERATOR };

class Token {
public:
    TipToken tip;
    char oper;
    double valoare;

    Token();
    Token(double valoare);
    Token(char oper);

    TipToken obtineTip();
    double obtineValoare();
    char obtineOperator();

    double& operator[](int idex);
};

#endif

