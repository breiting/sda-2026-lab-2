# Part 1 – Building a Resistor Class with TDD

## Our Challenge

The task is to design and implement a simple C++ class called `Resistor`.
Instead of writing the implementation immediately, we will follow **Test-Driven Development (TDD)**:

1. Understand a requirement.
2. Write a test that describes the expected behavior.
3. Run the test and observe it fail (**Red**).
4. Write just enough code to make the test pass (**Green**).

By the end of this exercise, we will have a small, tested C++ library.

## 1. Functional Requirements

The following requirements describe **what our software must do**, not how it should be implemented.

### R1 – Represent an Electrical Resistor

Every resistor has two properties:

- A **name** that identifies the resistor, such as `"R1"` or `"R2"`.
- A **resistance value** measured in ohms (Ω).

Both properties are provided when the resistor is created.

**Example:**

A resistor named `R1` has a resistance of `100 Ω`.

After creating this resistor, the application must be able to retrieve its name and resistance.

### R2 – Calculate Electrical Current

A resistor must be able to calculate the electrical current flowing through it when a voltage is applied.

The calculation follows **Ohm's law**:

**Current (A) = Voltage (V) / Resistance (Ω)**

**Example:**

A resistor has a resistance of `100 Ω`.

When a voltage of `5 V` is applied, the calculated current must be `0.05 A`.

The calculation must not change the resistor's properties.

### R3 – Maintain Independent Objects

An application must be able to create multiple resistors.

Each resistor must maintain its **own name and resistance value**, independently of other resistors.

**Example:**

- Resistor `R1` has a resistance of `100 Ω`.
- Resistor `R2` has a resistance of `200 Ω`.

Retrieving the resistance of `R1` must return `100 Ω`, while retrieving the resistance of `R2` must return `200 Ω`.

### R4 – Support Copying a Resistor

It must be possible to create a new resistor by copying an existing one.

The new resistor must have the same name and resistance as the original, but it must be a **separate object**.

**Example:**

We create a resistor named `R1` with a resistance of `100 Ω`.

When we copy it, the new resistor must also have the name `R1` and a resistance of `100 Ω`.

The original and the copy must occupy different object locations in memory.

### R5 – Reject Invalid Resistance Values

A resistor must always have a **strictly positive resistance**.

Creating a resistor with a resistance of zero or a negative value is not allowed.

**Expected behavior:**

- `100 Ω` → Valid
- `0 Ω` → Invalid
- `-50 Ω` → Invalid

If an invalid resistance is provided, the constructor must throw a `std::invalid_argument` exception.

## Build and run

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```
