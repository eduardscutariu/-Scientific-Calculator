#ifndef ABSTRACTCALCULATOR_H
#define ABSTRACTCALCULATOR_H

#include <string>

class AbstractCalculator {
public:
    virtual double evalueaza(std::string expr) = 0;  //metoda pur virtuala
};

#endif
