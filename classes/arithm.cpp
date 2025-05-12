#include <iostream> // for std::cout and tuples functionality

// this function returns four results as a tuple object
auto arithmetic(int a, int b) {  // auto here is possible since C++14
  return std::make_tuple( a + b, a - b, a * b, a / b );
}

int main() {
  auto arith = arithmetic(5, 7);
  // accessing the tuple is possible through indices:
  std::cout << " add: " << std::get<0>(arith) << '\n';
  std::cout << " sub: " << std::get<1>(arith) << '\n';
  std::cout << " mul: " << std::get<2>(arith) << '\n';
  std::cout << " div: " << std::get<3>(arith) << '\n';
  // .. or through decomposition declarations:
  auto [add, sub, mul, div] = arith;
  std::cout << " add: " << add << '\n';
  std::cout << " sub: " << sub << '\n';
  std::cout << " mul: " << mul << '\n';
  std::cout << " div: " << div << '\n';
}
