#pragma once

#include <string>

#include "sda/MeasurementHistory.hpp"

namespace sda {

class TemperatureSensor {
   public:
    explicit TemperatureSensor(const std::string& name);
    const std::string& Name() const;
    void SetTemperature(double value);
    double Temperature() const;
    const MeasurementHistory& History() const;

   private:
    std::string m_Name;
    double m_Temperature{0.0};
    MeasurementHistory m_History;  // Composition: sensor owns its history.
};
}  // namespace sda
