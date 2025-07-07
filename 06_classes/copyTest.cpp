#include <iostream>
#include <fstream> // in/output file stream classes

int main() {
  std::ifstream myFile("copyTest.cpp");    // initialize input and output file
  std::ofstream myFileCopy("copyTest_copy.cpp");  // streams with constructors

  auto c = ' ';
  // get each character from input file stream and output to output file stream
  while (myFile.get(c)) myFileCopy << c;
  std::cout << '\n';
}
