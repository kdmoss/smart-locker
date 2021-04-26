/* Reference: */ 

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

extern "C" {
  #include "user_interface.h"
  #include "wpa2_enterprise.h"
}

// WLAN configuration
const char *ssid     = "KSU Wireless";
const char *username = "leonar29";
const char *password = "basicc0ncepts29";

// Constants that can be changed based on your hardware or preferences
const int solenoidPin = 2;

// status 
bool locked = true;

ESP8266WebServer server(80);

// Toggle lock status
void toggle()
{
  if (locked)
  {
    digitalWrite(solenoidPin, 1);
    locked = false;
  }
  else
  {
    digitalWrite(solenoidPin, 0);
    locked = true;
  }
  
  server.send(200, "text/html", "<html><head><meta http-equiv=\"refresh\" content=\"0; url=/\" /></head><body></body></html>");
}

// Handler for each url except toggle (just print the button)
void handlePrint()
{
  String html = "<html><head></head><body style=\"margin:10px;\"><a style=\"display: inline-block; height: 30%; background-color: grey; color: white; font-size: 25vmin; font-family: arial; width: 100%; text-align:center; text-decoration: none;\" href=\"/toggle\">";

  if (locked)
  {
    html += "Unlock";
  }
  else
  {
    html += "Lock";
  }

  html += "</a></body></html>";
  server.send(200, "text/html", html);
}

// Init output pin
void initOutput()
{
  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, 0);
}

void clearWLAN()
{
  wifi_station_clear_cert_key();
  wifi_station_clear_enterprise_ca_cert();
  wifi_station_clear_enterprise_identity();
  wifi_station_clear_enterprise_username();
  wifi_station_clear_enterprise_password();
  wifi_station_clear_enterprise_new_password();
}

// Init wlan connection
void initWLAN()
{
  WiFi.mode(WIFI_SATA);
  wifi_set_opmode(STATION_MODE);
  
  struct station_config wifi_config;
  memset(&wifi_config, 0, sizeof(wifi_config));
  strcpy((char*)wifi_config.ssid, ssid);

  clearWLAN();
  
  wifi_station_set_config(&wifi_config);
  wifi_station_set_wpa2_enterprise_auth(1);

  wifi_station_set_enterprise_identity((uint8*)username, strlen(username));
  wifi_station_set_enterprise_username((uint8*)username, strlen(username));
  wifi_station_set_enterprise_password((uint8*)password, strlen(password));
  wifi_station_connect();
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
}

void setup(void)
{
  Serial.begin(115200);
  initOutput();
  initWLAN();
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/toggle", [](){toggle();});
  server.onNotFound(handlePrint);
  server.begin();
}

void loop(void)
{
  server.handleClient();
}
