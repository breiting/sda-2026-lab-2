#include "sda/SensorStation.hpp"

#include "sda/TemperatureSensor.hpp"

namespace sda {

void SensorStation::AddSensor(const std::string& name) {
    TemperatureSensor sensor(name);
    m_Sensors.push_back(sensor);
}

std::size_t SensorStation::SensorCount() const {
    return m_Sensors.size();
}

TemperatureSensor& SensorStation::SensorAt(std::size_t index) {
    return m_Sensors.at(index);
}

const TemperatureSensor& SensorStation::SensorAt(std::size_t index) const {
    return m_Sensors.at(index);
}
}  // namespace sda
