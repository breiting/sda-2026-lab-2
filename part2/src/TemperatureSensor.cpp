#include "sda/TemperatureSensor.hpp"

namespace sda {

TemperatureSensor::TemperatureSensor(const std::string &name) : m_Name(name) {}

const std::string &TemperatureSensor::Name() const { return m_Name; }

void TemperatureSensor::SetTemperature(double value) {
  // TODO CP2: update m_Temperature.
  // TODO CP4: also record the measurement in m_History.
  (void)value;
}

double TemperatureSensor::Temperature() const { return m_Temperature; }

const MeasurementHistory &TemperatureSensor::History() const {
  return m_History;
}
} // namespace sda
