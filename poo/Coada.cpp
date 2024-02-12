#include "Coada.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
Coada::Coada() {
    fata = spate = NULL;
}

void Coada::adauga(Token date) {
    Nod* nodNou = new Nod(date);
    if (spate == NULL) {
        fata = spate = nodNou;
        return;
    }
    spate->seteazaUrmator(nodNou);
    spate = nodNou;
}

Token Coada::scoate() {
    if (fata != NULL) {
        Token date = fata->obtineDate();
        Nod* temp = fata;
        fata = fata->obtineUrmator();
        if (fata == NULL) {
            spate = NULL;
        }
        delete temp;
        return date;
    }
    else {
        throw "Coada este goala";
    }
}

Token Coada::vede() {
    if (fata != NULL) {
        return fata->obtineDate();
    }
    else {
        throw "Coada este goala";
    }
}

bool Coada::esteGoala() {
    return fata == NULL;
}
