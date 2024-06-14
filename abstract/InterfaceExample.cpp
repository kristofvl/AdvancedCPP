#include <iostream>

class MyInterface {
 public:
  virtual int getFormulaWithX() const = 0;
  virtual ~MyInterface() {}
 public:
  static const int X = 7;
};

class Example : public MyInterface {
 public:
  int getFormulaWithX() const {  // implementation
    return 2*X*X - 7*X + 3;
  }
};

int main() {
  MyInterface * i = new Example;
  std::cout << i->getFormulaWithX() << "\n";
  return 0;
}
