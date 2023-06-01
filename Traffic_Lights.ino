#include <LiquidCrystal.h>
int val;
int state;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()  {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  val = analogRead(A0);
  if (val > 100)  {
  Serial.println("It is quite light!");
  digitalWrite(7,LOW);
  }
  else if (val < 100)  {
    Serial.println("It is pretty dark!");
    lcd.autoscroll();
    lcd.print("00:05");
    Serial.println("5");
    delay(1000);
    lcd.print("00:04");
    Serial.println("4");
    delay(1000);
    lcd.print("00:03");
    Serial.println("3");
    delay(1000);
    lcd.print("00:02");
    Serial.println("2");
    delay(1000);
    lcd.print("00:01");
    Serial.println("1");
    delay(1000);
    lcd.print("00:00");
    Serial.println("0");
    digitalWrite(7, HIGH);
    delay(5000);
    lcd.clear();
  }
}