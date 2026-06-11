#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//https://lastminuteengineers.com/oled-display-esp8266-tutorial/
//https://forum.arduino.cc/t/cant-find-my-wemos-d1-mini-in-device-type-list/1219091/2
//https://randomnerdtutorials.com/esp8266-web-server/
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(2, 28);
  display.println("Hello worlds!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display Inverted Text
  display.setTextColor(BLACK, WHITE);  // 'inverted' text
  display.setCursor(0, 28);
  display.println("Hello worldss!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("hellsso");
  delay(1000);
  display.clearDisplay();
}
