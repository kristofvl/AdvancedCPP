/** Example for a type conversion operator
  */

#include <iostream>

class Fraction {  //
 public:
  Fraction(int n, int d) : n(n), d(d) {}
  operator double() const { return double(n)/double(d); }
 private:
  int n, d;
};

int main() {
  Fraction frac(7, 9);
  double val = frac;
  std::cout << val << '\n';
  return 0;
}
