/** Example for a friend + operator
  */

#include <iostream>

class Complex;
Complex operator + ( Complex& cn1, const Complex& cn2);

class Complex {  // Class representing a complex number, e.g. 2.3 + 4.5 i
 protected:
  double real, imag;
 public:
  Complex() : real(0), imag(0) {}
  Complex(double real, double imag) : real(real), imag(imag){}
  void display() { std::cout << real << " " << imag << '\n'; }
  friend Complex operator + ( Complex& cn1, const Complex& cn2);
};

Complex operator + ( Complex& cn1, const Complex& cn2) {
  Complex temp;
  temp.real = cn1.real + cn2.real;
  temp.imag = cn1.imag + cn2.imag;
  return temp;
}

int main() {
  Complex c1(1.2, 3.4), c2(5.6, 7.8);
  Complex result = c1 + c2;
  result.display();
  return 0;
}
