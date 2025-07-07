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
  float maxVal = *std::max_element(rawData.begin(), rawData.end());

  std::vector<float> normalizedData(dataSize);

  // Time the transformation
  auto start = std::chrono::high_resolution_clock::now();

  std::transform(rawData.begin(), rawData.end(), normalizedData.begin(),
                   [maxVal](float val) { return val / maxVal; });

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;

  std::cout << "Normalized first 5 values:\n";
  for (int i = 0; i < 5; ++i) {
    std::cout << normalizedData[i] << " ";
  }
  std::cout << "\nTime taken: " << duration.count() << " seconds\n";
}
