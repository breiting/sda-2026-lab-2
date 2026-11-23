#pragma once

#include <string>

namespace sda {

class Resistor {
   public:
    Resistor(const std::string& name, double resistance);
    ~Resistor() = default;

    double Resistance() const;
    std::string Name() const;
    double Current(double voltage) const;

   protected:
   private:
    std::string name;
    double resistance;
};

}  // namespace sda
