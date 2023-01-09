///Diagnostic of  General Purpose INPUTS in Teenscience Platform REVB, R.Hormigo 2020
// Simple  reading GPIs for ICs 15 and IC 16

//These signals are active high
#define GPIO_J26_2 18 
#define GPIO_J26_3 19 
#define GPIO_J27_2 56  
#define GPIO_J27_3 57  
 

 #define GPIO_J31_1 1 
 #define GPIO_J31_3 32  
 #define GPIO_J31_5 31  
 #define GPIO_J31_4 0  


byte GPI[8]={GPIO_J26_2,GPIO_J26_3,GPIO_J27_2,GPIO_J27_3,
             GPIO_J31_1,GPIO_J31_3,GPIO_J31_5,GPIO_J31_4};

void setup() {
 for (byte n=0;n<8;n++)pinMode(GPI[n], INPUT);
  Serial.begin(115200);
  Serial.println("GPI at IC15 and IC16 DIAGNOSTICS  TEENSCIENCE");

} 

void loop() {
  Serial.print("GPI 8 INPUTS: ");
  for (byte n=0;n<8;n++){    
    Serial.print(digitalRead(GPI[n]));
  }
 delay(500); 
 Serial.println("");
}
