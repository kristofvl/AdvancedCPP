#include <iostream>

// Complete the class declaration with a private array types of 11 doubles, and
// a public static integer count, a default constructor and destructor, which
// will be implemented after the declaration:
class Marks {
 public:
  operator std::string();

// solution:
  Marks();
  ~Marks();
 private:
  float types[11];
  static int count;
};

int Marks::count = 0;  // forgetting =0 is not bad

// In the constructor body, fill the array 'types' with the marks (1.0,2.0,
// 3.0,4,0,5.0,1.3,2.3,3.3,1.7,2.7,3.7) with a single for loop and a single if
// condition. Increment the 'count' static member in the body:
// solution:
Marks::Marks() {
  for (auto i=0; i<5; i++) {
    types[i] = i+1.0;
    if (i < 3) {
	   types[i+5] = i+1.3;
      types[i+8] = i+1.7;
    }
  }
  count++;
}

// In the conversion operator implentation, return the contents of 'types' as
// string using std::to_string(), using a range-based loop:
// solution:
Marks::operator std::string() {
  std::string ret = "";
  for (auto e : types) {  // range-based loop mandatory
    ret += std::to_string(e)+',';  // std::to_string() given, ',' not needed
  }
  return ret;
}

// In the destructor, print out the value of 'count', followed by a new line:
// solution:
Marks::~Marks() {
  std::cout << count << '\n';
}

// In the main function, use a decomposition declaration and the above conversion
// operator to print out the elements of myMarks, separated by a space:
int main() {
  auto myMarks = std::make_tuple( Marks(), Marks(), Marks() );
  // solution:
  auto [e1, e2, e3] = myMarks;
  std::cout << (std::string)e1 << ' ';
  std::cout << (std::string)e2 << ' ';
  std::cout << (std::string)e3 << '\n';
}
