#include<NewPing.h>
#include<NewTone.h>

int r;
#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int speaker = 8;



//the buttons:

const int b1=4;
const int b2=5;
const int b3=6;
const int b4=7;
//variables to store previous button press and currend button press , used to eliminate switch bouncing
boolean pb1=LOW;
boolean cb1=LOW;

boolean pb2=LOW;
boolean cb2=LOW;

boolean pb3=LOW;
boolean cb3=LOW;

boolean pb4=LOW;
boolean cb4=LOW;


//variables to store numbers:

int w=0;
int x=0;
int y=0;
int z=0;

void setup() {
  // put your setup code here, to run once:
      Serial.begin(115200);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
}



boolean debounce1(boolean last1)
{
   boolean current1=digitalRead(b1);
  if(last1 != current1)
  {
      delay(5);
    }
      current1=digitalRead(b1);
      return current1;  
  }

boolean debounce2(boolean last2)
{
   boolean current2=digitalRead(b2);
  if(last2 != current2)
  {
      delay(5);
    }
      current2=digitalRead(b2);
      return current2;  
  }

  boolean debounce3(boolean last3)
{
   boolean current3=digitalRead(b3);
  if(last3 != current3)
  {
      delay(5);
    }
      current3=digitalRead(b3);
      return current3;  
  }

  boolean debounce4(boolean last4)
{
   boolean current4=digitalRead(b4);
  if(last4 != current4)
  {
      delay(5);
    }
      current4=digitalRead(b4);
      return current4;  
  }




  

void check(int y,int a, int b, int c, int d)
{
  
  if(y<60&&y>0)
  {
    NewTone(speaker,1000,10000);
  }   

  if(a==1&&b==3&&c==3&&d==1)
    {
      noNewTone(speaker);
      exit(0);
      }
  
  }


void loop() {
  // put your main code here, to run repeatedly:
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
     int r=uS / US_ROUNDTRIP_CM;
     

  cb1=debounce1(pb1);
  cb2=debounce2(pb2);
  cb3=debounce3(pb3);
  cb4=debounce4(pb4);

     if (pb1==LOW&&cb1==HIGH)   
   {
      w++;
    }
    pb1=cb1;
    

    if (pb2==LOW&&cb2==HIGH)   
   {
      x++;
    }
    pb2=cb2;

    
    if (pb3==LOW&&cb3==HIGH)   
   {
      y++;
    }
    pb3=cb3;

    if (pb4==LOW&&cb4==HIGH)   
   {
      z++;
    }
    pb4=cb4;

Serial.print(w);
Serial.print(x);
Serial.print(y);
Serial.print(z);


Serial.println();
Serial.println("ENTER PASSCODE!!!!!");
check(r,w,x,y,z);

delay(100);

    
     
}
