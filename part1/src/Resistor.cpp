#include "sda/Resistor.hpp"

#include <stdexcept>

namespace sda {

Resistor::Resistor(const std::string& name, double resistance) {
    if (resistance <= 0) {
        throw std::invalid_argument("The resistance must be greater than zero.");
    }

    this->name = name;
    this->resistance = resistance;
}

double Resistor::Resistance() const {
    return resistance;
}

std::string Resistor::Name() const {
    return name;
}

double Resistor::Current(double voltage) const {
    return voltage / resistance;
}

}  // namespace sda
