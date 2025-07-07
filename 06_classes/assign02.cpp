#include <iostream>

// Complete the class declaration with a private array grades of 11 floats, and
// a public static integer pos_4, a default constructor and destructor, which
// will be implemented after the declaration:
class Exam {
 public:
  operator std::string();

// solution:
  Exam();
  ~Exam();
 private:
  float grades[11];
  static int pos_4;
};

int Exam::pos_4;

// In the constructor body, fill the array grades with all possible marks (1.0,2.0,
// 3.0,4,0,5.0,1.3,2.3,3.3,1.7,2.7,3.7) with a single for loop and a single if
// condition. Initialize pos_4 to 0 in the body:
// solution:
Exam::Exam() {
  for (auto i=0; i<5; i++) {
    grades[i] = i+1.0f;
    if (i < 3) {
	   grades[i+5] = i+1.3f;
      grades[i+8] = i+1.7f;
    }
  }
  pos_4 = 0;
}

// In the conversion operator implentation, return the contents of marks as string
// using std::to_string(), using a range-based loop. Store the position of the
// "4.0" substring in this string in pos_4, by using the find("4.0") method:
// solution:
Exam::operator std::string() {
  std::string ret = "";
  for (auto e : grades) {  // range-based loop mandatory
    ret += std::to_string(e)+',';  // std::to_string() given, ',' not needed
  }
  pos_4 = ret.find("4.0");
  return ret;
}

// In the destructor, print out the value of pos_4, followed by a new line:
// solution:
Exam::~Exam() {
  std::cout << pos_4 << '\n';
}

// In the main function, use a decomposition declaration and the above conversion
// operator to print out the elements of myExams, each on a single line:
int main() {
  auto myExams = std::make_tuple( Exam(), Exam(), Exam() );
  // solution:
  auto [e1, e2, e3] = myExams;
  std::cout << (std::string)e1 << '\n';
  std::cout << (std::string)e2 << '\n';
  std::cout << (std::string)e3 << '\n';
}
