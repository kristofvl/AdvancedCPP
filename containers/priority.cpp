#include <iostream>
int main() {
  // a package has a weight and destination, deliveries are a priority queue
  using Package = std::tuple<double, std::string>;
  // Comparator for max-heap (heavier packages have higher priority):
  auto cmp = [](const Package & a, const Package & b) {
      return std::get<0>(a) < std::get<0>(b);  // index-based access
    };
  std::priority_queue<Package, std::vector<Package>, decltype(cmp)> deliveries(cmp);
  // add deliveries, duplicates possible:
  deliveries.push({2.5, "Berlin"});  deliveries.push({1.2, "Siegen"});
  deliveries.push({3.1, "Berlin"});  deliveries.push({2.5, "Hamburg"});
  deliveries.push({4.1, "Cologne"}); deliveries.push({2.5, "Berlin"});
  // emptying the priority queue:
  std::cout << "handling all deliveries (packages sorted by weight):\n";
  while (!deliveries.empty()) {
    auto [weight, city] = deliveries.top();  // structured binding
    std::cout << weight << " kg - " << city << '\n';
    deliveries.pop();
  }
}
