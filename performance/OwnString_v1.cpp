/** OwnString_v1.cpp: Illustration for a move constructor (see also _v2)
    */
#include <iostream>

class OwnString {
 public:
  OwnString(const char * p);              // constructor with C string
  ~OwnString();                           // 1. Destructor
  OwnString(const OwnString & that);      // 2. Copy constructor
  OwnString & operator=(OwnString that);  // 3. Assignment operator
  // friend method that returns a reference to a concatenated string:
  friend OwnString & operator+(const OwnString & s1, const OwnString & s2);
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
// friend operator:
OwnString & operator+(const OwnString & s1, const OwnString & s2) {
  size_t size = std::strlen(s1.data) + std::strlen(s2.data) + 1;
  char * data = new char[size];
  std::memcpy(data, s1.data, std::strlen(s1.data));
  std::memcpy(data+std::strlen(s1.data), s2.data, std::strlen(s2.data));
  OwnString * s = new OwnString(data);
  return * s;
}

int main() {
  OwnString s1("ping!");  // s1 is an object from C string
  OwnString s2(s1);       // s2's copy constructor from s1: lvalue
  OwnString s3(s1+s2);    // s3's copy constructor from s1+s2: rvalue?
  s1.show(); s2.show(); s3.show();
  return 0;
}
