//Diagnostic of Power General Purpose Outs  in Teenscience Platform REVB, R.Hormigo 2020
// Simple sequential writting for solenoids with initial pulse and holding at 33% power at PWM ports

//These signals are active high
#define GPO1 35  //This GPO Supports PWM "analog"
#define GPO2 36  //This GPO Supports PWM "analog"
#define GPO3 39
#define GPO4 40
#define GPO5 37  //This GPO Supports PWM "analog"
#define GPO6 38  //This GPO Supports PWM "analog"
#define GPO7 41
#define GPO8 42

byte GPO[8]={GPO1,GPO2,GPO3,GPO4,GPO5,GPO6,GPO7,GPO8};

void setup() {
  for (byte n=0;n<8;n++)pinMode(GPO[n], OUTPUT);
  Serial.begin(115200);
  Serial.println("GPO DIAGNOSTICS  TEENSCIENCE");

} 
#define ON 255
#define HOLD 90
#define OFF 0
void loop() {
  for (byte n=0;n<8;n++){
    analogWrite(GPO[n], ON);
    Serial.print("GPO");
    Serial.print(n+1);
    Serial.print(" ON... ");
    delay(200);
    if (n==0 || n==1 || n==4 || n==5){  //There are only PWM "analog" in these PGPOs, others are ON/OFF
      analogWrite(GPO[n], HOLD);
      Serial.print(" HOLD 33%... ");
    }
    delay(1000);
    analogWrite(GPO[n], OFF);
    Serial.println(" OFF...");
    delay(1000); 
  }
}
