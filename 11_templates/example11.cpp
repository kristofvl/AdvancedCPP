/*  An example illustration how to calibrate temperature data with transform
    and a functor */

#include <iostream>

// Create a functor called 'Calibrate' for calibration of data, using two
// attributes 'scale' and 'offset', which are used to do the calibration
// through the () operator.



int main() {
  // A time series for temperature values in degrees Celcius:
  std::vector<float> rawTemps = {37.5f, 37.8f, 37.5f, 37.3f, 37.6f};

  // Create a vector 'calibratedTemps' of the same size as rawTemps, and
  // apply Calibrate in std::transform by scaling the temperatur values up
  // by 10% and then shifting the signal down by 2 degrees Celsius


}
