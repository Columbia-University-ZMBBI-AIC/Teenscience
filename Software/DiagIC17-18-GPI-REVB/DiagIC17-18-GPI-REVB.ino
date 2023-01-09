///Diagnostic of  General Purpose INPUTS in Teenscience Platform REVB, R.Hormigo 2020
// Simple  reading GPIs for ICs 17 and IC 18


 #define GPIO_J33_1 10 
 #define GPIO_J33_2 12  
 #define GPIO_J33_3 54  
 #define GPIO_J33_4 55  


byte GPI[4]={GPIO_J33_1,GPIO_J33_2,GPIO_J33_3,GPIO_J33_4};

void setup() {
 for (byte n=0;n<4;n++)pinMode(GPI[n], INPUT);
  Serial.begin(115200);
  Serial.println("GPI at IC17 and IC18 DIAGNOSTICS  TEENSCIENCE");
  Serial.println("MAKE SURE DIRECTION IS INPUT, JUMPERS J34 and J40 1-2");

} 

void loop() {
  Serial.print("GPI 4 INPUTS: ");
  for (byte n=0;n<4;n++){    
    Serial.print(digitalRead(GPI[n]));
  }
 delay(500); 
 Serial.println("");
}
