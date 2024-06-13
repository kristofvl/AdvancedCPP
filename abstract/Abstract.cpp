#include <iostream>

class AbstractClass {  // Class has pure virtual method:
 public:
  virtual void printName() = 0;
 protected:
  std::string name = "myName";
};

class DerivedClass : public AbstractClass {
 public:
  virtual void printName() { std::cout << name << "\n"; }
};

int main() {
  // This would fail: AbstractClass myObject;
  DerivedClass myDerivedObject;  // The abstract class forces the
  myDerivedObject.printName();   // implementation of printName
  return 0;
}
