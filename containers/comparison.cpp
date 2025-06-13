#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>

const int DATA_SIZE = 100000;
const int LOOKUPS = 50000;

template <typename Container, typename LookupFunc>
void benchmark(const std::string & name, const Container & container, const std::vector<int> & queries, LookupFunc lookup) {
  auto start = std::chrono::high_resolution_clock::now();
  auto found = 0;
  for (auto q : queries) {
    if (lookup(container, q)) {
      found++;
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << name << ": Found " << found << " / " << LOOKUPS << " in "
         << duration.count() << " ms\n";
}

int main() {
  // Generate random data
  std::vector<int> data(DATA_SIZE);
  iota(data.begin(), data.end(), 0); // Fill with 0 to DATA_SIZE - 1
  shuffle(data.begin(), data.end(), std::default_random_engine(42));

  // Generate 1,000 random queries
  std::vector<int> queries(LOOKUPS);
  generate(queries.begin(), queries.end(), []() {
        return rand() % (DATA_SIZE * 3); // include other elements, too
  });

  // create three containers, unordered_set, vector, and forward_list:
  std::unordered_set<int> u_set(data.begin(), data.end());
  std::vector<int> vec(data.begin(), data.end());
  std::forward_list<int> f_list(data.begin(), data.end());

  std::cout << "Timing element lookup:\n";
  benchmark("unordered_set", u_set, queries, [](const auto & c, int x) {
    	  return c.find(x) != c.end();
    });
  benchmark("vector", vec, queries, [](const auto & c, int x) {
        return std::find(c.begin(), c.end(), x) != c.end();
    });
  benchmark("forward_list", f_list, queries, [](const auto & c, int x) {
        return std::find(c.begin(), c.end(), x) != c.end();
    });
}
