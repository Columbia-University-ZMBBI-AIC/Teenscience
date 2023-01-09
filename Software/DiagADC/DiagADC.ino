///Diagnostic of ADC INPUTS from Instrumentation Amplifier and user Pot in Teenscience Platform REVA, R.Hormigo 2020
// Simple  reading ADC ports

#define INST1 A6 // INST1 is J15 header
#define INST2 A7 // INST2 is J16 header
 
#define POT A0 // POT is R134



byte ADCp[3]={INST1, INST2, POT};
String ADCs[3]={"INST1: ", " INST2: ", " POT: "};
void setup() {
// for (byte n=0;n<3;n++)pinMode(, INPUT);
  Serial.begin(115200);
  Serial.println("ADC values DIAGNOSTICS  TEENSCIENCE");

} 

void loop() {
  Serial.print("ADC INPUTS ");
  for (byte n=0;n<3;n++){  
    Serial.print(ADCs[n]); 
    Serial.print(analogRead(ADCp[n]));
  }
 delay(500); 
 Serial.println("");
}
