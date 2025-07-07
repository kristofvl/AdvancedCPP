#include <iostream>

constexpr int square(int value) {
  return value * value;
}

int main() {
  square(4);  // evaluated at compile-time
  int val = 4;
  square(val);  // evaluated at run-time
  return 0;
}
