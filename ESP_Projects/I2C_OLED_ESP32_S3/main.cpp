#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C pins for ESP32-S3
#define I2C_SDA 8
#define I2C_SCL 9

// Create display object
#define OLED_RESET -1 // No reset pin
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Helper function to center text on OLED
void centerText(String text) {
  int16_t x1, y1;
  uint16_t w, h;

  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

  int16_t x = (SCREEN_WIDTH - w) / 2;
  int16_t y = (SCREEN_HEIGHT - h) / 2;

  display.setCursor(x, y);
  display.print(text);
}

void setup() {
  // Start I2C with custom pins
  Wire.begin(I2C_SDA, I2C_SCL);

  // Initialize Serial Monitor (optional)
  Serial.begin(115200);
  delay(1000);

  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is common I2C address
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ; // Loop forever if display fails
  }

  // Clear the display
  display.clearDisplay();

  // Set text properties
  display.setTextSize(1);              // 1 = default size
  display.setTextColor(SSD1306_WHITE); // White text

  // Centered text
  String text = "There's no moutain too great!";
  centerText(text);

  display.display(); // Push to screen
}

void loop() {
  // Nothing to do here
}
