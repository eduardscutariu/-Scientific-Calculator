#include "Nod.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
Nod::Nod(Token date) {
    this->date = date;
    this->urmator = NULL;
}

Token Nod::obtineDate() { return date; }

Nod* Nod::obtineUrmator() { return urmator; }

void Nod::seteazaUrmator(Nod* urmator) { this->urmator = urmator; }

Nod& Nod::operator++() {
    if (date.obtineTip() == NUMAR) {
        double nouaValoare = date.obtineValoare() + 1;
        date = Token(nouaValoare);
    }
    return *this;
}

Nod Nod::operator++(int) {
    Nod temp = *this;
    ++*this;
    return temp;
}
