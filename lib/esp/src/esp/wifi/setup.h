#ifndef WIFI_SETUP_H
#define WIFI_SETUP_H

#include <ESP8266WiFi.h>

namespace ESP {
/*
 * Connect to the WiFi network
 *
 * @return IPAddress - the IP address of the device
 */
IPAddress setupWifi();
}  // namespace ESP

#endif