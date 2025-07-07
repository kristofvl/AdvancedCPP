#include <iostream>

union Number {  // a Number has:
  long l;       // either a long,
  unsigned u;   // or an unsigned,
  double f;     // or a double
};

int main() {
  Number n;  // n is a union
  n.l = 7l;  // fill in the l attribute
  std::cout << n.l << '\n';
  n.f = 8.9; // fill in the f attribute
  std::cout << n.f << '\n';
  std::cout << sizeof(n) << '\n';  // only 8 bytes
  return 0;
}
