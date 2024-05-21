#include <iostream>  // std::cout, std::runtime_error, std::exception, std::cerr
class Superclass {
 public:
  Superclass(int x) : x(x) { if (x < 0) throw 1; }  // an exception can be thrown here
  int x;
};
class Subclass : public Superclass {
 public:
  // exceptions from A's constructor are now caught here -- but note the throw --- …
  Subclass(int x) try : Superclass(x) {}
                  catch (int) { std::cerr << "Oops, my bad."; throw; }
};
int main() {    // … instead of here
  try { Subclass sub(-5); } catch (int) { std::cerr << "Oops, my bad.\n"; }  return 0;
}
