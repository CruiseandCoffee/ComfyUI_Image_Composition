#include <Adafruit_NeoPixel.h> // Librería necesaria, instalarla desde el gestor de librerías

Adafruit_NeoPixel LED_RGB(1, 48, NEO_GRBW + NEO_KHZ800); // Creamos el objeto que manejará el led rgb PIO48

void setup() {
  LED_RGB.begin();            // Inicia el objeto que hemos creado asociado a la librería NeoPixel
  LED_RGB.setBrightness(150); // Para el brillo del led
}

void loop() {
  LED_RGB.setPixelColor(0, uint32_t(LED_RGB.Color(255, 0, 0))); // Encendemos el led rojo
  LED_RGB.show();                                               // Enciende el color
  delay(2000);                                                  // Pausa de un segundo

  LED_RGB.setPixelColor(0, uint32_t(LED_RGB.Color(0, 255, 0))); // Encendemos el led verde
  LED_RGB.show();                                               // Enciende el color
  delay(2000);                                                  // Pausa de un segundo

  LED_RGB.setPixelColor(0, uint32_t(LED_RGB.Color(0, 0, 255))); // Encendemos el led azul
  LED_RGB.show();                                               // Enciende el color
  delay(2000);                                                  // Pausa de un segundo
}
