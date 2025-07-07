#include <iostream>  // use of std::cout, std::cin
#include <cstdlib>   // std::rand()
#include <ctime>     // std::time()
#include <cassert>   // assert()

int main() {
  std::srand( std::time(nullptr) );  // time seeds random generator (nullptr)
  double myValue = ( std::rand() % 4 ) - 2;  // gets a random value
  assert(myValue != 0);  // since we'll divide by myValue, it should not be zero
  myValue = 5 / myValue;  // integer division by 0 leads to undefined behavior
  std::cout << myValue << '\n';
}
