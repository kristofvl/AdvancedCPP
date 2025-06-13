/* An example of dynamically transforming output (similar
   to filters in Boost, but without dependencies */

#include <iostream>

// a custom stream buffer that outputs all as upper case
class Uppercase : public std::streambuf {
  std::streambuf* target;
 public:
  Uppercase(std::streambuf* buf) : target(buf) {}
 protected:
  // overflow is a virtual std::streambuf function and
  // called by a stream whenever a character is written:
  int overflow(int ch) override {
    if (ch != EOF) ch = std::toupper(ch);
    return target->sputc( ch );
  }
};

int main() {
  Uppercase u( std::cout.rdbuf() );  // buffer links to cout
  std::ostream upperOutput( &u );  // output stream using u
  upperOutput << "this should be uppercase\n";
}
