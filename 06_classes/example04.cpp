#include <iostream>     // terminal input and output classes and objects
class GPSCoord {
 private:
  double lat, lng, elv;  // latitude, longitude, elevation
 public:
  GPSCoord(double lat, double lng, double e=0.0): lat(lat), lng(lng), elv(e) {}
  operator std::string() {
    // convert the three attributes to a string

  }
  bool operator == (GPSCoord & obj) {
    // test whether two objects have same latitude and longitude

  }
};
int main() {
  GPSCoord point1(1.0,2.0,3.0), point2(1.0,2.0,4.0);
  // print out both points, and whether they overlap with the == operator

}
