#include "../Rational/Rational.h"
#include "quadratic_equation.h"
#include <iostream>


void quadratic_equation(Rational a, Rational b, Rational c) {
    // Rational*x*x+Rational*x+Rational;
    // d = b^2 - 4*a*c
    // x1 = (-b + sqrt(d)) / (2*a)
    // x2 = (-b - sqrt(d)) / (2*a)
    Rational d = b.pow(2) - a * c * 4; // дискриминант
    if (d < 0) {
        throw "No real roots";
    }
    if (a == Rational()) { // если неполное квадратное уравнение
        Rational x = -c / b;
        cout << "x = (" << x << ")" << endl;
        return;
    }
    Rational x1 = (-b + d.rational_sqrt()) / (a * 2);
    Rational x2 = (-b - d.rational_sqrt()) / (a * 2);
    cout << "x1 = (" << x1 << ")" << endl;
    cout << "x2 = (" << x2 << ")" << endl;
}