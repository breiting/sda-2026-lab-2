# Part B — Sensor Monitoring

### CP1 — Inspect and predict

- [ ] Identify class declarations, constructors, private members, and two independent objects in `app/main.cpp`.
- [ ] Locate declarations in `.hpp` and definitions in `.cpp`.
- [ ] Configure and build; run tests and inspect failures.

**STOP & REVIEW:**

- Is `TemperatureSensor` a class or an object? Why does each object have its own state?
- What does `const std::string&` mean?

### CP2 — Encapsulation and const

- [ ] Implement `TemperatureSensor::SetTemperature()` and check the `Name()` and `Temperature()` getters.
- [ ] Run the independent-state test without changing it.

```bash
> ./sensor_tests --gtest_filter=TemperatureSensorTest.ObjectsHaveIndependentState
```

**STOP & REVIEW:**

- Why are data members private?
- Why are getters `const`?
- What is the difference between `const` on a parameter and on a member function?

### CP3 — STL and measurement history

- [ ] Implement `MeasurementHistory::Add`, `Count`, and `Average`
- [ ] Empty average returns `0.0`. Run the targeted test.

**STOP & REVIEW:**

- What does `push_back` do?

### CP4 — Composition

- [ ] Extend `SetTemperature` to record every measurement in the owned `m_History`.
- [ ] Run the history test; draw `TemperatureSensor` composed of `MeasurementHistory`.

**STOP & REVIEW:**

- Which object owns the history?
- How does an owning member (composition) differ from a non-owning reference (association)?

### CP5 — One-to-many and association

- [ ] Implement `SensorStation::AddSensor`, `SensorCount`, and `SensorAt` (use `vector::at`).
- [ ] Run all tests

**STOP & REVIEW:**

- Why is `vector<TemperatureSensor>` composition?

## Bonus – Add an Existing Sensor

Extend `SensorStation` so that an existing `TemperatureSensor` object can be added to the station.

**Acceptance Criteria**

- `AddSensor(const TemperatureSensor& sensor)` accepts an existing sensor.
- The station stores a **copy** of the provided sensor.
- `Count()` increases by one after adding the sensor.
- The stored sensor retains its name and temperature.
- Modifying the original sensor afterward does not affect the stored copy.

Write at least one GoogleTest to verify this behavior.

## Advanced Challenge – Sensor Display

Implement a class `SensorDisplay` that displays the current temperature of an existing `TemperatureSensor`.

Unlike `SensorStation`, the display must **not own or copy** the sensor.

**Acceptance Criteria**

- The constructor accepts a `const TemperatureSensor&`.
- The display provides `double CurrentTemperature() const`.
- `CurrentTemperature()` returns the current temperature of the referenced sensor.
- If the original sensor's temperature changes, the display returns the updated value.
- Creating a display must not create a copy of the sensor.

Write GoogleTests to verify this behavior.
