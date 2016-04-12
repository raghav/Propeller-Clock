//#include <PID_v1.h>

#include<Servo.h>

int temp,Speed;   
Servo m1;



double k=0;
double Setpoint, Input, Output;
//Specify the links and initial tuning parameters
//PID myPID(&Input, &Output, &Setpoint,1000,100,0, DIRECT);

int ir_led = 2;
  unsigned long  t1=0,t2=0,t3=0;
int a = 0,count=0;

      
void setup()
{

  //initial ize the variables we're linked to
  Input = 0;
  Setpoint = 1000;

  //turn the PID on
    //myPID.SetMode(AUTOMATIC);

  
  Serial.begin(9600); 
  m1.attach(9);
  
   pinMode(ir_led,INPUT);
  Serial.begin(9600);
  //t1 = millis(); 
  
  Serial.println("Program begin...");
  Serial.println("This program will calibrate the ESC.");

  Serial.println("Now writing maximum output.");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
  m1.write(2000);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  // Send min output
  Serial.println("Sending minimum output");

  m1.write(1000);


  
  
//  pinMode(A0,INPUT);
  Speed =1000;  
   m1.writeMicroseconds(Speed);
   delay(1000);
     
 for (int k=0; k<18; k++){
  
 Speed+=10;
      m1.writeMicroseconds(Speed);
      delay(500);
 }   
     Serial.println(Speed);  
  
}
void loop()
{
      m1.writeMicroseconds(Speed);
     
} 
