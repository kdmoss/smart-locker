/* Reference: */ 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

extern "C" {
  #include "user_interface.h"
  #include "wpa2_enterprise.h"
}

// WLAN configuration
const char ssid[]     = "eduroam";
const char username[] = "leonar29";
const char password[] = "basicc0ncepts29";

void clearWLAN()
{
  wifi_station_clear_cert_key();
  wifi_station_clear_enterprise_ca_cert();
}

// Init wlan connection
void initWLAN()
{
  WiFi.mode(WIFI_STA);
  wifi_set_opmode(STATION_MODE);

  struct station_config wifi_config;
  memset(&wifi_config, 0, sizeof(wifi_config));
  strcpy((char*)wifi_config.ssid, ssid);
  wifi_station_set_config(&wifi_config);  
  wifi_station_set_wpa2_enterprise_auth(1);
  
  clearWLAN();

  wifi_station_set_enterprise_identity((uint8_t*)username, strlen(username));
  wifi_station_set_enterprise_username((uint8_t*)username, strlen(username));
  wifi_station_set_enterprise_password((uint8_t*)password, strlen(password));
  wifi_station_connect();

  
  while (WiFi.status() != WL_CONNECTED)
  {
    WiFi.printDiag(Serial);
    delay(500);
  }
}

void setup(void)
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  initWLAN();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop(void) { }
