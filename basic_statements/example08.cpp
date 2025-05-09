/**
   Write a program that draws in the terminal the letter N for a
   given size, made out of '0' characters.
   Depending on the variable int size (with size = 4, ..., 30):
   size = 4:    size = 5:      size = 6:      etc.
   0  0         0   0          0    0
   00 0         00  0          00   0
   0 00         0 0 0          0 0  0
   0  0         0  00          0  0 0
                0   0          0   00
                               0    0
**/

#include <iostream>  // to allow use of std::cout and std::endl
int main( ) {

  auto size = 15;

  auto n = size - 1;

  for (auto y = 0; y <= n; y++) {
    for (auto x = 0; x <= n; x++) {
      if ( (x == 0) || (x == n) || (x == y) ) {
        std::cout << '0';
      } else {
   	  std::cout << ' ';
      }
    }
    std::cout << '\n';
  }

  return 0;
}
