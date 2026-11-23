#include "sda/TemperatureSensor.hpp"

namespace sda {

TemperatureSensor::TemperatureSensor(const std::string& name) : m_Name(name) {
}

const std::string& TemperatureSensor::Name() const {
    return m_Name;
}

void TemperatureSensor::SetTemperature(double value) {
    m_Temperature = value;
    m_History.Add(value);
}

double TemperatureSensor::Temperature() const {
    return m_Temperature;
}

const MeasurementHistory& TemperatureSensor::History() const {
    return m_History;
}
}  // namespace sda
