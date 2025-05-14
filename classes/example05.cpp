#include <iostream>

class GPSCoord {
 private:
  // latitude, longitude, elevation:
  double lat, lng, elv;
 public:
  GPSCoord(double lat, double lng, double e=0.0): lat(lat), lng(lng), elv(e) {}
  int operator [] (int index);  // access the GPS coordinates with []
};

int GPSCoord::operator [] (int index) {
  // for index 0, 1 or 2, return the latitude, longitude, or elevation

}

int main() {
  GPSCoord point1(1.0,2.0,3.0);
  // print out the coordinates by accessing them with the [] operator

}
