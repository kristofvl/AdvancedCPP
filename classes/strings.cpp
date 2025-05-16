#include <iostream>     // terminal input and output classes and objects
int main() {
  std::wcout.imbue(std::locale("en_US.UTF-8"));
  std::string  myStr  = "¡Hola! 日本 שלום 你好مرحبا";   // UTF-8
  std::wstring mywStr = L"¡Hola! 日本 שלום 你好مرحبا";  // wide chars
  std::cout  << myStr << '\n' << sizeof(myStr[0]) << '\n';
  std::wcout << mywStr << '\n' << sizeof(mywStr[0]) << '\n';  // ! note wcout
  // what do sizeof(myStr) and sizeof(mywStr) return? Try it out and explain
}
