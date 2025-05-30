/** Print a mouse in the console, using a const pointer to avoid changes */
#include <iostream>     // terminal output
[[nodiscard]] auto *getBitmapAddress() {
  static const char bitmap[] = "(^._.^)~\n";  // "bitmap" created in static memory
  return bitmap;  // return pointer to first element
}

int main() {
  // using a pointer to bitmap, and incrementing it, is possible:
  auto * mousePointer = getBitmapAddress();
  while ( *mousePointer != 0 )  std::cout << *(mousePointer++);
  // Here mousePointer has changed, it's hard to get the original pointer.
  // Modify the above by protecting the pointer with const, and looping twice.

}
