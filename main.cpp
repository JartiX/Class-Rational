#include <iostream>
#include "Rational/Rational.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "ru-RU");
  // Test constuctors
  Rational r1(5);
  cout << "Testing Rational constructor with int argument (5): " << r1 << endl;
  Rational r2(3.14);
  cout << "Testing Rational constructor with double argument (3,14): " << r2 << endl;
  Rational a(1, 2), b(1, 6);
  cout << "a = " << a << ", b = " << b << endl;

  // Test +, -, *, / operators
  cout << "Testing + operator with Rational objects: a + b = " << a + b << endl;
  cout << "Testing - operator with Rational objects: a - b = " << a - b << endl;
  cout << "Testing * operator with Rational objects: a * b = " << a * b << endl;
  cout << "Testing / operator with Rational objects: a / b = " << a / b << endl;
  int n = 2;
  cout << "number = " << n << endl;
  cout << "Testing + operator with int: a + number = " << a + n << endl;
  cout << "Testing - operator with int: a - number = " << a - n << endl;
  cout << "Testing * operator with int: a * number = " << a * n << endl;
  cout << "Testing / operator with int: a / number = " << a / n << endl;
  double nn = 2.3;
  cout << "number = " << nn << endl;
  cout << "Testing + operator with double: a + number = " << a + nn << endl;
  cout << "Testing - operator with double: a - number = " << a - nn << endl;
  cout << "Testing * operator with double: a * number = " << a * nn << endl;
  cout << "Testing / operator with double: a / number = " << a / nn << endl;

  // Test +=, -=, *=, /= operators
  a = 3;
  cout << "a = " << a << endl;
  a += b;
  cout << "Testing += operator with Rational objects: a += b = " << a << endl;
  a -= b;
  cout << "Testing -= operator with Rational objects: a -= b = " << a << endl;
  a *= b;
  cout << "Testing *= operator with Rational objects: a *= b = " << a << endl;
  a /= b;
  cout << "Testing /= operator with Rational objects: a /= b = " << a << endl;
  a = 3;
  cout << "a = " << a << endl;
  a += 1.5;
  cout << "Testing += operator with double: a += 1.5 = " << a << endl;
  a -= 0.5;
  cout << "Testing -= operator with double: a -= 0.5 = " << a << endl;
  a *= 2.5;
  cout << "Testing *= operator with double: a *= 2.5 = " << a << endl;
  a /= 3.5;
  cout << "Testing /= operator with double: a /= 3.5 = " << a << endl;
  a = 3;
  cout << "a = " << a << endl;
  a += 1;
  cout << "Testing += operator with int: a += 1 = " << a << endl;
  a -= 5;
  cout << "Testing -= operator with int: a -= 5 = " << a << endl;
  a *= 5;
  cout << "Testing *= operator with int: a *= 5 = " << a << endl;
  a /= 5;
  cout << "Testing /= operator with int: a /= 5 = " << a << endl;

  // Test comparison operators
  cout << "a = " << a << ", b = " << b << endl;
  cout << "Testing == operator with Rational objects: a == b = " << (a == b) << endl;
  cout << "Testing != operator with Rational objects: a != b = " << (a != b) << endl;
  cout << "Testing < operator with Rational objects: a < b = " << (a < b) << endl;
  cout << "Testing > operator with Rational objects: a > b = " << (a > b) << endl;
  cout << "Testing <= operator with Rational objects: a <= b = " << (a <= b) << endl;
  cout << "Testing >= operator with Rational objects: a >= b = " << (a >= b) << endl;
  int number = 0;
  cout << "a = " << a << "number = " << number << endl;
  cout << "Testing == operator with int objects: a == number = " << (a == b) << endl;
  cout << "Testing != operator with int objects: a != number = " << (a != b) << endl;
  cout << "Testing < operator with int objects: a < number = " << (a < b) << endl;
  cout << "Testing > operator with int objects: a > number = " << (a > b) << endl;
  cout << "Testing <= operator with int objects: a <= number = " << (a <= b) << endl;
  cout << "Testing >= operator with int objects: a >= number = " << (a >= b) << endl;
  double num = -0.3;
  cout << "a = " << a << "number = " << num << endl;
  cout << "Testing == operator with double objects: a == number = " << (a == b) << endl;
  cout << "Testing != operator with double objects: a != number = " << (a != b) << endl;
  cout << "Testing < operator with double objects: a < number = " << (a < b) << endl;
  cout << "Testing > operator with double objects: a > number = " << (a > b) << endl;
  cout << "Testing <= operator with double objects: a <= number = " << (a <= b) << endl;
  cout << "Testing >= operator with double objects: a >= number = " << (a >= b) << endl;

  // Test int, double conversion operators
  a = Rational(3,4);
  int a_int = int(a);
  double a_double = double(a);
  cout << "a = " << a << endl;
  cout << "Casting Rational to int: " << a_int << endl;
  cout << "Casting Rational to double: " << a_double << endl;
  
  // Test cin, cout operators
  Rational r;
  cout << "Enter a rational number (numerator denominator): ";
  cin >> r;
  cout << "You entered: " << r << endl;
  
  // Test negative operator
  Rational c(2, 3);
  Rational neg_result = -c;
  cout << "c = " << c << ", -c = " << neg_result << endl;
  
  // Test post-increment and post-decrement operators
  cout << "c = " << c << endl;
  Rational post_inc_result = c++;
  Rational post_dec_result = c--;
  cout << "c Post-increment result: " << post_inc_result << endl;
  cout << "c Post-decrement result: " << post_dec_result << endl;

  // Test copy
  Rational c_copy = c;
  cout << "copy c: " << c_copy << endl;

  // Test rational_sqrt
  Rational d(9, 4);
  Rational sqrt_result = d.rational_sqrt();
  cout << "Testing rational_sqrt function with 9/4: " << sqrt_result << endl;

  // Test rational pow 
  Rational pow_result = c.pow(3);
  cout << "c = " << c << ", c^3 = " << pow_result << endl;

  // Test int pow
  int numb = 16;
  double sqrt_res = num_sqrt(numb);
  cout << "Testing num_sqrt function with num = " << numb << ": " << sqrt_res << endl;

  // Test quadratic equation
  Rational aa(1, 2), bb(2, 1), cc(-3, 1);
  cout << "Testing quadratic_equation function with a = " << aa << ", b = " << bb << ", c = " << cc << endl;
  quadratic_equation(aa, bb, cc);

  // Test incompleted quadratic equation
  Rational aaa(0);
  cout << "Testing uncompleted quadratic_equation function with a = " << aaa << ", b = " << bb << ", c = " << cc << endl;
  quadratic_equation(aaa, bb, cc);
}