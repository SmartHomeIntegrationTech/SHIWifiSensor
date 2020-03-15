/**
 * Copyright (c) 2020 Karsten Becker All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */
#pragma once
#include <memory>
#include <vector>

#include "SHISensor.h"

namespace SHI {

class WifiSensor : public Sensor {
 public:
  WifiSensor() : Sensor("Wifi") {}
  std::vector<MeasurementBundle> readSensor();
  bool setupSensor();
  bool stopSensor() { return true; }
  const Configuration *getConfig() const { return nullptr; }
  bool reconfigure(Configuration *newConfig) { return true; }

 private:
  std::shared_ptr<SHI::MeasurementMetaData> signalStrength =
      std::make_shared<SHI::MeasurementMetaData>("Signalstrength", "dBm",
                                                 SHI::SensorDataType::INT);
};

}  // namespace SHI
