#include "Token.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

Token::Token() : tip(NUMAR), valoare(0), oper('\0') {}

Token::Token(double valoare) : tip(NUMAR), valoare(valoare), oper('\0') {}

Token::Token(char oper) : tip(OPERATOR), valoare(0), oper(oper) {}

TipToken Token::obtineTip() { return tip; }

double Token::obtineValoare() { return valoare; }

char Token::obtineOperator() { return oper; }

double& Token::operator[](int index) {
    if (index == 0) {
        return valoare;
    }
    else {
        throw "Index in afara limitelor";
    }
}

