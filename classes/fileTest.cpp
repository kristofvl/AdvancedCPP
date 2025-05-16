#include <iostream>    // terminal input/output classes & objects
#include <fstream>     // input file stream class std::ifstream

int main() {
  std::ifstream myFile("fileTest.cpp");  // initialize with constructor

  auto c = ' ';
  // get a character from the file, move to next, and output it to the terminal
  while (myFile.get(c)) std::cout << c;
  std::cout << '\n';
}
