/** Example for the + operator
  */

#include <iostream>

class Char {  // wrapper class for character
  char c;  // private char;
 public:
  Char( char const& c ) : c(c) { }
  std::string operator + (const Char& c2) {
    std::string s;
    s.append(1, this->c); s.append(1, c2.c);
    return s;
  }
};

int main() {
  Char a('a'), b('b');
  std::cout << a + b << "\n";
  return 0;
}
