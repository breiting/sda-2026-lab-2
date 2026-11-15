#pragma once

#include <vector>

namespace sda {

class MeasurementHistory {

public:
  void Add(double value);
  std::size_t Count() const;
  double Average() const; // Return 0.0 for an empty history.

private:
  std::vector<double> m_Values;
};
} // namespace sda
