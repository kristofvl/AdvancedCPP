#include <iostream>

auto f() {
  if constexpr (__cplusplus == 202002L)  // const char*
    return "C++23";
  else
    return 3;  // int, never compiled
}

int main() {
  std::cout << f() << '\n';
  return 0;
}
