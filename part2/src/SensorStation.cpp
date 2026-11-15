#include "sda/SensorStation.hpp"

#include <stdexcept>

namespace sda {

void SensorStation::AddSensor(const std::string &name) {
  // TODO CP5: construct a sensor directly inside m_Sensors.
  (void)name;
}

std::size_t SensorStation::SensorCount() const {
  // TODO CP5.
  return 0;
}

TemperatureSensor &SensorStation::SensorAt(std::size_t index) {
  // TODO CP5: use vector::at() to check bounds.
  (void)index;
  throw std::out_of_range("Sensor not found");
}

const TemperatureSensor &SensorStation::SensorAt(std::size_t index) const {
  // TODO CP5.
  (void)index;
  throw std::out_of_range("Sensor not found");
}
} // namespace sda
