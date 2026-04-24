/*
   For a given group of n people, what is the chance (X) that
   at least 2 have the same birthday?

   Stochastics:
     - P(X) = probability that X happens
     - P(not X) = 1 - P(X)
     - P(X) and P(Y) = P(X) * P(Y)

   P(X) = 1 - P(not X)
   P(not X) =
     for n=2: 364/365, for n=3: 364/365 * 363/365, for n=4: 364/365 * 363/365 * 362/365
     364/365 * ... * (366-n)/365
*/

#include <iostream>

class Birthday {
 public:
  double run(int n) {  // probability .....
    double p = 1.0;
    for (int i = 2; i <= n; i++ ) {
      p = p * (366.0 - i)/365.0;
    }
    return 1.0 - p;
  }
};

int main() {
  Birthday d;
  int n = 40;
  std::cout << "the probability of at least 2 in a group of " << n << "people ";
  std::cout << " having the same birthday is: " << d.run(n) << ".\n";
  return 0;
}


