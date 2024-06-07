#include <iostream>
#include <vector>

int main() {
  std::vector a( { 16.0, 17.0, 18.0 } );  // since C++17
  std::vector b( { 10.0, 30.0, 60.0 } );
  std::vector<double> c;
  double n = 2.7;
  std::transform(a.begin(), a.end(),               // iterators for all
                 b.begin(), std::back_inserter(c), // input and output vectors
          [=](double x, double y) {return(x - y)/n; });
         // [=] : capture all external variables (n) in lambda by value
         // [&] : capture all external variables (n) in lambda by reference
  for (const double & i : c) {
    std::cout << i << "\n";
  }
  return 0;
}

