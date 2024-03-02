#include "Round.h"
#include "../Rational/Rational.h"
#include <iostream>
using namespace std;

Rational round(Rational r) {
    double num = double(r);
    num = int(num * 100 + 0.5) / 100.0;
    Rational temp(num);

    return temp;
}