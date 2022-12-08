#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "Realme";
char pass[] = "12345678";

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLzXYGuSKz"
#define BLYNK_DEVICE_NAME "DKP B"
#define BLYNK_AUTH_TOKEN "VTsHwS9hryUeGHyN0ts62ExHufz-_xWn"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

// defines pins numbers
const int trigPin = 12;  //D6
const int echoPin = 13;  //D7

// defines variables
float duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication
   lcd.init();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hallo, FI KK I ");
  lcd.clear();


}

void loop() {
  Blynk.run();


  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Blynk.virtualWrite(V1, distance);
  lcd.setCursor(0, 0);
  lcd.print("Jarak Pengukuran ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.setCursor(5, 1);
  lcd.print("cm");
  delay(1000);
}