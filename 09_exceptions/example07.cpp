#include <iostream>

// Complete this function to check whether the input is empty, or whether
// the value is negative. Use the .empty() std::string member
// function for this. Use the existing std::invalid_argument (for an empty
// string) and std::domain_error (for negatives) exceptions if these occur.
int parseInput(const std::string & input) {


  // Convert to int (may throw std::invalid_argument or std::out_of_range):
  int value = std::stoi(input);



}

// Complete this function that returns an element in a vector to cause an
// std::out_of_range exception if the index is too large. Use the .size()
// member function for the vector container.
int accessData(const std::vector<int> & data, int index) {



  return data[index];
}

int main() {
  std::vector<int> data = {10, 20, 30};
  // User input could be "-42", "12345678901234567890", or "abc"
  std::string userInput = "4";
  // Use complete exception handling for the code below to print out
  // the type of exception and the .what() description for each.
  // Handle std::exception exceptions for general errors, too.


    int number = parseInput(userInput);
    int value = accessData(data, number);
    std::cout << "Value at index " << number << ": " << value << '\n';


}
