int DS_pin=10;
int STCP_pin=11;
int SHCP_pin=12;
int IR=13;
int a=0;
double t=0.40;
double T=0.9;
boolean led[32];

void setup()
{
  pinMode(DS_pin,OUTPUT);
  pinMode(STCP_pin,OUTPUT);
  pinMode(SHCP_pin,OUTPUT);
  pinMode(IR,INPUT);
  Serial.begin(9600);
  writereg();
}

void writereg()
{
  digitalWrite(STCP_pin,LOW);
  for(int i=31;i>0;i--)
  {
    digitalWrite(SHCP_pin,LOW);
    digitalWrite(DS_pin,led[i]);
    digitalWrite(SHCP_pin,HIGH);
  }
  digitalWrite(STCP_pin,HIGH);
}

void loop()
{
  a=digitalRead(IR);
  
  if(a==1)
  { for(int b=0;b<32;b++)
{led[b]=LOW;}

writereg();
delay(10);
    
    displayW();
    displayE();
    displayL();
    displayC();
    displayO();
//   
    displayM();
     displayE();
 delay(2);
     displayT();
    displayO();

     delay(2);
//     
    displayS();
    displayR();
    displayI();
   // delay(2);
    displayS();
     displayH();
//
      displayT();
     displayI();
//
//   displayN();
//    displayI();
//    displayT();
//    displayE();
//     displayS();
//
//     displayH();
//
//delay(2);
// displayT();
//    displayH();
//    displayE();
//
//delay(2);
//    displayL();
//     displayO();
//     displayV();
//      displayE();
//    displayR();
//    
//    delay(2);
//    displayB();
//    displayO();
//     displayY();
//
     
    

    
    //displayD();
   // displayE();
    //displayR();
    //displayT();
    //displayU();
    //displayV();
    //displayW();
    //displayX();
    //displayY();
    //displayZ();

   
    } 
  }

void displayA(){
//*************A******************
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[19]=LOW;
led[20]=LOW;
led[21]=LOW;
led[23]=LOW;
led[24]=LOW;
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}

