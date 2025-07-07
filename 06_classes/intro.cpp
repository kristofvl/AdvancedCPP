#include <iostream>

struct A {
  const int b = 0;
  A(int b): b(b) { }
};

int main() {
  A a1(8);
  std::cout << a1.b << '\n';
}
