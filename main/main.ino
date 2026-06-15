//https://lastminuteengineers.com/oled-display-esp8266-tutorial/
//https://forum.arduino.cc/t/cant-find-my-wemos-d1-mini-in-device-type-list/1219091/2
//https://randomnerdtutorials.com/esp8266-web-server/

//https://api.spot-hinta.fi/swagger/ui
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//tarvitaan rajapintaaan
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>

#include "secret.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASSWORD;
unsigned long lastRequest = 18000;
const long interval = 300000;

WiFiServer server(80);

void getData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClientSecure client;
    client.setInsecure();
    http.begin(client, "https://api.spot-hinta.fi/JustNow");

    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);

      StaticJsonDocument<1024> doc;

      DeserializationError error = deserializeJson(doc, payload);
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.f_str());
        http.end();
        return;
      } 
      float price = doc["PriceWithTax"];

      display.clearDisplay();
      display.drawPixel(50, 50, WHITE);
      
      display.setTextSize(1);
      display.setCursor(32, 20);
      display.print("Price: ");

      display.setTextSize(2);
      display.setCursor(32, 40);

      display.print(price);
      display.display();
      http.end();
    } else {
      Serial.println("HTTP request failed!");
    }
  }
}

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
  //pinMode(LED, OUTPUT);

  Serial.print("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  server.begin();  // Starts the Server
  Serial.println("Server started");

  // Display Inverted Text
  display.setTextColor(WHITE);  // 'inverted' text
  display.setCursor(60, 20);
  display.println("Hello");
  display.setCursor(60, 35);
  display.println("world!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // put your setup code here, to run once:
  getData();
}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.print("hellsso");
 // delay(1000);
 // display.clearDisplay();
  if (millis() - lastRequest >= interval) {
    lastRequest = millis();
    getData();
    Serial.print("new request");
  }
}



