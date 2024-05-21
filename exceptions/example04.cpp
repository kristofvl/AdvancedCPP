#include <iostream>  // std::cout
#include <fstream>   // std::ifstream

void run();  // catch exception + wrap it in nested exception
void open_file(const std::string& s);  // catch exception + wrap it

// Nested exception adds 'level' spaces and prints messages through recursion
void print_exception(const std::exception& e, int level = 0) {
  std::cerr << std::string(level, ' ') << "exception: " << e.what() << "\n";
  try { std::rethrow_if_nested(e); }
  catch (const std::exception& nestedException) {
    print_exception(nestedException, level+1);
  }
}

int main() {  // runs run() and prints the caught exception
  try { run(); } catch (const std::exception& e) { print_exception(e); }
  return 0;
}

void run() {  // catch exception + wrap it in nested exception
  try { open_file("nonExistentFile.txt"); }
  catch (...) { std::throw_with_nested(std::runtime_error("run() fail")); }
}

void open_file(const std::string& s) {  // catch exception + wrap it
  try {
    std::ifstream file(s);  // open file and create an IO fail:
    file.exceptions(std::ios_base::failbit);  // raise exception
  }
  catch (...) {
    std::throw_with_nested(std::runtime_error("file error: " + s));
  }
}
