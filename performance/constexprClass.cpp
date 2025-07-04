#include <iostream>

class A {
 public:
  int v = 3;
  constexpr int f() const { return v; }
  static constexpr int g() { return 3; }
};

int main() {
  A a1;
  constexpr int x = a1.f();  // compile error, f() evaluated at run-time
  constexpr int y = a1.g(); // ok, same as 'A::g()'
  constexpr A a2;
  constexpr int z = a2.f(); // works
}


