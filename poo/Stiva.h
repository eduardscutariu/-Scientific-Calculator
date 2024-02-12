#ifndef STIVA_H
#define STIVA_H

#include "Nod.h"
using namespace std;
class Stiva {
private:
    Nod* varf;

public:
    Stiva();

    void adauga(Token date);
    Token scoate();
    Token vede();
    bool esteGoala();
};

#endif


