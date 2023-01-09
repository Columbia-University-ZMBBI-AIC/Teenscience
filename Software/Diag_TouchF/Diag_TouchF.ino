
//Diagnostic of Touch pins interface  in Teenscience Platform REVA, R.Hormigo 2019
//Simple test to sequence read three touch pins
#include "TeensyThreads.h"  //Use separated thread to run Touch and avoid delay
#define TOUCH1 17
#define TOUCH2 16
#define TOUCH3 15
volatile int t1, t2, t3; //Global Touch sensor values

void touchThread() {
    while(1) {
      t1=touchRead(TOUCH1);
      threads.delay(20); 
      t2=touchRead(TOUCH2);
      threads.delay(20); 
      t3=touchRead(TOUCH3);
      threads.delay(20); 
      threads.yield(); 
    }  
}

void setup()                    
{
   Serial.begin(9600);
   threads.addThread(touchThread);
   threads.setSliceMicros(50);
}
  //  unsigned long tMark=0;
 //   unsigned long oMark=0;
void loop()                    
{
  //  oMark = tMark;
  //  tMark = (micros());
  //  if ((tMark-oMark)>550){
  //    Serial.print(tMark-oMark);
  //    Serial.print(" "); 
  //  }
  //print the 3 TeenScience touch sensors in a line to check with Serial Plotter 
    Serial.print(t1);
    Serial.print(" ");
    Serial.print(t2);
    Serial.print(" ");
    Serial.println(t3);
    delayMicroseconds(50000);// arbitrary delay to limit data to serial port 
}
