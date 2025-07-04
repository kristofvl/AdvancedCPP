/* Example: Point class with a distanceFrom0 method that is const-overloaded.
   One overloaded method distanceFrom0() caches the result (mutable) in the non-const
   version, the const version does not cache.

   const overloading thus helps to separate safe, read-only logic from performance-tuned,
   mutable logic, provide clean APIs, and allow optimizations (like caching) without
   breaking const guarantees.
   */

#include <iostream>

class Point {
 public:
  Point(double x = 0, double y = 0) : x(x), y(y), cachedDistance_(0), cacheValid_(false) {}
  double distanceFrom0() {  // non-const method: allows caching for performance
    if (!cacheValid_) {
      std::cout << "Calculating distance (non-const)...\n";
      cachedDistance_ = std::sqrt(x_ * x_ + y_ * y_);
      cacheValid_ = true;
    }
    return cachedDistance_;
  }
  double distanceFrom0() const {  // const version: doesn't allow modifying internal state
    std::cout << "Calculating distance (const)...\n";
    return std::sqrt(x_ * x_ + y_ * y_);
  }
 private:
  double x, y;
  double cachedDistance_;  // for caching internal state
  bool cacheValid_;
};

int main() {
  Point p(3, 4);
  std::cout << "Distance (non-const): " << p.distanceFrom0() << "\n";  // uses cache
  std::cout << "Distance (non-const, cached): " << p.distanceFrom0() << "\n";  // gets from cache
  const Point cp(6, 8);
  std::cout << "Distance (const): " << cp.distanceFromOrigin() << "\n";  // always recalculates
}
