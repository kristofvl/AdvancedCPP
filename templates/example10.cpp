/*  An example illustration how to normalise sensor data with transform */

#include <iostream>
#include <random>    // for generating random values in the data set

int main() {
  // we simulate a sensor data set, rawData, with 1M floats in [0,1023]:
  const size_t dataSize = 1'000'000;
  std::vector<float> rawData(dataSize);
  std::random_device rand;
  std::generate(rawData.begin(), rawData.end(), [&]() {
        return static_cast<float>(rand()) / rand.max() * 1000.0f;} );

  // normalize the data in rawData between 0 and 1, by first finding the maximum
  // value, creating a vector for the normalized data, and then using transform
  // using a lambda funtion that scales all rawData elements.
  // Bonus: time the transform by using std::chrono::high_resolution_clock::now()


}
