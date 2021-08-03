#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//선언
#include <DHT.h>
//모델명이 DHT11
DHT dht(6, DHT11);
float temp;
float humid;

void setup() {
  lcd.init();
  Serial.begin(115200);
  Serial.print("ready");
  dht.begin();
  
}

void loop() {
  temp = dht.readTemperature();
  humid = dht.readHumidity();
  Serial.print("temp="); Serial.print(temp);
  Serial.print(",humid="); Serial.println(humid);
  lcd.backlight();
  lcd.print(temp);
  lcd.print(","); lcd.print(humid);
  delay(500);
  lcd.clear();
}
