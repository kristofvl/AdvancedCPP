/* Example of passing an object to a function by reference
   */

#include <iostream>  // output to terminal

struct Pair {
  int x,y;
};

void swap(Pair & p)	{
  auto temp = 0;
  temp = p.x; p.x = p.y; p.y = temp;
}

int main()	{
  Pair p; p.x = 5; p.y = 10;
  swap(p);
  std::cout << p.x << ", " << p.y << '\n';
}
