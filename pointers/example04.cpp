/** Define the class' methods below so that the main function makes sense */
#include <iostream>     // terminal output

class NumberSequence {  // class for sequence of whole, positive numbers 
 public:
  NumberSequence(uint16_t length = 10); 
  void forEach(uint16_t (*func)(uint16_t));  // apply func to all numbers
  void print() const;  // print all numbers to console
 private: 
  const uint16_t length;  // length of number sequence 
  uint16_t *seq;  // the numbers are stored as a dynamic array 
};

// define all NumberSequence methods here
//

uint16_t times2(uint16_t n) { return n*2; }

int main() {
	NumberSequence s;
	s.print();
	s.forEach( &times2 ); // apply the function times2 to all numbers
	s.print();
	return 0;
}