//***********B*******************
void displayB(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[20]=LOW;
led[21]=LOW;
led[23]=LOW;
led[24]=LOW;
writereg();
delay(2*t);
led[20]=HIGH;
led[21]=HIGH;
led[23]=HIGH;
led[24]=HIGH;
led[19]=LOW;
led[22]=LOW;
led[25]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************C***************
void displayC(){
led[21]=HIGH;
led[22]=HIGH;
led[23]=HIGH;
writereg();
delay(t);
led[21]=LOW;
led[22]=LOW;
led[23]=LOW;
led[20]=HIGH;
led[24]=HIGH;
writereg();
delay(t);
led[20]=LOW;
led[24]=LOW;
led[19]=HIGH;
led[25]=HIGH;
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************D*************
void displayD(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20;b<25;b++)
{led[b]=LOW;}
writereg();
delay(t);
led[19]=LOW;
led[25]=LOW;
led[20]=HIGH;
led[24]=HIGH;
writereg();
delay(t);
led[20]=LOW;
led[24]=LOW;
led[21]=HIGH;
led[22]=HIGH;
led[23]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************E*************
void displayE(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[20]=LOW;
led[21]=LOW;
led[23]=LOW;
led[24]=LOW;
writereg();
delay(3*t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************F*************
void displayF(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[19]=LOW;
led[20]=LOW;
led[21]=LOW;
led[23]=LOW;
led[24]=LOW;
writereg();
delay(3*t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************G*************
void displayG(){
for(int b=19;b<24;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20;b<24;b++)
{led[b]=LOW;}
led[24]=HIGH;
writereg();
delay(t);
led[24]=LOW;
led[25]=HIGH;
led[20]=HIGH;
led[21]=HIGH;
writereg();
delay(t);
led[19]=LOW;
led[20]=LOW;
writereg();
delay(t);
led[25]=LOW;
led[24]=HIGH;
led[19]=HIGH;
led[20]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************H*************
void displayH(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[19]=LOW;
led[20]=LOW;
led[21]=LOW;
led[23]=LOW;
led[24]=LOW;
led[25]=LOW;
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************I*************
void displayI(){
led[19]=HIGH;
led[25]=HIGH;
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20;b<25;b++)
{led[b]=LOW;}
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************J*************
void displayJ(){
led[20]=HIGH;
led[21]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
led[20]=LOW;
led[21]=LOW;
led[19]=HIGH;
writereg();
delay(2*t);
for(int b=20;b<26;b++)
{led[b]=HIGH;}
led[19]=LOW;
writereg();
delay(t);
for(int b=20;b<25;b++)
{led[b]=LOW;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************K*************
void displayK(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[19]=LOW;
led[20]=LOW;
led[22]=LOW;
led[24]=LOW;
led[25]=LOW;
writereg();
delay(t);
led[21]=LOW;
led[23]=LOW;
led[20]=HIGH;
led[24]=HIGH;
writereg();
delay(t);
led[20]=LOW;
led[24]=LOW;
led[19]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************L*********
void displayL(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20;b<26;b++)
{led[b]=LOW;}
writereg();
delay(3*t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************M*********
void displayM(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<24;b++)
{led[b]=LOW;}
led[25]=LOW;
writereg();
delay(t);
led[24]=LOW;
led[23]=HIGH;
led[22]=HIGH;
writereg();
delay(t);
led[24]=HIGH;
led[23]=LOW;
led[22]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//*****************N************
void displayN(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<23;b++)
{led[b]=LOW;}
led[25]=LOW;
writereg();
delay(t);
led[24]=LOW;
led[23]=LOW;
led[22]=HIGH;
writereg();
delay(t);
led[20]=HIGH;
led[21]=HIGH;
led[22]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//**********O**********
void displayO(){
for(int b=20;b<25;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20;b<25;b++)
{led[b]=LOW;}
led[19]=HIGH;
led[25]=HIGH;
writereg();
delay(2*t);
for(int b=20;b<25;b++)
{led[b]=HIGH;}
led[19]=LOW;
led[25]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//**********P************
void displayP(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
led[22]=HIGH;
led[25]=HIGH;
writereg();
delay(2*t);
led[22]=LOW;
led[25]=LOW;
led[23]=HIGH;
led[24]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);

}
//*************Q**************
void displayQ(){
for(int b=21;b<25;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=21;b<25;b++)
{led[b]=LOW;}
led[20]=HIGH;
led[25]=HIGH;
writereg();
delay(2*t);
for(int b=20;b<25;b++)
{led[b]=HIGH;}
led[25]=LOW;
writereg();
delay(t);
for(int b=20;b<25;b++)
{led[b]=LOW;}
led[19]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//**************R*******************
void displayR(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
led[21]=HIGH;
led[22]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
led[21]=LOW;
led[20]=HIGH;
writereg();
delay(t);
led[20]=LOW;
led[19]=HIGH;
led[23]=HIGH;
led[24]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//***********S**************
void displayS(){
led[19]=HIGH;
led[23]=HIGH;
led[24]=HIGH;
writereg();
delay(t);
led[19]=LOW;
led[23]=LOW;
led[24]=LOW;
led[19]=HIGH;
led[22]=HIGH;
led[25]=HIGH;
writereg();
delay(2*t);
led[19]=LOW;
led[22]=LOW;
//led[25]=LOW;
//led[19]=HIGH;
led[21]=HIGH;
led[20]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************T*************
void displayT(){
led[25]=HIGH;
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<25;b++)
{led[b]=LOW;}
writereg();
delay(2*t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//***************U***************
void displayU(){
for(int b=20;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20;b<26;b++)
{led[b]=LOW;}
led[19]=HIGH;
writereg();
delay(2*t);
for(int b=20;b<26;b++)
{led[b]=HIGH;}
led[19]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//***************V**************
void displayV(){
led[25]=HIGH;
led[24]=HIGH;
writereg();
delay(t/2.0);
led[25]=LOW;
led[24]=LOW;
led[23]=HIGH;
led[22]=HIGH;
writereg();
delay(t/2.0);
led[23]=LOW;
led[22]=LOW;
led[21]=HIGH;
led[20]=HIGH;
writereg();
delay(t/2.0);
led[21]=LOW;
led[20]=LOW;
led[19]=HIGH;
writereg();
delay(t/2.0);
led[19]=LOW;
led[21]=HIGH;
led[20]=HIGH;
writereg();
delay(t/2.0);
led[20]=LOW;
led[21]=LOW;
led[22]=HIGH;
led[23]=HIGH;
writereg();
delay(t/2.0);
led[22]=LOW;
led[23]=LOW;
led[24]=HIGH;
led[25]=HIGH;
writereg();
delay(t/2.0);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//**************W*********
void displayW(){
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=21;b<26;b++)
{led[b]=LOW;}
led[19]=LOW;
writereg();
delay(t);
led[20]=LOW;
led[21]=HIGH;
led[22]=HIGH;
writereg();
delay(t);
led[20]=HIGH;
led[21]=LOW;
led[22]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//**********X************
void displayX(){
led[19]=HIGH;
led[20]=HIGH;
led[24]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
led[19]=LOW;
led[20]=LOW;
led[24]=LOW;
led[25]=LOW;
led[21]=HIGH;
led[23]=HIGH;
writereg();
delay(t);
led[21]=LOW;
led[23]=LOW;
led[22]=HIGH;
writereg();
delay(t);
led[22]=LOW;
led[21]=HIGH;
led[23]=HIGH;
writereg();
delay(t);
led[19]=HIGH;
led[20]=HIGH;
led[24]=HIGH;
led[25]=HIGH;
led[21]=LOW;
led[23]=LOW;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//*************Y*********
void displayY(){
led[24]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
led[24]=LOW;
led[25]=LOW;
led[22]=HIGH;
led[23]=HIGH;
writereg();
delay(t);
led[22]=LOW;
led[23]=LOW;
led[19]=HIGH;
led[20]=HIGH;
led[21]=HIGH;
writereg();
delay(t);
led[22]=HIGH;
led[23]=HIGH;
led[19]=LOW;
led[20]=LOW;
led[21]=LOW;
writereg();
delay(t);
led[22]=LOW;
led[23]=LOW;
led[24]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
for(int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);

}
//*************Z************
void displayZ(){
led[19]=HIGH;
led[20]=HIGH;
led[25]=HIGH;
writereg();
delay(t);
led[20]=LOW;
led[21]=HIGH;
writereg();
delay(t);
led[21]=LOW;
led[22]=HIGH;
writereg();
delay(t);
led[22]=LOW;
led[23]=HIGH;
writereg();
delay(t);
led[23]=LOW;
led[24]=HIGH;
writereg();
delay(t);
for (int b=19;b<26;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************ALPHABETS_OVER****************

