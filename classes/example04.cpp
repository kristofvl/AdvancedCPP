#include <iostream>

class GPSCoord {
 private:
  // latitude, longitude, elevation:
  double lat, lng, elv;
 public:
  GPSCoord(double lat, double lng, double e=0.0): lat(lat), lng(lng), elv(e) {}
  operator std::string() {
    // implement to convert the three attributes to a string

  }
  bool operator == (GPSCoord & obj) {
    // implement to test whether two objects have same latitude and longitude

  }
};

int main() {
  GPSCoord point1(1.0,2.0,3.0), point2(1.0,2.0,4.0);
  // print out both points, and whether they overlap with the == operator
  // If they do, the output should be: "Overlap? yes", otherwise: "Overlap? no"

}
