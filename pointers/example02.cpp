/** An exercise illustrating shallow and deep copy: Add to the code of GPSTrace
    the necessary functionality that allows copying a GPSTrace and illustrate this
    in the main function below. */

#include <iostream>  // for writing to the console

//--- GPSTrace uses this class for single GPS coordinates: ---------
class GPSCoord {  // GPS coordinate class
 public:
  GPSCoord() {;}  // default constructor
  GPSCoord(GPSCoord const &source);  // copy constructor
  void set(double lat, double lng);  // set latitude, longitude
  void setElevation(double elv);     // set elevation
  void print() const;  // output coordinates to console
 private:
  double lat, lng, elv;  // latitude, longitude, elevation
};

GPSCoord::GPSCoord(GPSCoord const &source) {  // copy constructor
  lat = source.lat; lng = source.lng; elv = source.elv;
  }
void GPSCoord::set(double lat, double lng) {
  this->lat = lat; this->lng = lng;
}
void GPSCoord::setElevation(double elv) {
  this->elv = elv;
}
void GPSCoord::print() const {
  std::cout << "Lat:" << lat << " Lng:" << lng;
  std::cout << " Elv:" << elv << "\n";
}


//--- GPSTrace holds several dynamically allocated GPS points: -----
class GPSTrace {  // class for a GPS trace
 public:
  GPSTrace(uint16_t numPoints);
  ~GPSTrace();
  // add a new point to trace at position pos:
  void setPoint(GPSCoord newPoint, uint16_t pos);  // set a GPSCoord
  [[nodiscard]] int print() const;  // print entire trace
 private:
  GPSCoord *points;  // pointer to GPS coordinates
  uint16_t numPoints;
};

GPSTrace::GPSTrace(uint16_t numpoints): numPoints(numpoints) {
  points = new GPSCoord[numPoints];
}
GPSTrace::~GPSTrace() {
  delete[] points; points = NULL; numPoints = 0;
}
void GPSTrace::setPoint(GPSCoord newPoint, uint16_t pos) {
  if (pos < numPoints) points[pos] = newPoint;
}
int GPSTrace::print() const {  // output trace to console
  for (auto i = 0; i < numPoints; i++) points[i].print();
  return 0;
}

//--- This program creates a trace of 5 points ---------------------
// extend it to illustrate copying a GPSTrace object:
int main() {
  GPSTrace t(5);
  for (auto i = 0; i < 5; i++ ) {  // fill in the points
    GPSCoord point;
    point.set(i*1.2, i*3.4);
    point.setElevation(i*5.6);
    t.setPoint(point, i);
  }
  return t.print();
}
