#include <iostream>

// Complete the function below, so that it returns the index that is
// typed by the user as a string as an integer. Generate the exceptions
// std::invalid_argument if input is empty (use the empty() member
// function of std::string) and std::domain_error if index is negative.
int parseInput(const std::string & input) {
  if (input.empty())
    throw std::invalid_argument("Input cannot be empty.");
  int index = std::stoi(input);  // convert to int
  if (index < 0)
    throw std::domain_error("Negative index is invalid.");
  return index;
}

// Complete this function, so that it calls parseInput() to obtain the
// index, and then prints out the value in vec stored at that index.
// Generate an std::out_of_range error if the index is too large.
// Write out all exceptions that might be generated below to std::cerr,
// and ensure that they can also get handled by main().
void getValue(const std::vector<int> & vec, const std::string & input) {
  try {
    int index = parseInput(input);
    if (index >= vec.size())
      throw std::out_of_range("Index exceeds vector size.");
    std::cout << "Element " << index << ": " << vec[index] << '\n';
  }
  catch (...) {
    std::cerr << "[cerr] Error for input: " << input << '\n';
    throw;  // Rethrow the exception to be handled at a higher level
  }
}

int main() {
  std::vector<int> data = {100, 200, 300};
  std::string inputs[] = {"-2", "abc", "5", "0", "232872833"};
  // Write a range-based loop that uses each element of inputs as an
  // input, together with data, to the function getValue(). Handle
  // all exceptions that could occur by writing out the output of the
  // std::exception's what() member function to std::cerr.
  for (auto input : inputs) {
    try {
      getValue(data, input);
    }
    catch (const std::exception& e) {
      std::cerr << "[Handled] " << e.what() << '\n';
    }
  }
}
