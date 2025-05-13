#include <iostream>

class Complex {
 private:
  int real, imag;
 public:
  Complex(int real=0, int imag=0): real(real), imag(imag) {}  // sole constructor
  Complex operator +(Complex const& obj) {  // takes the object on right of '+'
    Complex res;                           // this object is on the left of '+'
    res.real = real + obj.real;
    res.imag = imag + obj.imag;
    return res;
  }
  operator std::string() {  // conversion to std::string operator
    return std::to_string(real)+'+'+std::to_string(imag)+'i';
  }
  operator float() {  // conversion to float operator
    return (float)real+(float)imag/1000.0f;
  }
};  // end of Complex class

int main() {
  Complex c1(2,3), c2(7,5), c3(3,3);
  std::cout << (std::string)(c1 + c2) << '\n';  // out: 9+8i
  c1 = 6; c2 = {7, 8}; c3 = c2;  // conversion constructor, default assignment
  std::cout << c1 << ' ' << c2 << ' ' << c3 << '\n';  // out: 6 7.008 4
}

