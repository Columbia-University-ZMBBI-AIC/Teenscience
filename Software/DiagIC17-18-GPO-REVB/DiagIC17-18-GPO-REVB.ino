///Diagnostic of  General Purpose Outs and SPEAKER in Teenscience Platform REVB, R.Hormigo 2020
// Simple sequential writting GPOs with pulse for ICs 17 and IC 18

#define GPIO_J33_1 10 
 #define GPIO_J33_2 12  
 #define GPIO_J33_3 54  
 #define GPIO_J33_4 55  


byte GPO[4]={GPIO_J33_1,GPIO_J33_2,GPIO_J33_3,GPIO_J33_4};


void setup() {
  for (byte n=0;n<4;n++)pinMode(GPO[n], OUTPUT);
  Serial.begin(115200);
  Serial.println("GPO at IC17 and IC18 DIAGNOSTICS  TEENSCIENCE");
  Serial.println("MAKE SURE DIRECTION IS OUTPUT, JUMPERS J34 and J40 2-3");

} 
//Music Ext buzzer
unsigned int tones[8]={62, 125, 250, 500, 1000, 2000, 4000, 8000};
void loop() {
  for (byte n=0;n<4;n++){
    digitalWrite(GPO[n], HIGH);
    Serial.print("GPO");
    Serial.print(n+1);
    Serial.print(" of 4 ON... ");
    delay(500);
    digitalWrite(GPO[n], LOW);
    Serial.println(" OFF...");
    delay(500); 
  }
//SPEAKER
  for (byte n=0;n<8;n++){
    tone(GPIO_J33_1, tones[n]);
    Serial.print("TONE: "); 
    Serial.println(tones[n]); 
    delay(500);
  }
  noTone(GPIO_J33_1); //Mute
  Serial.println("MUTE"); 
}
