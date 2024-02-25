#include <iostream>
#include "Rational.h"

using namespace std;

const double EPS = 1E-19;

// constructors
Rational::Rational() {
  numer = 0;
  denom = 1;
}

Rational::Rational(int number) {
  numer = number;
  denom = 1;
}

Rational::Rational(double number) {
  denom = 1;
  number = int(number * 100+0.5)/double(100); // округляем дабл, чтобы избавиться от слишком больших дробей
  while(number - (int)number != 0) {
    number *= 10;
    denom *= 10;
  }
  numer = number;
  simplify();
}

Rational::Rational(int n, int d) {
  numer = n;
  denom = d;
}

// functions
void Rational::simplify() { // упрощаем дробь по алгоритму Евклида
  int num1 = abs(numer);
  int num2 = abs(denom);
  while (num1 != 0 && num2 != 0) {
    if (num1 >= num2) {
        num1 %= num2;
    } else {
        num2 %= num1;
    }
  }
  int nod = num1 + num2; // одно из чисел всегда 0, поэтому складывая находим НОД
  numer /= abs(nod);
  denom /= abs(nod);
  
}

Rational Rational::to_same_denom(const Rational& r) {
  Rational res(*this);
  if (numer > INT_MAX / r.denom or denom > INT_MAX / r.denom) {
    throw "Overflow";
  }
  res.numer *= r.denom;
  res.denom *= r.denom;

  return res;
}

double num_sqrt(int number) {
  bool is_negative = false;
  if (number < 0) { // numer может быть отрицательным, поэтому в таком случае выносим минус
    number = -number;
    is_negative = true;
  }
  double x = 1, nx;
  for (;;) {
    nx = (x + number / x) / 2;
    if (abs(x - nx) < EPS)  break;
    x = nx;
  }
  x = int(x*100+0.5)/double(100); // находим число с точностью до 2 знаков
  if (is_negative) {
    return -x;
  } return x;
}

Rational Rational::rational_sqrt() {
  double a, b;
  // Находим корни числителя и знаменателя
  a = num_sqrt(numer);
  b = num_sqrt(denom);
  // делаем из них дроби
  Rational aa(a);
  Rational bb(b);
  // получаем новую дробь aa(числитель) / bb(значенатель)
  return aa / bb;
}

Rational Rational::pow(int x) { // возвести дробь в целочисленную степень
  Rational res(*this);
  for (int i = 0; i < x - 1; i++) {
    res *= *this;
  }

  return res;
}

void quadratic_equation(Rational a, Rational b, Rational c) {
  // Rational*x*x+Rational*x+Rational;
  // d = b^2 - 4*a*c
  // x1 = (-b + sqrt(d)) / (2*a)
  // x2 = (-b - sqrt(d)) / (2*a)
  Rational d = b.pow(2) - a * c * 4; // дискриминант
  if (d < 0) {
    throw "No real roots";
  }
  if (a == 0) { // если неполное квадратное уравнение
    Rational x = -c / b;
    cout << "x = (" << x << ")" << endl;
    return ;
  }
  Rational x1 = (-b + d.rational_sqrt()) / (a * 2);
  Rational x2 = (-b - d.rational_sqrt()) / (a * 2);
  cout << "x1 = (" << x1 << ")" << endl;
  cout << "x2 = (" << x2 << ")" << endl;
}

// =, +=, -=, *=, /=
Rational& Rational::operator =(const Rational& r) {
  numer = r.numer;
  denom = r.denom;

  return *this;
}
Rational& Rational::operator +=(const Rational& r) {
  if (numer > INT_MAX / r.denom or r.numer > INT_MAX / denom or denom > INT_MAX / r.denom) {
    throw "Overflow";
  }
  numer = (numer * r.denom + r.numer * denom);
  denom *= r.denom;
  simplify();
  return *this;
}
Rational& Rational::operator -=(const Rational& r) {
  return (*this += (-r));
}
Rational& Rational::operator *=(const Rational& r) {
  if (numer > INT_MAX / abs(r.numer+EPS) or denom > INT_MAX / r.denom) {
    throw "Overflow";
  }
  numer *= r.numer;
  denom *= r.denom;
  simplify();
  return *this;
}
Rational& Rational::operator /=(const Rational& r) {
  Rational res;

  res.denom = r.numer;
  res.numer = r.denom;

  return *this *= res;
}

