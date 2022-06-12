#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int sensor=A0;
int nemDurumu=0;
//int motor=6;
//int motorHiz=0;
int lcdEkran=0;
#define motor1R 3
#define motor1L 2
#define motor1E 6
void setup() 
{
Serial.begin(9600);
lcd.begin();
pinMode(sensor,INPUT);
//pinMode(motor,OUTPUT);
pinMode(motor1R,OUTPUT);
pinMode(motor1L,OUTPUT);
pinMode(motor1E,OUTPUT);
}
void loop() 
{
  nemDurumu=analogRead(A0);
  Serial.println(nemDurumu);
  //motorHiz=map(nemDurumu,1023,350,255,0);
  lcdEkran=map(nemDurumu,1023,0,100,0);
  //digitalWrite(motor,motorHiz);
   /*digitalWrite(motor1R,HIGH);
  digitalWrite(motor1L,LOW);
  analogWrite(motor1E,255);*/
 lcd.setCursor(0,0);
 lcd.print("SUSUZLUK ORANI"); 
 lcd.setCursor(0,1);
 lcd.print("      %");
 lcd.setCursor(10,1);
 lcd.print(   lcdEkran); 
 delay(2000);
// ikinci yazı
 lcd.clear();
 lcd.noBacklight(); 
 delay(2000);
 lcd.backlight(); 
 lcd.setCursor(0,0); 
 lcd.print("SAGLIKLI VE IYI");
 lcd.setCursor(0,1); 
 lcd.print("  GUNLER..."); 
 delay(2000);
 lcd.clear();
 if( nemDurumu>=900 &&  nemDurumu<=1100){
  digitalWrite(motor1R,HIGH);
  digitalWrite(motor1L,LOW);
  analogWrite(motor1E,140);
 }
 else{
  digitalWrite(motor1R,HIGH);
  digitalWrite(motor1L,LOW);
  analogWrite(motor1E,0);
 }
}
