/* Example of pointers to functions, and their use for passing
   functions as a parameter to a function.
   */

#include <iostream>     // terminal output

int addTwo(int x) { return x + 2; }     // functions we can pass in callFunct
int timesFour(int x) { return x * 4; }  // since they match the signature

// callFunct takes a pointer to a function:
int callFunct(int x, int (* funct)(int) ) { return funct(x); /* = (*funct)(x); */ }

int main() {
  std::cout << "addTwo(149) = " << callFunct(149, addTwo) << '\n';
  std::cout << "timesFour(4) = " << callFunct(4, timesFour) << '\n';
}
