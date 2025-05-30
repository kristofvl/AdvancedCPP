/** This code explains that functions and arrays are basically pointers
    and shows how to print out their memory addresses.
  */

#include <iostream>

int fun(int i) { return i+7; }  // a function

int main() {
  int a[3] = {1,2,3};  // an array

  // The << overloaded operator taking a void pointer exists, but
  // conversion to function pointers defaults to a bool,
  // since there are so many types for function pointers:
  std::cout << "fun:        " << fun << '\n';  // will result in warning
  std::cout << "&fun:       " << &fun << '\n';
  // Converting to a void pointer works:
  std::cout << "(void*)fun: " << (void*)fun << '\n';
  std::cout << "(void*)&fun:" << (void*)&fun << '\n';
  // The address of an array can be gotten by:
  std::cout << "a:     " <<  a << '\n';
  std::cout << "&a:    " << &a << '\n';
  std::cout << "&a[0]: " << &a[0] << '\n';

}
