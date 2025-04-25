#include <iostream>

int main() {
  int a = 7, b = 14;
  auto swap = [&a, &b]() { int t = a; a = b; b = t; };
  swap();
  std::cout << "a = " << a << '\n';
  std::cout << "b = " << b << '\n';
}
