# Lab 02 – Part 2: Sensor Monitoring

## Project Overview

Imagine you are developing a small monitoring system for an electrical engineering laboratory.

Several temperature sensors are installed at different measurement points. Each sensor has a name and measures a temperature in degrees Celsius.

Our software should allow us to:

- Represent individual temperature sensors.
- Store temperature measurements and calculate their average.
- Group multiple sensors into a monitoring station.
- Access and evaluate measurements from the station.

We will implement this system using classes, encapsulation, and object relationships (associations).

## Class Diagram

The system consists of three classes:

```text
+----------------------------------+
|         TemperatureSensor        |
+----------------------------------+
| - m_Name: std::string            |
| - m_Temperature: double          |
| - m_History: MeasurementHistory  |
+----------------------------------+
| + SetTemperature(value)          |
| + GetTemperature(): double       |
| + Name(): const std::string&     |
+----------------------------------+
                 |
                 | owns one
                 v
+----------------------------------+
|        MeasurementHistory        |
+----------------------------------+
| - m_Values: std::vector<double>  |
+----------------------------------+
| + Add(value)                     |
| + Count(): std::size_t           |
| + Average(): double              |
+----------------------------------+


+----------------------------------+
|           SensorStation          |
+----------------------------------+
| - m_Sensors:                     |
|   std::vector<TemperatureSensor> |
+----------------------------------+
| + AddSensor(...)                 |
| + Count(): std::size_t           |
+----------------------------------+
                 |
                 | owns many
                 v
        +-------------------+
        | TemperatureSensor |
        +-------------------+
```

## Object Relationships

A `TemperatureSensor` owns its `MeasurementHistory`. A `SensorStation` owns a collection of `TemperatureSensor` objects.

A single station can contain multiple sensors.

## Example Scenario

A monitoring station contains two temperature sensors:

- `Motor`: 65.0 °C
- `Ambient`: 22.5 °C

The motor sensor receives additional measurements: 66.0 °C and 67.0 °C.

Its measurement history stores these values, allowing the application to calculate an average temperature.

The station provides a central place to manage the sensors.

## Your Task

Follow the checkpoints in **[TODO.md](TODO.md)**.

Do not modify the provided tests. Implement the missing functionality in the header and source files until all tests pass.
