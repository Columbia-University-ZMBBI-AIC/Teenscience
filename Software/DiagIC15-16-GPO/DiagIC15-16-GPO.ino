///Diagnostic of  General Purpose Outs  in Teenscience Platform REVB, R.Hormigo 2020
// Simple sequential writting GPOs with 500mS pulse for ICs 15 and IC 16

//These signals are active high
#define GPIO_J26_3 19 
#define GPIO_J26_2 18  
#define GPIO_J27_3 57  
#define GPIO_J27_2 56  

 #define GPIO_J31_1 1 
 #define GPIO_J31_3 32  
 #define GPIO_J31_5 31  
 #define GPIO_J31_4 0  


byte GPO[8]={GPIO_J26_2,GPIO_J26_3,GPIO_J27_2,GPIO_J27_3,
             GPIO_J31_1,GPIO_J31_3,GPIO_J31_5,GPIO_J31_4};

void setup() {
  for (byte n=0;n<8;n++)pinMode(GPO[n], OUTPUT);
  Serial.begin(115200);
  Serial.println("GPO at IC15 and IC16 DIAGNOSTICS  TEENSCIENCE");

} 

void loop() {
  for (byte n=0;n<8;n++){
    digitalWrite(GPO[n], HIGH);
    Serial.print("GPO");
    Serial.print(n);
    Serial.print(" of 8 ON... ");
    delay(500);
    digitalWrite(GPO[n], LOW);
    Serial.println(" OFF...");
    delay(500); 
  }
}
