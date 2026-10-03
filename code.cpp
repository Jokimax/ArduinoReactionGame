#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);
int speed = 750;
int speedup = 5;
int maxSpeed = 250;
int score = 0;
int playerPos = -1;
int items [3] = {-1, -1, -1};
bool lost = false;

void setup()
{
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  for (int c = 0; c < 9; c++) {
    pinMode(c, OUTPUT);
  }
  lcd_1.begin(16, 2);
  lcd_1.print("Current Score");
  lcd_1.setCursor(0, 1);
}

void loop()
{
  if(!lost){
    playerPos = -1;
    lcd_1.setCursor(0, 1);
    lcd_1.print(score);
    
    items[2] = items[1];
    items[1] = items[0];
    items[0] = random(0, 3);      
    
    for (int c = 0; c < 9; c++) {
      digitalWrite(c, LOW);
    }
    for (int i = 0; i < 3; i++) {
      if(items[i] != -1) digitalWrite(i * 3 + items[i], HIGH);
    }


    delay(speed);
    if (digitalRead(13) == HIGH) playerPos = 2;
    else if (digitalRead(12) == HIGH) playerPos = 1;
    else if (digitalRead(11) == HIGH) playerPos = 0;
     
    if (items[2] != -1 && playerPos != items[2]){
      lcd_1.setCursor(0, 0);
      lcd_1.print("You lost!    ");
      lost = true;
    }
    
    else if (items[2] != - 1) {
       if(speed > maxSpeed) speed -= speedup;
       score++;
    }
  }
} 