Rational& Rational::operator +=(int number) {
  Rational res(number);

  return *this += res;
} 
Rational& Rational::operator -=(int number) {
  Rational res(number);

  return *this -= res;
} 
Rational& Rational::operator *=(int number) {
  Rational res(number);

  return *this *= res;
} 
Rational& Rational::operator /=(int number) {
  Rational res(number);

  return *this /= res;
} 

Rational& Rational::operator +=(double number) {
  Rational res(number);

  return *this += res;
} 
Rational& Rational::operator -=(double number) {
  Rational res(number);

  return *this -= res;
} 
Rational& Rational::operator *=(double number) {
  Rational res(number);

  return *this *= res;
} 
Rational& Rational::operator /=(double number) {
  Rational res(number);

  return *this /= res;
} 

// +, -, *, /
Rational Rational::operator +(const Rational& r) const {
  Rational res(*this);

  return res += r;
}
Rational Rational::operator -(const Rational& r) const {
  Rational res(*this);
  return (res += (-r));
}
Rational Rational::operator *(const Rational& r) const {
  Rational res(*this);

  return res *= r;
}
Rational Rational::operator /(const Rational& r) const {
  Rational res(*this);

  return res /= r;
}

Rational Rational::operator +(int number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational += res;
} 
Rational Rational::operator -(int number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational -= res;
} 
Rational Rational::operator *(int number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational *= res;
} 
Rational Rational::operator /(int number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational /= res;
} 

Rational Rational::operator +(double number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational += res;
} 
Rational Rational::operator -(double number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational -= res;
} 
Rational Rational::operator *(double number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational *= res;
} 
Rational Rational::operator /(double number) const {
  Rational origin_rational(*this);
  Rational res(number);

  return origin_rational /= res;
} 
Rational Rational::operator -() const {
  Rational r(-numer, denom);

  return r;
}

// ++, --
Rational Rational::operator ++() {
  numer += denom;
  return *this;
}
Rational Rational::operator --() {
  numer -= denom;

  return *this;
}
Rational Rational::operator ++(int) {
  Rational r(*this);

  numer += denom;

  return r;
}
Rational Rational::operator --(int) {
  Rational r(*this);

  numer -= denom;

  return r;
}

// ==, !=, <, >, <=, >=
bool Rational::operator ==(const Rational& r) const
{
  Rational res(*this);
  Rational res_1(r);

  res.to_same_denom(r);
  res_1.to_same_denom(*this);
  return res.numer == res_1.numer;
}
bool Rational::operator !=(const Rational& r) const
{
  return !(*this == r);
}
bool Rational::operator <(const Rational& r) const {
  return !(*this >= r);
}
bool Rational::operator >(const Rational& r) const {
  return !(*this <= r);
}
bool Rational::operator <=(const Rational& r) const {
  Rational res(*this);
  Rational res_1(r);

  res.to_same_denom(r);
  res_1.to_same_denom(*this);

  return (res.numer <= res_1.numer);
}
bool Rational::operator >=(const Rational& r) const {
  Rational res(*this);
  Rational res_1(r);

  res.to_same_denom(r);
  res_1.to_same_denom(*this);

  return (res.numer >= res_1.numer);
}

bool Rational::operator ==(int number) const {
  return (*this == Rational(number));
}
bool Rational::operator !=(int number) const {
  return (*this != Rational(number));
}
bool Rational::operator <(int number) const {
  return (*this < Rational(number));
}
bool Rational::operator >(int number) const {
  return (*this > Rational(number));
}
bool Rational::operator <=(int number) const {
  return (*this <= Rational(number));
}
bool Rational::operator >=(int number) const {
  return (*this >= Rational(number));
}

bool Rational::operator ==(double number) const {
  return (*this == Rational(number));
}
bool Rational::operator !=(double number) const {
  return (*this != Rational(number));
}
bool Rational::operator <(double number) const {
  return (*this < Rational(number));
}
bool Rational::operator >(double number) const {
  return (*this > Rational(number));
}
bool Rational::operator <=(double number) const {
  return (*this <= Rational(number));
}
bool Rational::operator >=(double number) const {
  return (*this >= Rational(number));
}



// int, double
Rational::operator int() const {
  return numer / denom;
}
Rational::operator double() const {
  return ((double)numer) / denom;
}

// cin, cout
istream& operator >>(istream& in, Rational& r) {
  in >> r.numer >> r.denom;
  return in;
}
ostream& operator <<(ostream& out, const Rational& r) {
  if (r.numer % r.denom == 0) { // если наше число можно разделить, то выводим только целое число
    out << r.numer / r.denom;
  } else out << r.numer << "/" << r.denom;
  return out;
}