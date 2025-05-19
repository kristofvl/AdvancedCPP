/** Print a mouse in the console, using a const pointer to avoid changes */
#include <iostream>     // terminal output
[[nodiscard]] auto *getBitmapAddress() {
  static auto bitmap[] = "(^._.^)~";  // "bitmap" created in static memory
  return bitmap;  // return pointer to first element
}
int main() {
  // using a pointer to bitmap, and incrementing it, is possible:
  auto * const mousePointer = getBitmapAddress();
  auto * iterPointer = mousePointer;
  while ( *iterPointer != 0 )  std::cout << *(iterPointer++);
  std::cout << '\n';
  iterPointer = mousePointer;
  while ( *iterPointer != 0 )  std::cout << *(iterPointer++);
  std::cout << '\n';
  // Here mousePointer has changed, it's hard to get the original pointer.
  // Modify the above by protecting the pointer with const and redo the loop.

}
