/* Example of usage for the unique_ptr smart pointer.
*/

#include <iostream>

struct Coordinate {
  int x = 10, y = 20;
  void print() {
    std::cout << x << ',' << y << '\n';
  }
};

int main() {
  auto p1 = std::make_unique<Coordinate>();
  auto p2 = std::make_unique<int[]>(10);
  p1->print();
  std::cout << p2.get() << '\n';  // display pointer's address
  // this would give a compiler error:
  //unique_ptr<Coordinate> p2 = p1;
}
