#pragma once

#include "sda/MeasurementHistory.hpp"
#include <string>

namespace sda {

class TemperatureSensor {

public:
  explicit TemperatureSensor(const std::string &name);
  const std::string &Name() const;
  void SetTemperature(double value);
  double Temperature() const;
  const MeasurementHistory &History() const;

private:
  std::string m_Name;
  double m_Temperature{0.0};
  MeasurementHistory m_History; // Composition: sensor owns its history.
};
} // namespace sda
