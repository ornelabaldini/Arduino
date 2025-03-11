Medición de Temperatura y Humedad con Arduino

Este proyecto utiliza un Arduino Uno y un sensor DHT11 para medir la temperatura y la humedad del ambiente. Los valores de temperatura y humedad se muestran en una pantalla LCD 16x2 mediante una interfaz I2C.

Componentes necesarios
Arduino Uno o cualquier placa compatible con Arduino.
Sensor de temperatura y humedad DHT11.
Pantalla LCD 16x2 con interfaz I2C.
Cables de conexión.
Resistencia de 10kΩ (si es necesario para el sensor DHT11).
Protoboard (opcional para conexiones).
Diagrama de conexión
Diagrama básico de las conexiones:

Sensor DHT11:

VCC → 5V (Arduino)
GND → GND (Arduino)
DATA → Pin 2 (Arduino)
Pantalla LCD I2C:

VCC → 5V (Arduino)
GND → GND (Arduino)
SDA → A4 (Arduino Uno)
SCL → A5 (Arduino Uno)
Código
Código necesario para medir la temperatura y la humedad con el sensor DHT11 y mostrar los resultados en una pantalla LCD:

#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Configuración de la pantalla LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definir el pin del sensor DHT11
const int pinDHT = 2;
DHT dht(pinDHT, DHT11);

void setup() {
  lcd.begin(16, 2);  // Inicializa la pantalla LCD con 16 columnas y 2 filas
  lcd.backlight();  // Enciende la retroiluminación de la pantalla
  lcd.setCursor(0, 0);  // Establece el cursor en la primera línea
  dht.begin();  // Inicializa el sensor DHT11

  // Leer los valores de temperatura y humedad
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  // Muestra los valores en la pantalla LCD
  lcd.print("TEMP: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);  // Mueve el cursor a la segunda línea
  lcd.print("HUM: ");
  lcd.print(hum);
  lcd.print(" %");
}

void loop() {
  lcd.backlight();  // Mantiene la retroiluminación encendida
  delay(1000);  // Espera 1 segundo antes de actualizar los datos
}


Librerías utilizadas:

LiquidCrystal_I2C: Para controlar la pantalla LCD a través de la interfaz I2C.
DHT: Para leer los datos de temperatura y humedad del sensor DHT11.
Funcionamiento:

En el setup(), se inicializan la pantalla LCD y el sensor DHT11.
En el loop(), se actualizan los valores de temperatura y humedad cada segundo y se muestran en la pantalla LCD.
