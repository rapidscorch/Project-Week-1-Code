#include <LiquidCrystal.h>

// Definitions Arduino pins connected to input H Bridge
int IN1 = A1;
int IN2 = A2;
int IN3 = A3;
int IN4 = A4;
int seconds = 0;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd_1(rs, en, d4, d5, d6, d7);


void setup() {
  // Set the output pins

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  lcd_1.begin(16, 2);
  lcd_1.print("Time");
}

void loop() {
  //lcd
  lcd_1.setCursor(0, 1);
  lcd_1.print(seconds);
  delay(1000);
  seconds += 1;

  if(seconds <=11){
  // go straight
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  }
  else{
  // stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  exit(0);
  }
}
// exit (0) to break
