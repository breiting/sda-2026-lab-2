#pragma once

#include "sda/TemperatureSensor.hpp"

#include <string>
#include <vector>

namespace sda {

class SensorStation {

public:
  void AddSensor(const std::string &name);
  std::size_t SensorCount() const;
  TemperatureSensor &SensorAt(std::size_t index);
  const TemperatureSensor &SensorAt(std::size_t index) const;

private:
  std::vector<TemperatureSensor> m_Sensors; // Station owns sensor objects.
};
} // namespace sda
