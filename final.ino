#include <LiquidCrystal.h>
#include <DHT.h>
#include <Servo.h>

Servo myServo;
Servo myServo1;
#define LDR A0
unsigned int value;

DHT dht(7, DHT11);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//(RS, E, D4, D5, D6, D7)

void setup() {
      dht.begin();
      lcd.begin(16, 2);
      Serial.begin(9600);
      pinMode(8,OUTPUT);
      pinMode(9,OUTPUT);//led1
      pinMode(10,OUTPUT);//led2
      pinMode(LDR, INPUT);
      //myServo.attach(9);  
      //myServo1.attach(10); 
}

void loop() {
  float h = dht.readHumidity();
   float t = dht.readTemperature();
   lcd.setCursor(0, 0);
   lcd.print("Hum: ");
   lcd.println(h);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.println(t);
  Serial.print("Humidity: ");
   Serial.println(h);
   Serial.print("Temperature: ");
   Serial.println(t);
   value = analogRead(LDR);
   Serial.println(value);
   if (h>=60 and value<=900 and value>=800)
   {
    digitalWrite(8,0);
    delay(3000);
    digitalWrite(9,1);
    digitalWrite(10,1);
    //myServo.writeMicroseconds(2000);  
    //myServo1.writeMicroseconds(2000);  
    delay(2000); 
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,0);
    delay(1000);
    digitalWrite(9,1);
    digitalWrite(10,1);
    delay(2000);
    digitalWrite(9,0);
    digitalWrite(10,0);
    delay(1000);
   }
   else
   {
    digitalWrite(8,1);
    digitalWrite(10,0);
    digitalWrite(9,0);
    delay(1000); 
    }
  delay(1000);
}
