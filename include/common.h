/*
 * project:  Intex PureSpa SB-H20 WiFi Controller
 *
 * file:     common.h
 *
 * encoding: UTF-8
 * created:  13th March 2021
 *
 * Copyright (C) 2021 Jens B.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <limits.h>
#include <../d1_mini/pins_arduino.h>

//#define SERIAL_DEBUG

namespace CONFIG
{
  const char POOL_MODEL_NAME[] = "Intex PureSpa SB-H20";
  const char WIFI_VERSION[] = "1.0.2.0"; // 12.06.2022

  // WiFi parameters
  const unsigned long WIFI_MAX_DISCONNECT_DURATION = 900000; // [ms] 5 min until reboot

  // MQTT publish rates
  const unsigned int POOL_UPDATE_PERIOD = 500;           // [ms]
  const unsigned int WIFI_UPDATE_PERIOD = 30000;         // [ms] 30 sec
  const unsigned int FORCED_STATE_UPDATE_PERIOD = 10000; // [ms] 10 sec
}

// Config File Tags
namespace CONFIG_TAG
{
  const char FILENAME[] = "config.json";

  const char WIFI_SSID[] = "wifiSSID";
  const char WIFI_PASSPHRASE[] = "wifiPassphrase";

  const char MQTT_SERVER[] = "mqttServer";
  const char MQTT_USER[] = "mqttUser";
  const char MQTT_PASSWORD[] = "mqttPassword";
  const char MQTT_RETAIN[] = "mqttRetain";
};

// MQTT topics
namespace MQTT_TOPIC
{
  // publish
  const char STATE[] = "intex/state";
  const char MODEL[] = "intex/model";
  const char VERSION[] = "intex/version";
  const char WIFI_IP[] = "intex/wifi/ip";
  const char WIFI_RSSI[] = "intex/wifi/rssi";
  const char BOARD_TEMPERATURE[] = "intex/board/temperature";
  const char POOL_BUBBLE[] = "intex/pool/bubble";
  const char POOL_ERROR[] = "intex/pool/error";
  const char POOL_FILTER[] = "intex/pool/filter";
  const char POOL_HEATER[] = "intex/pool/heater";
  const char POOL_POWER[] = "intex/pool/power";
  const char POOL_CURRENT_TEMPERATURE[] = "intex/pool/current_temperature";
  const char POOL_TARGET_TEMPERATURE[] = "intex/pool/target_temperature";

  // subscribe
  const char POOL_BUBBLE_SET[] = "intex/pool/bubble/set";
  const char POOL_FILTER_SET[] = "intex/pool/filter/set";
  const char POOL_HEATER_SET[] = "intex/pool/heater/set";
  const char POOL_POWER_SET[] = "intex/pool/power/set";
  const char POOL_TARGET_TEMPERATURE_SET[] = "intex/pool/target_temperature/set";
}

// ESP8266 pins
namespace PIN
{
  const uint8_t CLOCK = D5;
  const uint8_t DATA = D6;
  const uint8_t LATCH = D7;
}

// serial debugging
#ifdef SERIAL_DEBUG
#define DEBUG_MSG(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_MSG(...)
#endif

class DIFF
{
public:
  static unsigned long timeDiff(unsigned long newTime, unsigned long oldTime);
  static unsigned long diff(unsigned int newVal, unsigned int oldVal);
};

#endif /* COMMON_H */
