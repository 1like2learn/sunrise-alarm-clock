 #include <LiquidCrystal.h>

 LiquidCrystal lcd(7,8,9,10,11,12);
 
 // Rotary Encoder Inputs
 #define roteEncA 2
 #define roteEncBut 13
 #define roteEncC 4

 int direc = 0;
 bool alarmSet = false;
 int curRoteInput, prevRoteInput;
 int brightness = 80;
 int backlight = 160;
 
 void setup()
 { 
   analogWrite(6, brightness);
   analogWrite(3, backlight);
   lcd.begin(16,2);
   lcd.print(0);
   pinMode (roteEncA,INPUT);
   pinMode (roteEncC,INPUT);
   pinMode (roteEncBut,INPUT);
   Serial.begin (9600);
   prevRoteInput = digitalRead(roteEncA);
 } 
 
 void loop()
 {
   curRoteInput = digitalRead(roteEncA);
  // menu control
  if ((curRoteInput != prevRoteInput) && curRoteInput == 1)
  { 
//    Serial.print("curRoteInput ");
//    Serial.println(curRoteInput);
//    Serial.print("curRoteInput == 1 ");
//    Serial.println(curRoteInput == 1);
//    Serial.print("Prev ");
//    Serial.println(prevRoteInput);
//    Serial.print("digitalRead(roteEncC) ");
//    Serial.println(digitalRead(roteEncC));
    if (digitalRead(roteEncC) != curRoteInput)
    {
      direc--;
    } else
    {
      direc++;
    }
     lcd.clear();
     lcd.print(direc);
    
   
  }
    prevRoteInput = curRoteInput; 
 }
