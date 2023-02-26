#define echoPin 10
#define trigPin 9
#include <WiFiClient.h>
// #include <ArduinoJson.h>

WiFiClient client;
StaticJsonDocument<200> doc;

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* host = "f8e1-192-58-125-226.ngrok.io";
const int port = 80;

long duration;
long distance;

WiFiClient client;
StaticJsonDocument<200> doc;

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Wait for Serial to connect
  while (!Serial);

  pinMode(echoPin, INPUT);
  pinMode(trigPin,OUTPUT);
}

void loop() {
  // Read the distance sensor
  int distance = readDistanceSensor();

  // Build the JSON payload
  doc.clear();
  doc["distance"] = distance;
  String payload;
  serializeJson(doc, payload);

  // Send the request
  if (client.connect(host, port)) {
    client.println("POST / HTTP/1.1");
    client.println("Host: " + String(host));
    client.println("Content-Type: application/json");
    client.println("Content-Length: " + String(payload.length()));
    client.println();
    client.println(payload);
    delay(100);
    client.stop();
  }

  delay(1000);
}

int readDistanceSensor() {

 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);
 
 distance = duration/58.2;

 Serial.println(distance);

 delay(1000);

}