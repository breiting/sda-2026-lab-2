#include "sda/MeasurementHistory.hpp"
#include "sda/SensorStation.hpp"
#include "sda/TemperatureSensor.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

using namespace sda;

TEST(TemperatureSensorTest, ObjectsHaveIndependentState) {
  TemperatureSensor kitchen("Kitchen");
  TemperatureSensor office("Office");

  kitchen.SetTemperature(21.5);
  office.SetTemperature(24.0);

  EXPECT_EQ(kitchen.Name(), "Kitchen");
  EXPECT_EQ(office.Name(), "Office");

  EXPECT_DOUBLE_EQ(kitchen.Temperature(), 21.5);
  EXPECT_DOUBLE_EQ(office.Temperature(), 24.0);
}

TEST(MeasurementHistoryTest, EmptyAndAverage) {
  MeasurementHistory history;

  EXPECT_EQ(history.Count(), 0u);
  EXPECT_DOUBLE_EQ(history.Average(), 0.0);

  history.Add(10.0);
  history.Add(20.0);
  history.Add(30.0);

  EXPECT_EQ(history.Count(), 3u);
  EXPECT_DOUBLE_EQ(history.Average(), 20.0);
}

TEST(TemperatureSensorTest, OwnsItsHistory) {
  TemperatureSensor sensor("Hallway");

  sensor.SetTemperature(18.0);
  sensor.SetTemperature(22.0);

  EXPECT_EQ(sensor.History().Count(), 2u);
  EXPECT_DOUBLE_EQ(sensor.History().Average(), 20.0);
}

TEST(SensorStationTest, OwnsMultipleIndependentSensors) {
  SensorStation station;

  station.AddSensor("Kitchen");
  station.AddSensor("Office");

  ASSERT_EQ(station.SensorCount(), 2u);

  EXPECT_EQ(station.SensorAt(0).Name(), "Kitchen");
  EXPECT_EQ(station.SensorAt(1).Name(), "Office");

  station.SensorAt(0).SetTemperature(19.0);
  station.SensorAt(1).SetTemperature(25.0);

  EXPECT_DOUBLE_EQ(station.SensorAt(0).Temperature(), 19.0);
  EXPECT_DOUBLE_EQ(station.SensorAt(1).Temperature(), 25.0);

  EXPECT_THROW(station.SensorAt(2), std::out_of_range);
}
