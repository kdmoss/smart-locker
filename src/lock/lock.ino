/* Reference: */ 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

extern "C" 
{
  #include "user_interface.h"
  #include "wpa2_enterprise.h"
}

ESP8266WebServer server(80);

// WLAN configuration
const char ssid[]     = "linksys";
const char password[] = "password";
// Lock configuration
boolean locked = false;

void handleRoot()
{
  String html = "<html><head></head><body style=\"margin:10px;\"><a style=\"display: inline-block; height: 30%; background-color: grey; color: white; font-size: 25vmin; font-family: arial; width: 100%; text-align:center; text-decoration: none;\" href=\"/toggle\">";

  if (locked) html += "Unlock";
  else html += "Lock";

  html += "</a></body></html>";
  server.send(200, "text/htmls", html);
}

void handleNotFound()
{
  server.send(404, "text/plain", "Not Found");
}

void handleLogin()
{
  server.send(200, "text/plain", "Login");
}

void handleToggle()
{
  digitalWrite(solenoidPin, (int)locked);
  locked = !locked;
}

void initLock()
{
  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, 0);
}

void initWLAN()
{
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Diagnostics: ");
    WiFi.printDiag(Serial);
    Serial.println("-------------");
  }

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void initServer()
{
  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.on("/toggle", handleToggle);
  server.onNotFound(handleNoteFound);
}

void setup(void)
{
  Serial.begin(115200);
  initLock();
  initWLAN();
  initServer();
}

void loop(void) 
{ 
  server.handleClient();
}
