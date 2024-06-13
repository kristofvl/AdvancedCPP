#include <iostream>

class BaseClass {
 public:
  virtual void print() {
   std::cout << "Base Class. \n";
  }
};

class DerivedClass : public BaseClass {
 public:
  virtual void print() {
    std::cout << "Derived Class. \n";
  }
};

int main() {
  BaseClass base; DerivedClass derived;

  BaseClass & bref = base;
  BaseClass & dref = derived;
  bref.print();  // "Base Class."
  dref.print();  // "Derived Class."

  BaseClass * bpnt = &base;
  BaseClass * dpnt = &derived;
  bpnt->print();  // "Base Class."
  dpnt->print();  // "Derived Class."

  bref.BaseClass::print(); // "Base Class."
  dref.BaseClass::print(); // "Base Class."

  return 0;
}
