
#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <LiquidCrystal.h>

TinyGPS gps;
SoftwareSerial sgps(A1, A0);  // GPS RX, TX
SoftwareSerial sgsm(8, 9);    // GSM RX, TX
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define MOTOR A2
#define S1 A4
#define S2 10
#define BUZZER 13

float lat, lon;
bool alertSent = false;
const char PHONE[] = "8600654962";

void setup() {
  lcd.begin(16, 2);

  pinMode(MOTOR, OUTPUT);
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(MOTOR, LOW);  // Motor ON (relay assumed active LOW)
  digitalWrite(BUZZER, LOW);

  sgps.begin(9600);
  sgsm.begin(9600);

  lcd.print("Rail Track Robot");
  delay(2000);
  sgps.listen();
}

void loop() {
  sgps.listen();

  while (sgps.available())
    gps.encode(sgps.read());

  unsigned long age;
  gps.f_get_position(&lat, &lon, &age);

  bool s1 = digitalRead(S1) == LOW;
  bool s2 = digitalRead(S2) == LOW;

  if (s1 || s2) {
    digitalWrite(MOTOR, HIGH); // Stop motor
    digitalWrite(BUZZER, HIGH);

    lcd.clear();
    lcd.print("TRACK FAULT!");
    lcd.setCursor(0, 1);
    lcd.print("Motor Stopped");

    if (!alertSent) {
      digitalWrite(BUZZER, LOW);
      sgsm.listen();

      sgsm.println("AT");
      delay(1000);
      sgsm.println("AT+CMGF=1");
      delay(1000);

      sgsm.print("AT+CMGS=\"");
      sgsm.print(PHONE);
      sgsm.println("\"");
      delay(1000);

      sgsm.print("Rail Track Fault! ");

      if (age < 5000 && lat != 0 && lon != 0) {
        sgsm.print("Location: https://maps.google.com/?q=");
        sgsm.print(lat, 6);
        sgsm.print(",");
        sgsm.print(lon, 6);
      } else {
        sgsm.print("GPS location unavailable.");
      }

      sgsm.write(26);
      delay(3000);

      alertSent = true;
      sgps.listen();
    }
  } else {
    digitalWrite(MOTOR, LOW);
    digitalWrite(BUZZER, LOW);
    alertSent = false;

    lcd.clear();
    lcd.print("Track Normal");
  }

  delay(200);
}
