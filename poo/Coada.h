#ifndef COADA_H
#define COADA_H

#include "Nod.h"
using namespace std;
class Coada {
private:
    Nod* fata;
    Nod* spate;

public:
    Coada();

    void adauga(Token date);
    Token scoate();
    Token vede();
    bool esteGoala();
};

#endif


