 #include <LiquidCrystal.h>

 LiquidCrystal lcd(7,8,9,10,11,12);
 
 // Rotary Encoder Inputs
 #define roteEncA 2
 #define roteEncBut 13
 #define roteEncC 4

 int direc = 0;
 int menuIndex = 0;
 unsigned long curTime = 1200;
 int alarm = 1200;
 bool alarmSet = false;
 int curRoteInput, prevRoteInput;
 String mainMenu[] = {"Disable Alarms", "Alarm Time", "Time", "Show Cycle", "Select Cycle", "Cycle Length", "Snooze Length"};
 unsigned long previousMillis = 0;
 int interval = 1000; // 60000 in a minute 3,600,000 in an hour 43,200,000 in 12 hours
 int brightness = 80;
 int backlight = 160;
 
 void setup()
 { 
   analogWrite(6, brightness);
   analogWrite(3, backlight);
   lcd.begin(16,2);
   pinMode (roteEncA,INPUT);
   pinMode (roteEncC,INPUT);
   lcd.print(mainMenu[0]);
   Serial.begin (9600);
   prevRoteInput = digitalRead(roteEncA);
 } 
 
 void loop()
 {
   curRoteInput = digitalRead(roteEncA);

  // time measurement
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;                                                        
  }
  // menu control
  if (curRoteInput != prevRoteInput && curRoteInput == 1)
  { 
    lcd.clear();
    if (digitalRead(roteEncA) != curRoteInput && roteEncA == HIGH)
    {
      direc = -1;
    } else
    {
      direc = 1;
    }
    menuIndex += direc;
   if (menuIndex > 6)
   {
     menuIndex = 0;
   } else if (menuIndex < 0)
   {
     menuIndex = 6;
   }
   direc = 0;
   lcd.print(mainMenu[menuIndex]);
    
  }
  prevRoteInput = curRoteInput; 
 }
