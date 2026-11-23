#include <gtest/gtest.h>

#include <stdexcept>

#include "sda/Resistor.hpp"

using namespace sda;

// **Acceptance Criteria**
// - Given a resistor `("R1", 100.0)`, `Name()` returns `"R1"`.
// - `Resistance()` returns `100.0`.

TEST(TestResistor, R1) {
    Resistor r("R1", 100.0);
    EXPECT_EQ(r.Name(), "R1");
    EXPECT_DOUBLE_EQ(r.Resistance(), 100.0);
}

// - Given a resistor with `100.0 Ω`, `Current(5.0)` returns `0.05`.
// - `Current(0.0)` returns `0.0`.
// - `Current()` can be called on a `const Resistor`.

TEST(TestResistor, R2) {
    const Resistor r("", 100.0);
    EXPECT_DOUBLE_EQ(r.Current(5.0), 0.05);
    EXPECT_DOUBLE_EQ(r.Current(0.0), 0.0);
}

// - Given `r1("R1", 100.0)` and `r2("R2", 200.0)`:
//   - `r1.Name()` returns `"R1"` and `r2.Name()` returns `"R2"`.
//   - `r1.Resistance()` returns `100.0` and `r2.Resistance()` returns `200.0`.

TEST(TestResistor, R3) {
    Resistor r1("R1", 100.0);
    Resistor r2("R2", 200.0);

    EXPECT_EQ(r1.Name(), "R1");
    EXPECT_EQ(r2.Name(), "R2");
    EXPECT_DOUBLE_EQ(r1.Resistance(), 100.0);
    EXPECT_DOUBLE_EQ(r2.Resistance(), 200.0);
}

// - Given `Resistor original("R1", 100.0)` and `Resistor copy(original)`:
//   - `copy.Name()` equals `original.Name()`.
//   - `copy.Resistance()` equals `original.Resistance()`.
//   - `&copy != &original`.

TEST(TestResistor, R4) {
    Resistor original("R1", 100.0);
    Resistor copy(original);
    EXPECT_EQ(original.Name(), copy.Name());
    EXPECT_EQ(original.Resistance(), copy.Resistance());
}

// - Constructing a resistor with `0.0` throws `std::invalid_argument`.
// - Constructing a resistor with `-50.0` throws `std::invalid_argument`.
// - Constructing a resistor with `100.0` does not throw.

TEST(TestResistor, R5) {
    EXPECT_THROW(Resistor("", 0.0), std::invalid_argument);
    EXPECT_THROW(Resistor("", -50.0), std::invalid_argument);
    EXPECT_NO_THROW(Resistor("", 100.0));
}
