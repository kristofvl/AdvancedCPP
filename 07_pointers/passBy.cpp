#include <iostream>
#include <chrono>  // for timing

struct BigObject {
  double data[99999];
};

// two types of passing an object:
void byValue(BigObject obj) { obj.data[0]++; }
void byReference(BigObject& obj) { obj.data[0]++; }

int main() {
  BigObject x;
  const int N = 10000;

  // do this a few times to see the difference in execution time:
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; i++) byValue(x);
  auto middle = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; i++) byReference(x);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Passing by value: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(middle - start).count()
            << " ms\n";
  std::cout << "Passing by reference: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - middle).count()
              << " ms\n";

  // what would change when changing both functions to inline ones?
}
