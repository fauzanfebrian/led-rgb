#ifndef SERVER_SETUP_H
#define SERVER_SETUP_H

#include <ESP8266WiFi.h>

namespace ESP {

/*
 * Setup the server
 *
 * @param server - the server to setup
 */
void setupServer(WiFiServer &server);

}  // namespace ESP

#endif