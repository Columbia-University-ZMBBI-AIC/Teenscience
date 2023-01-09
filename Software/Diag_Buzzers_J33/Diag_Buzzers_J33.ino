//Diagnostic of J33 Buzzer/LED outs Outs (also could be set as GPI)   in Teenscience Platform REVA, R.Hormigo 2019
//Simple buzzer ext spk control
//Use UP / DW / SEL buttons to control  

#define SEL_RD analogRead(A10)<0x3F
#define DW_RD analogRead(A11)<0x3F
#define UP_RD analogRead(A3)<0x3F


//These signals are active high
#define  IBUZZ_P 10 
#define  IBUZZ_N 12
#define  EBUZZ_P 54 
#define  EBUZZ_N 55


void setup() {
  pinMode(IBUZZ_P, OUTPUT);
  pinMode(IBUZZ_N, OUTPUT);
  pinMode(EBUZZ_P, OUTPUT);
  pinMode(EBUZZ_N, OUTPUT);
  Serial.begin(115200);
  delay(100);
  Serial.println("BUZZER DIAGNOSTICS  TEENSCIENCE");

} 
//Music Ext buzzer
unsigned int tones[8]={62, 125, 250, 500, 1000, 2000, 4000, 8000};
byte toneSel=0;
void loop() {
  if (UP_RD && toneSel<7){
    toneSel++;
    tone(EBUZZ_P, tones[toneSel]);
    Serial.print("TONE: "); 
    Serial.println(tones[toneSel]); 
    delay(200);
  }
  else if (DW_RD && toneSel>0){
    toneSel--;
    tone(EBUZZ_P, tones[toneSel]);
    Serial.print("TONE: "); 
    Serial.println(tones[toneSel]); 
    delay(200);
  }
  else if (SEL_RD){
    noTone(EBUZZ_P); //Mute
    delay(200);
    Serial.println("MUTE"); 
  }
}
