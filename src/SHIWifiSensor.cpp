/**
 * Copyright (c) 2020 Karsten Becker All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include "SHIWifiSensor.h"

#include "WiFi.h"
std::vector<SHI::MeasurementBundle> SHI::WifiSensor::readSensor() {
  auto rssi = WiFi.RSSI();
  return {{{signalStrength->measuredInt(rssi)}, this}};
}
bool SHI::WifiSensor::setupSensor() {
  addMetaData(signalStrength);
  return true;
}
