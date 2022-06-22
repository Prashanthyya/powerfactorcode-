#include <LiquidCrystal.h>

/* The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 13
 * LCD D7 pin to digital pin 8
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
/*Constants will not change their value:*/

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pin = 6;  //read pin
int cap1 = 7; //2.5 micro farad capacitor 
int cap2 = 8; //2.5 micro farad capacitor 
int cap3 = 9; //2.5 micro farad capacitor 
int cap4 = 10; //2.5 micro farad capacitor 

double duration,duration1,T=20;
double si,phi;
double power_factor; 

void getpf();

void setup() 
{
lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines,
//lcd.setCursor(0, 1);
//lcd.print("All Capacitor OFF");
lcd.setCursor(0, 0); 
lcd.print("  PF:");
pinMode(pin, INPUT);
Serial.begin(9600);
pinMode(cap1, OUTPUT);
pinMode(cap2, OUTPUT);
pinMode(cap3, OUTPUT);
pinMode(cap4, OUTPUT); 
} 
void loop()
{
 
 getpf();
 lcd.setCursor(8, 0); 
 lcd.print(power_factor);
 if(power_factor < 1)
 {
   lcd.setCursor(0, 1);
   lcd.print("1 capacitor  ON");
   digitalWrite(cap1, HIGH);
   getpf();
   lcd.setCursor(8, 0); 
   lcd.print(power_factor);
   Serial.print("\tThe corrected Power factor is:\t\t\t");
   Serial.println(power_factor);
   lcd.clear();
   //delay(5000);
  if(power_factor <1) 
  { 
    lcd.setCursor(0, 1);
    lcd.print("2 capacitors  ON");
    digitalWrite(cap2, HIGH);
    getpf(); 
    lcd.setCursor(8, 0); 
    lcd.print(power_factor);
    Serial.print("\tThe corrected Power factor is:\t\t\t");
    Serial.println(power_factor);
    lcd.clear();
    //delay(5000);
    if(power_factor <1) 
    {
      lcd.setCursor(0, 1);
      lcd.print("3 capacitors ON");   
      digitalWrite(cap3, HIGH); 
      getpf(); 
      lcd.setCursor(8, 0); 
      lcd.print(power_factor);
      Serial.print("\tThe corrected Power factor is:\t\t\t");
      Serial.println(power_factor);
       //delay(5000);
      
       if(power_factor <1)
       {
        lcd.setCursor(0, 1);
        lcd.print("4 capacitors ON");
        digitalWrite(cap4, HIGH); 
        getpf(); 
        lcd.setCursor(8, 0); 
        lcd.print(power_factor);
        Serial.print("\tThe corrected Power factor is:\t\t\t"); 
        Serial.println(power_factor);        
        //delay(5000);
      
        if(power_factor <1)
       {
        digitalWrite(cap4,HIGH);
        digitalWrite(led,HIGH);
        getpf();
        Serial.println(power factor);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print(" Inductive load "); 
        lcd.setCursor(8, 0); 
        lcd.print(power_factor);
        Serial.print("\tThe corrected Power factor is:\t\t\t"); 
        Serial.println(power_factor);        
        //delay(5000);
       }
       }  
     } 
   } 
  } 
              
  if(power_factor >= 1)
   {
       digitalWrite(cap4,LOW);
       digitalWrite(led,LOW);
       Serial.println(power factor);
       lcd.clear(); 
       lcd.setCursor(8, 0); 
       lcd.print("Resistive load");
       lcd.setCursor(0, 1);
       lcd.print("power factor= ");
       Serial.println(power_factor); 
       //delay(5000);
       
   } 
   
}
                 
                  
                  void getpf()
                  { 
                    duration = pulseIn(pin, HIGH); 
                    duration1=(duration/5000);
                    si=(duration1/20);
                    phi=(si*360); 
                    power_factor=cos(phi/57.2);
                    }
