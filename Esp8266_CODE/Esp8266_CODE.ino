#include <ESP8266WiFi.h>

const char* ssid = "your hotspot name";  //enter your hotspot name.
const char* password = "your hotspot password"; //enter your hotspot password.
WiFiServer server(80);

void printWiFiStatus();

void setup(void) {
  Serial.begin(9600);
  WiFi.begin(ssid, password);


  // Start TCP server.
  server.begin();
}

void loop(void) {
  // Check if module is still connected to WiFi.
  if (WiFi.status() != WL_CONNECTED) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
    // Print the new IP to Serial.
    printWiFiStatus();
  }

  WiFiClient client = server.available();

  if (client) {
    while (client.connected()) {
      if (client.available()) {
        String command = client.readStringUntil('\r');
        Serial.print(command);
        if (command == "A") {
          Serial.print("A");
        }
        else if (command == "B") {
          Serial.print("B");
        }
        else if (command == "C") {
          Serial.print("C");
        }
        else if (command == "D") {
          Serial.print("D");
        }
      }
    }
    client.stop();
  }
}

void printWiFiStatus() {
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
