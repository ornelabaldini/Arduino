#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinDHT = 2;
DHT dht(pinDHT, DHT11);


void setup() {
  lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light
  lcd.setCursor(0, 0);
  dht.begin();
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  lcd.print("TEMP: ");
  lcd.print(temp);
  lcd.print(" G");
  lcd.setCursor(0, 1);
  lcd.print("HUM: " );
  lcd.print(hum);
  lcd.print(" %");
}

void loop() {
  lcd.backlight();
  delay(1000);
}
