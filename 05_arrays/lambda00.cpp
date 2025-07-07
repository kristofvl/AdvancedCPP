/* This code shows how the capture clause in lamba functions
   can be used to swith between pass-by-value and pass-by-
   reference. */

#include <iostream>

int main() {
  int a = 7, b = 14;
  auto swap = [&a, &b]() { int t = a; a = b; b = t; };
  swap();
  std::cout << "a = " << a << '\n';
  std::cout << "b = " << b << '\n';

}
