#include "sda/MeasurementHistory.hpp"

namespace sda {

void MeasurementHistory::Add(double value) {
  // TODO CP3: append value to m_Values.
  (void)value;
}

std::size_t MeasurementHistory::Count() const {
  // TODO CP3: return number of stored values.
  return 0;
}

double MeasurementHistory::Average() const {
  // TODO CP3: return 0.0 if empty; otherwise arithmetic mean.
  return 0.0;
}
} // namespace sda
