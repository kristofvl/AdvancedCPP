/* Create an array for which the length is given at runtime through an argument
   of the executable. The main function can also have two parameters:
   argc: integer containing the count of arguments in argv
   argv: array of strings holding command-line arguments.
   argv[0] is the command itself, argv[1] is first argument */
#include <iostream>

int main(int argc, char *argv[]) {
  // if an argument given, assume it is a number and convert from string:
  if (argc > 1) {
    int size = std::stoi(argv[1]);  

    // add code to create an array of length size, and fill it with increasing
    // numbers from 1 till size, display these, and then delete the array 

  }
  return 0;
}
