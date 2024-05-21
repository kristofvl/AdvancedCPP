#include <iostream>  // std::cout, std::runtime_error, std::exception, std::cerr
class MyException : public std::exception {
 public:
  MyException(const char * msg) : message(msg) {}  // Constructor sets exception message
  const char * what() { return message.c_str(); }  // Override what() to return own message
 private:
  std::string message;
};

int main() {
  try { throw MyException("Oops, my bad."); }  // create and throw object of MyException
  catch (MyException& e) { std::cerr << "Exception handled: " << e.what() << "\n"; }
  return 0;
}
