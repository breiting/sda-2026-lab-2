#include "sda/TemperatureSensor.hpp"

#include <iostream>

using namespace sda;
using namespace std;

int main() {

  TemperatureSensor kitchen("Kitchen");
  TemperatureSensor office("Office");

  kitchen.SetTemperature(21.5);
  office.SetTemperature(24.0);

  cout << kitchen.Name() << ": " << kitchen.Temperature() << " C" << endl;
  cout << office.Name() << ": " << office.Temperature() << " C" << endl;

  // TODO: after CP5, also demonstrate SensorStation.
}
