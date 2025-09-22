/*Pinout: Dht-22 module:VCC-5V|Gnd-Gnd|Dat-pin 6
          Oled:VCC-5V|GND-GND|SDA A4|SCK A5
               */

#include <Adafruit_SSD1306.h>   // OLED display library
#include <Adafruit_GFX.h>       // Core graphics library
#include <DHT.h>                // DHT sensor library

// ---- DHT Sensor Setup ----
#define DHTPIN 6          // Data pin from DHT22 connected to Arduino pin 6
#define DHTTYPE DHT22     // Define sensor type (DHT22 / AM2302)
DHT dht(DHTPIN, DHTTYPE); // Create DHT object with pin and type

// ---- OLED Setup ----
#define SCREEN_WIDTH 128   // OLED width
#define SCREEN_HEIGHT 64   // OLED height
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Start serial for debugging
  Serial.begin(9600);

  // Start DHT sensor
  dht.begin();

  // Start OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is common I2C addr
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Halt if display not found
  }

  display.clearDisplay();             // Clear screen
  display.setTextSize(1);             // Normal size
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("DHT22 + OLED"));
  display.display();                  // Show startup text
  delay(2000);                        // Wait 2s
}

void loop() {
  // ---- Read data from DHT22 ----
  float temp = dht.readTemperature();     // Temperature in Celsius
  float hum = dht.readHumidity();         // Humidity %

  // Check if readings are valid
  if (isnan(temp) || isnan(hum)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print to Serial Monitor
  ;Serial.print(F("Temp: "));
  Serial.print(temp);
  Serial.print(F(" °C  Humidity: "));
  Serial.print(hum);
  Serial.println(F(" %"));

  // ---- Display on OLED ----
  display.clearDisplay();        // Clear old data

  display.setTextSize(2);        // Larger font for temp
  display.setCursor(0, 0);
  display.print(temp, 1);        // 1 decimal place
  display.print(" C");

  display.setTextSize(1);        // Smaller font for humidity
  display.setCursor(0, 30);
  display.print("Humidity: ");
  display.print(hum, 1);
  display.println(" %");

  display.display();             // Update screen

  delay(10000); // Wait  10 seconds before next reading
}
