#include <LiquidCrystal_I2C.h> //Library LCD
#include <MQ7.h> //LIbrary MQ7
#include <MQ135.h> //LIbrary MQ135


//Definisikan pin sensor yang digunakan
MQ135 mq135(A3);
MQ7 mq7(A2,5.0);

// Variabel untuk menyimpan data dari sensor
float ppmCO2, ppmCO;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); 
  lcd.backlight();

//Tulisan awal saat dinyalakan
  lcd.setCursor(0, 0);
  lcd.print("Air Qlty Sensor");
  lcd.setCursor(6, 1);
  lcd.print("by YM-Pro");
  delay(5000);
  lcd.clear();

}

void loop() {
  ppmCO = mq7.getPPM();
  lcd.setCursor(0, 0);
  lcd.print("CO:");
  lcd.print(ppmCO);
  lcd.print(" ppm");

  ppmCO2 = mq135.getPPM();
  lcd.setCursor(0, 1);
  lcd.print("CO2:");
  lcd.print(ppmCO2);
  lcd.print(" ppm");

  conclusion(ppmCO, ppmCO2);

  delay(2000);
  lcd.clear();
}

void conclusion(float co, float co2){
  const float batasCO = 25;
  const float batasCO2 = 30000;

  if (co <= batasCO && co2 <= batasCO2) {
    lcd.setCursor(15, 0);
    lcd.print("G");
  } else {
    lcd.setCursor(14, 0);
    lcd.print("NG");
  }
}
