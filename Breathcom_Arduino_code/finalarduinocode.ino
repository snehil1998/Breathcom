#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();
double dx=0.0, dy=0.0, dz=0.0;
int long t = 0;
double offset;
double newacc, sub_acc, acc_diff;
double arr[10];
double rollingaverage=0;
int i=0, j=0, k=0;
double sum=0;
bool check = false;
bool start = true;
String code = "";
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(void) {
  Serial.begin(9600);  

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  
  mma.setRange(MMA8451_RANGE_2_G);
  lcd.begin(20, 4);
  lcd.setCursor(0, 1);
  delay(2000);
  lcd.clear();
  lcd.print("START BREATHING");
  Serial.println("START BREATHING");
//  Serial.println("22");
}

void loop() {
  
 if(start == true){
  mma.read();
  
  ++t;
  if(t==1){offset = (float)mma.z/(float)16384;} 

  newacc = ((float)((float)mma.z/(float)16384)-offset)*1000;
  //Serial.println(newacc);
  if(j==0){sub_acc = newacc;}
  acc_diff = abs(newacc - sub_acc);
  //Serial.println(acc_diff);
  //Serial.println(j);
          if(j <250)
          {
            if(acc_diff >12)
            check = true;
          }
          else if(j == 250){
            if(check == true){
              code+= "-";
            }
            else{
              code += ".";
            }
            k++;
            check = false;
            Serial.println("STOP BREATHING"); 
            lcd.setCursor(0, 1);
            lcd.clear();
            lcd.print("STOP BREATHING");
            lcd.setCursor(1, 1);
            lcd.print(code);
            Serial.println(code);
            delay(1000);
            if(k<4){//Serial.println("22");
              Serial.println("BREATHE NOW");}
            lcd.setCursor(0, 1);
            lcd.clear();
            if(k<4){lcd.print("BREATHE NOW!");}
            j = -1;
          }

          if(k==4){
            //Serial.println("Printing word!");
            //lcd.setCursor(0, 1);
            //lcd.print("Printing word!");
            //Serial.println(code);
            convertor();
            start = false;
          }
          j++;
        delay(10);
        }        
  
}


void convertor()
{
  static String letters[] = {"----", "---.", "--.-", "--..", "-.--", "-.-.", "-..-", "-...", ".---", ".--.", ".-.-", ".-..", "..--", "..-.", "...-", "...."};
  
      if (letters[0] == code){
        //----
        delay(1000);
        Serial.println("0");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("I WANT TO SLEEP");
        Serial.println("I WANT TO SLEEP");}
      
      else if(letters[1] == code){
        //---.
        delay(1000);
        Serial.println("1");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("I WANT TO USE THE WASHROOM");
        Serial.println("I WANT TO USE THE WASHROOM");
        delay(5000);
        lcd.clear();}
        
      else if(letters[2] == code){
        //--.-
        delay(1000);
        Serial.println("2");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("I NEED SOME WATER");
        Serial.println("I NEED SOME WATER");
        delay(5000);
        lcd.clear();}
        
      else if(letters[3] == code){
        //--..
        delay(1000);
        Serial.println("3");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("I AM HUNGRY");
        Serial.println("I AM HUNGRY");
        delay(5000);
        lcd.clear();}
        
      else if(letters[4] == code){
        //-.--
        delay(1000);
        Serial.println("4");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("I DON'T FEEL WELL");
        Serial.println("I DON'T FEEL WELL");
        delay(5000);
        lcd.clear();}
        
      else if(letters[5] == code){
        //-.-.
        delay(1000);
        Serial.println("5");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("PLEASE LEAVE");
        Serial.println("PLEASE LEAVE");
        delay(5000);
        lcd.clear();}
        
      else if(letters[6] == code){
        //-..-
        delay(1000);
        Serial.println("6");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("CHANGE MY CLOTHES");
        Serial.println("CHANGEMY CLOTHES");
        delay(5000);
        lcd.clear();}
        
      else if(letters[7] == code){
        //-...
        delay(1000);
        Serial.println("7");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("YES");
        Serial.println("YES");
        delay(5000);
        lcd.clear();}
        
      else if(letters[8] == code){
        //.---
        delay(1000);
        Serial.println("8");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("NO");
        Serial.println("NO");
        delay(5000);
        lcd.clear();}
        
      else if(letters[9] == code){
        //.--.
        delay(1000);
        Serial.println("9");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("I LOVE YOU!");
        Serial.println("I LOVE YOU!");
        delay(5000);
        lcd.clear();}
        
      else if(letters[10] == code){
        //.-.-
        delay(1000);
        Serial.println("10");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("TAKE ME FOR A STROLL");
        Serial.println("TAKE ME FOR A STROLL");
        delay(5000);
        lcd.clear();}
        
      else if(letters[11] == code){
        //.-..
        delay(1000);
        Serial.println("11");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("READ ME THE NEWS");
        Serial.println("READ ME THE NEWS");
        delay(5000);
        lcd.clear();}
        
      else if(letters[12]== code){
        //..--
        delay(1000);
        Serial.println("12");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("SOS!");
        Serial.println("SOS");
        delay(5000);
        lcd.clear();}
        
      else if(letters[13] == code){
        //..-.
        delay(1000);
        Serial.println("13");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("FEED ME MY MEDICINES");
        Serial.println("FEED ME MY MEDICINES");
        delay(5000);
        lcd.clear();}
        
      else if(letters[14] == code){
        //...-
        delay(1000);
        Serial.println("14");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("PLAY MUSIC/TV");
        Serial.println("PLAY MUSIC/TV");
        delay(5000);
        lcd.clear();}
        
      else if(letters[15] == code){
        //....
        delay(1000);
        Serial.println("15");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("HI! HOW ARE YOU?");
        Serial.println("HI! HOW ARE YOU?");
        delay(5000);
        lcd.clear();}
        
      else{
        delay(1000);
        Serial.println("INCORRECT INPUT");
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("INCORRECT INPUT");
        delay(5000);
        lcd.clear();}
    
  code = "";                            //reset code to blank string
}
