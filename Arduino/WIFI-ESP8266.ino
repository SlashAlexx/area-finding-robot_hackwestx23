#include <ESP8266WiFi.h>

const char* ssid = "TTUguest";
const char* password = "diplomaticthreshold";
const char* host = "f8e1-192-58-125-226.ngrok.io";
const int port = 80;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
}

void loop() {
  String json = distance();
  
  WiFiClient client;
  if (client.connect(host, port)) {
    Serial.println("Connected to server");
    client.print("POST / HTTP/1.1\r\n");
    client.print("Host: ");
    client.println(host);
    client.print("Content-Type: application/json\r\n");
    client.print("Content-Length: ");
    client.println(json.length());
    client.print("\r\n");
    client.print(json);
    Serial.println("Request sent");
    delay(5000);
  } else {
    Serial.println("Failed to connect to server");
  }
}
