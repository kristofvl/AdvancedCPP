#include <iostream>

// Complete the class declaration with a private array marks of 11 double elements
// and a public static integer len, a default constructor and destructor, which
// will both be implemented after the declaration:
class Student {
 public:
  operator std::string();

// solution:
  Student();
  ~Student();
 private:
  double marks[11];
  static int len;
};

int Student::len;

// In the constructor body, fill the array marks with all possible grades (1.0,2.0,
// 3.0,4,0,5.0,1.3,2.3,3.3,1.7,2.7,3.7) with a single for loop and a single if
// condition. Initialize len to -1 in the body:
// solution:
Student::Student() {
  for (auto i=0; i<5; i++) {
    marks[i] = i+1.0;
    if (i < 3) {
	   marks[i+5] = i+1.3;
      marks[i+8] = i+1.7;
    }
  }
  len = -1;
}

// In the conversion operator implentation, return the contents of marks as string
// using std::to_string() by using a range-based loop. Copy the string length in
// the attribute len using the length() method:
// solution:
Student::operator std::string() {
  std::string ret = "";
  for (auto e : marks) {  // range-based loop mandatory
    ret += std::to_string(e)+',';  // std::to_string() given, ',' not needed
  }
  len = ret.length();
  return ret;
}

// In the destructor, print out the value of len, followed by a new line as a char:
// solution:
Student::~Student() {
  std::cout << len << '\n';
}

// In the main function, use a decomposition declaration and the above conversion
// operator to print out the elements of myStudents, each on a single line:
int main() {
  auto myStudents = std::make_tuple( Student(), Student() );
  // solution:
  auto [s1, s2] = myStudents;
  std::cout << (std::string)s1 << '\n';
  std::cout << (std::string)s2 << '\n';
}
