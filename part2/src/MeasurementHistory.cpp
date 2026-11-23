#include "sda/MeasurementHistory.hpp"

namespace sda {

void MeasurementHistory::Add(double value) {
    m_Values.push_back(value);
}

std::size_t MeasurementHistory::Count() const {
    return m_Values.size();
}

double MeasurementHistory::Average() const {
    if (m_Values.empty()) {
        return 0.0;
    }

    double sum = 0.0;

    for (double value : m_Values) {
        sum += value;
    }

    return sum / m_Values.size();
}

}  // namespace sda
