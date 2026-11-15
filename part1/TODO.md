# Lab 02 – Part 1: Resistor

## Requirements & Acceptance Criteria

Implement a C++ class `sda::Resistor` representing an electrical resistor.

### R1 – Resistor Properties

A resistor has a name (`std::string`) and a resistance (`double`, in ohms), both provided at construction.

**Acceptance Criteria**

- Given a resistor `("R1", 100.0)`, `Name()` returns `"R1"`.
- `Resistance()` returns `100.0`.

### R2 – Calculate Current

A resistor calculates current using Ohm's law: **I = U / R**.

**Acceptance Criteria**

- Given a resistor with `100.0 Ω`, `Current(5.0)` returns `0.05`.
- `Current(0.0)` returns `0.0`.
- `Current()` can be called on a `const Resistor`.

### R3 – Independent Objects

Each resistor object maintains its own properties.

**Acceptance Criteria**

- Given `r1("R1", 100.0)` and `r2("R2", 200.0)`:
  - `r1.Name()` returns `"R1"` and `r2.Name()` returns `"R2"`.
  - `r1.Resistance()` returns `100.0` and `r2.Resistance()` returns `200.0`.

### R4 – Copy a Resistor

A resistor can be copy-constructed. The copy contains the same properties but is a distinct object.

**Acceptance Criteria**

- Given `Resistor original("R1", 100.0)` and `Resistor copy(original)`:
  - `copy.Name()` equals `original.Name()`.
  - `copy.Resistance()` equals `original.Resistance()`.
  - `&copy != &original`.

### R5 – Invalid Resistance

Resistance must be strictly positive.

**Acceptance Criteria**

- Constructing a resistor with `0.0` throws `std::invalid_argument`.
- Constructing a resistor with `-50.0` throws `std::invalid_argument`.
- Constructing a resistor with `100.0` does not throw.

## Implementation Constraints

- Namespace: `sda`
- Private members: `m_Name`, `m_Resistance`
- Constructor: `Resistor(const std::string& name, double resistance)`
- Declaration: `include/sda/Resistor.hpp`
- Implementation: `src/Resistor.cpp`
