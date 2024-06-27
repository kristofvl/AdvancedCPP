/** OwnString_v2.cpp: Illustration for a move constructor
    */
#include <iostream>

class OwnString {
 public:
  OwnString(const char * p);              // constructor with C string
  ~OwnString();                           // 1. Destructor
  OwnString(const OwnString & that);      // 2. Copy constructor
  OwnString & operator=(OwnString that);  // 3. Assignment operator
  OwnString(OwnString&& that);            // move constructor: OwnString&&
                                          //  is an rvalue reference
  // friend method that returns an rvalue :
  friend OwnString && operator+(const OwnString & s1, const OwnString & s2);
  void show() { std::cout << data << '\n'; }
 private:
  char * data;
};

OwnString::OwnString(const char * p) {
  std::cout << "in char[] constructor\n";
  size_t size = std::strlen(p) + 1;
  data = new char[size];
  std::memcpy(data, p, size);
}
OwnString::~OwnString() { delete[] data; }
OwnString::OwnString(const OwnString & that) {
  std::cout << "in copy constructor\n";
  size_t size = std::strlen(that.data) + 1;
  data = new char[size];
  std::memcpy(data, that.data, size);  // deep copy of that.data to data
}
OwnString & OwnString::operator=(OwnString that) {
  std::swap(data, that.data);  // see copy-swap idiom
  return *this;
}
// move constructor:
OwnString::OwnString(OwnString&& that) {  // OwnString&& is an rvalue
  data = that.data;                       // reference to a string
  that.data = nullptr;   // note the simplicity (versus copy constructor)
  std::cout << "in move constructor\n";
}
// friend operator returning an rvalue:
OwnString && operator+(const OwnString & s1, const OwnString & s2) {
  size_t size = std::strlen(s1.data) + std::strlen(s2.data) + 1;
  char * data = new char[size];
  std::memcpy(data, s1.data, std::strlen(s1.data));
  std::memcpy(data+std::strlen(s1.data), s2.data, std::strlen(s2.data));
  OwnString * s = new OwnString(data);
  return std::move(* s);
}

int main() {
  OwnString s1("ping!");  // s1 is an object from C string
  OwnString s2(s1);       // s2's copy constructor from s1 (an lvalue)
  OwnString s3(s1+s2);    // s3's move constructor from s1+s2 (an rvalue)
  s1.show(); s2.show(); s3.show();
  return 0;
}
