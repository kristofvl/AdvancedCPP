#include <cstdarg>   // va_start, va_arg, va_copy, va_end, va_list
#include <iostream>  // std::cout

void myPrint(const char * format, ...) {  // example of variadic arguments
  va_list args;
  va_start(args, format);
  while (*format != '\0') {  // while the string is not delimited by a zero
    int i = va_arg(args, int);  // get the next argument as an integer
    if (*format == 'd') {
      std::cout << 'i' << i << ' ';  // precede an integer by i
    } else if (*format == 'c') {
      std::cout << 'c' << (char)i << ' ';  // precede a char by c and convert
    }
    ++format;
  }
  va_end(args);
}

int main() {
  myPrint("dcd", 3, 'a', 14);
  myPrint("cc", 'c', 'd');
  std::cout << '\n';
}

