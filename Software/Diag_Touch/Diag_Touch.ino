
//Diagnostic of Touch pins interface  in Teenscience Platform REVA, R.Hormigo 2019
//Simple test to sequence read three touch pins

#define TOUCH1 17
//#define TOUCH2 16
//#define TOUCH3 15
#define TOUCH2 29
#define TOUCH3 30
void setup()                    
{
   Serial.begin(115200);
}

void loop()                    
{

    Serial.print("TOUCH: ");                  // print the 3 TeenScience touch sensors in a line to check with Serial Plotter 
    Serial.print(touchRead(TOUCH1));
    Serial.print(" ");
    Serial.print(touchRead(TOUCH2));
    Serial.print(" ");
    Serial.println(touchRead(TOUCH3));

    delay(100);                             // arbitrary delay to limit data to serial port 
}
