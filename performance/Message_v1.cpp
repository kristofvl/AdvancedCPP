/** Message_v1.cpp: Illustration the rule of three (see also _v2)
    */
#include <iostream>
#include <algorithm>

class Message {
  char * text;
 public:
  Message(const char * str);             // single constructor with C string
  ~Message();                            // 1. Destructor
  Message(const Message & other);        // 2. Copy constructor
  Message & operator=(const Message & other);    // 3. Assignment operator

  // friend method that returns a Message having a concatenated string:
  friend Message operator+(const Message & m1, const Message & m2);

  // print out the Message object address and text:
  void show() { std::cout << this << ':' << text << '\n'; }
};

// plain contructor from string:
Message::Message(const char * str) {   // copy from str:
  text = new char[std::strlen(str) + 1];
  std::strcpy(text, str);
  std::cout << "Message " << text << " constructed\n";
}

// destructor:
Message::~Message() { delete[] text; std::cout << "Message destroyed\n"; }

// copy constructor:
Message::Message(const Message & other) {  // perform deep copy:
  text = new char[std::strlen(other.text) + 1];
  std::strcpy(text, other.text);
  std::cout << "Message " << text << " copy-constructed\n";
}

// assignment operator:
Message & Message::operator=(const Message & other) {
  if (this != &other) {  // if this pointer is different to other address..
    delete[] text;
    text = new char[std::strlen(other.text) + 1];
    std::strcpy(text, other.text);
  }
  std::cout << "Message " << text << " assigned\n";
  return *this;  // dereferencing this to get to the object
}

// friend operator that concatenates two Messages:
Message operator+(const Message & m1, const Message & m2) {
  char * text = new char[std::strlen(m1.text) + std::strlen(m2.text) + 1];
  std::strcpy(text, m1.text);
  std::strcat(text, m2.text);
  Message result(text);  // construct Message with concatenated text
  delete[] text;
  return result;  // return by value or move
}

int main() {
  std::cout << "--- s1: ---\n";
  Message s1("ping!");  // s1 is an object constructed from C string
  std::cout << "--- s2: ---\n";
  Message s2(s1);       // s2's copy constructor from s1: lvalue
  std::cout << "--- s3: ---\n";
  Message s3(s1+s2);    // s3's copy constructor from s1+s2: rvalue?
  std::cout << "--- s4: ---\n";
  Message s4 = s1;      // s4 is copy-constructed here by the compiler
  std::cout << "--- s5: ---\n";
  Message s5("pong!");  // s5 is constructed here
  s5 = s2;              // s5 is assigned here
  s1.show(); s2.show(); s3.show(); s4.show(); s5.show();
}
