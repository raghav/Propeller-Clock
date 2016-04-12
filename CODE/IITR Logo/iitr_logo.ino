int DS=10;
int SH_CP=12;
int ST_CP=11;
int a=0;
int IR = 13;
    int test=0;
    double T1=30;
    double t=0.40;
double T=0.9;
boolean led[32];
void setup(){
  pinMode(DS,OUTPUT);
  pinMode(SH_CP,OUTPUT);
  pinMode(ST_CP,OUTPUT);
   pinMode(IR,INPUT);
   
  for(int i=0;i<32;i++){
    led[i]=LOW;
  }
  writereg();
}

void loop(){
   a= digitalRead(IR);
  
  if (a==1 && test==0){
    test=1;
    for (int j=0; j<12; j++){
  for(int i=0;i<=7;i++){
    led[i] = HIGH;
  }
   arrow(); 
    }
  }
  else if (a==1){
    test=0;
    delay(14);
displayI();
displayI();
displayT();
delay(4);
displayR();
displayO();
displayO();
displayR();
displayK();
displayE();
displayE();
    
    }
}

void writereg()
{
digitalWrite(ST_CP, LOW);
for (int i = 31; i>=0; i--)
{
digitalWrite(SH_CP, LOW);
digitalWrite(DS, led[i] );

digitalWrite(SH_CP, HIGH);
}
digitalWrite(ST_CP, HIGH);
}

void arrow(){
  led[13]=HIGH;
  led[20]=HIGH;
  led[21]=HIGH;
  for(int i=8;i<=12;i++){
    led[i]=HIGH;
  }
  writereg();
  //delay(T/120);
  for(int i=0;i<1;i++){
    led[30]=HIGH;
    led[31]=HIGH;
    writereg();
    delay(T1/360);

    led[31]=LOW;
    writereg();
    delay((T1/120)-(T1/360));
  }
  
  
  for(int i=8;i<=12;i++){
    led[i]=LOW;
  }
  //writereg();
  
  led[15]=HIGH;
  led[16]=HIGH;
  led[18]=HIGH;
  
  led[30]=HIGH;
  led[31]=HIGH;
  
  writereg();
  delay(T1/360);
  led[31]=LOW;  
  delay((T1/120)-(T1/360));
  
  led[30]=HIGH;
  led[31]=HIGH;
  writereg();
  delay(T1/360);
  
  led[31]=LOW;
  
  led[17]=HIGH;
  writereg();
  delay((T1/120)-(T1/360));
  
  
  for(int i=15;i<=18;i++){
    led[i]=LOW;
  }
  writereg();
  
  for(int i=0;i<2;i++){
    led[30]=HIGH;
    led[31]=HIGH;
    writereg();
    delay(T1/360);

    led[31]=LOW;
    writereg();
    delay((T1/120)-(T1/360));
  }  
  
  //delay(T/60);
}

//************E*************
void displayE(){
for(int b=19+4;b<26+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[20+4]=LOW;
led[21+4]=LOW;
led[23+4]=LOW;
led[24+4]=LOW;
writereg();
delay(3*t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}

//************I*************
void displayI(){
led[19+4]=HIGH;
led[25+4]=HIGH;
writereg();
delay(2*t);
for(int b=19+4;b<26+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20+4;b<25+4;b++)
{led[b]=LOW;}
writereg();
delay(2*t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//************K*************
void displayK(){
for(int b=19+4;b<26+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
led[19+4]=LOW;
led[20+4]=LOW;
led[22+4]=LOW;
led[24+4]=LOW;
led[25+4]=LOW;
writereg();
delay(t);
led[21+4]=LOW;
led[23+4]=LOW;
led[20+4]=HIGH;
led[24+4]=HIGH;
writereg();
delay(t);
led[20+4]=LOW;
led[24+4]=LOW;
led[19+4]=HIGH;
led[25+4]=HIGH;
writereg();
delay(t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}

//**********O**********
void displayO(){
for(int b=20+4;b<25+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20+4;b<25+4;b++)
{led[b]=LOW;}
led[19+4]=HIGH;
led[25+4]=HIGH;
writereg();
delay(2*t);
for(int b=20+4;b<25+4;b++)
{led[b]=HIGH;}
led[19+4]=LOW;
led[25+4]=LOW;
writereg();
delay(t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}

//**************R*******************
void displayR(){
for(int b=19+4;b<26+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
led[21+4]=HIGH;
led[22+4]=HIGH;
led[25+4]=HIGH;
writereg();
delay(t);
led[21+4]=LOW;
led[20+4]=HIGH;
writereg();
delay(t);
led[20+4]=LOW;
led[19+4]=HIGH;
led[23+4]=HIGH;
led[24+4]=HIGH;
writereg();
delay(t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}

//************T*************
void displayT(){
led[25+4]=HIGH;
writereg();
delay(2*t);
for(int b=19+4;b<26+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=19+4;b<25+4;b++)
{led[b]=LOW;}
writereg();
delay(2*t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}
//***************U***************
void displayU(){
for(int b=20+4;b<26+4;b++)
{led[b]=HIGH;}
writereg();
delay(t);
for(int b=20+4;b<26+4;b++)
{led[b]=LOW;}
led[19+4]=HIGH;
writereg();
delay(2*t);
for(int b=20+4;b<26+4;b++)
{led[b]=HIGH;}
led[19+4]=LOW;
writereg();
delay(t);
for(int b=19+4;b<26+4;b++)
{led[b]=LOW;}
writereg();
delay(T);
}



