/* Reference: */ 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

ESP8266WebServer server(80);
HTTPClient http;

// Apache configuration
const char domain[] = "http://192.168.0.84";
const int port = 80;

// WLAN configuration
const char ssid[] = "MOSS 2G";
const char password[] = "G4m3rz0n3";

// Lock configuration
boolean locked = false;
int solenoidPin = 2;

void handleRoot()
{
  String html = "<html><head></head><body style=\"margin:10px;\"><a style=\"display: inline-block; height: 30%; background-color: grey; color: white; font-size: 25vmin; font-family: arial; width: 100%; text-align:center; text-decoration: none;\" href=\"/toggle\">";

  if (locked) html += "Unlock";
  else html += "Lock";

  html += "</a></body></html>";
  server.send(200, "text/html", html);
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
  String html = "<html><head><meta http-equiv=\"refresh\" content=\"0; url=/\" /></head><body></body></html>";
  digitalWrite(solenoidPin, (int)locked);
  locked = !locked;
  
  server.send(200, "text/html", html);
}

void handleDomainResponse()
{
  int responseCode = http.GET();

  if (responseCode > 0)
  {
    Serial.println("HTTP Response: ");
    Serial.println("---------------");
    Serial.println(http.getString());
    Serial.println("---------------");
  }
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
    Serial.println("-------------");
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
  server.onNotFound(handleNotFound);
  server.begin();
  http.begin(domain);
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
  handleDomainResponse();
}
