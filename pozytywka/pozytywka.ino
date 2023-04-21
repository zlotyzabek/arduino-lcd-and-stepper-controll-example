//THIS MEGA ADVANCED CODE IS ONE DAY GONNA TAKE OVER DA WORLDDDDDDDDDDDDDDDDDDDd
//TRUST ME, MY C CODE IS ALWAYS SAFE AND I NEVER EXPERIENCE MEMORY LEAKS LOL
#include <Stepper.h> // THIS THING IS SO FREAKIN' INEFFICIENT
#include <LiquidCrystal.h>
#include <Keypad.h>

const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 6, 7, 8, 9);
int stepCount = 0;


const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 1, 13}; //connect to the column pinouts of the keypad
const int rs = 12, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int period = 2000;
unsigned long time_now = 0;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(11, OUTPUT);
  lcd.begin(16, 2);

}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1090, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);
  }
  if (time_now + 12000 <= millis()){
    time_now = millis();
    lcd.setCursor(0, 0);
    lcd.print("   POZYTYWKA");
    lcd.setCursor(0, 1);
    lcd.print("Adam         ");
    }
   else if (time_now + 9000 <= millis()){
    lcd.setCursor(0, 0);
    lcd.print("   POZYTYWKA");
    lcd.setCursor(0, 1);
    lcd.print("Piotr        ");
    }
   else if (time_now + 6000 <= millis()){
    lcd.setCursor(0, 0);
    lcd.print("   POZYTYWKA");
    lcd.setCursor(0, 1);
    lcd.print("Tomek          ");
    }
   else if (time_now + 3000 <= millis()){
    lcd.setCursor(0, 0);
    lcd.print("   POZYTYWKA");
    lcd.setCursor(0, 1);
    lcd.print("Anastasiia    ");
    }
   else if (time_now <= millis()){
    lcd.setCursor(0, 0);
    lcd.print("   POZYTYWKA");
    lcd.setCursor(0, 1);
    lcd.print("Pani Edyta     ");
    }
    
}
