int DS=10;    
int SH_CP=12;
int ST_CP=11;
int IR = 13;
int a=0;
int test=0;

unsigned long t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,countif=0,Tstart=0,Tend=0;
int count_rev=0,count_rev2=0;
int count=0;
double T=0,T_digit=0;


void setup()
{
  pinMode(DS,OUTPUT);
  pinMode(SH_CP,OUTPUT);
  pinMode(ST_CP,OUTPUT);
  pinMode(IR,INPUT);
  Serial.begin(9600);
} 

boolean registers[32];

void writereg()
{
digitalWrite(ST_CP, LOW);
for (int i = 31; i>=0; i--)
{
digitalWrite(SH_CP, LOW);
digitalWrite(DS, registers[i] );

digitalWrite(SH_CP, HIGH);
}
digitalWrite(ST_CP, HIGH);
}  

void loop()
{  
     
  int a= digitalRead(IR);
  
  delayMicroseconds(10);

  if (a==1 && test==0)
  {
    test=1;
    count_rev++;
     t3=millis();
     if(count_rev%10==0)
     {
      T=(double(t3-t5))/20;     
        t5=t3;
     }

  if(T<80.0 && T>0.0){
  
  if(((count/60)%60)==(count%60) && (((count/60)/60)%60)==(count%60) )
  {
    delay((T/60)*((count/60)%60));   
    SLEDWrite();
    delay((T/120));
    LEDErase();
  }

  
  
else if((((count/60)%60)-(((count%60))))>=0)
{
    
    
    HLEDWrite();
    delay((T/120));
    LEDErase();

  //SECOND HAND
  
  delay((T/60)*(count%60));
  Serial.print("detect ho gya"); 
  SLEDWrite();
  delay((T/120));
  LEDErase();
   
   
    //(count%60)==0   //MINUTE HAND
  
  delay((T/60)*((count/60)%60)-(((T/60)*(count%60))));   
  MLEDWrite();
  delay((T/120));
  LEDErase();
  
  
}

else
{
      
    HLEDWrite();
    delay((T/120));
    LEDErase();
    
  //MINUTE HAND
  
  delay((T/60)*((count/60)%60));
  MLEDWrite();
  delay((T/120));
  LEDErase(); 
  
  //(count%60)!=0)  //SECOND HAND
  
  
  
  delay(abs((T/60)*(count%60))-((T/60)*((count/60)%60)));
  Serial.print("detect ho gya"); 
  SLEDWrite();
  delay((T/120));
  LEDErase();
  
}

  }
 
 }
 else if (a==1)
 {
  test=0;
  count_rev2++;
     t6=millis();
     if(count_rev2%5==0)
     {
      T_digit=(double(t6-t7))/10;
      //T_digit=42.85;     
      t7=t6;
     }

     if(T_digit<80.0 && T_digit>0.0){
  registers[31] = HIGH;

    //################6###########
    registers[29]=HIGH;
  registers[23]=HIGH;
  registers[26]=HIGH;
  for(int i=27;i<=28;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay((T_digit/240));

  registers[28]=LOW;
  registers[27]=LOW;
  writereg();
  delay((T_digit/120));  
  
  for(int i=23;i<=29;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay((T_digit/240));

  for(int i=23;i<=29;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay((T_digit/5)-((2*T_digit/240)+(T_digit/120)));
  //###################6over##############
   //##################9###################
  registers[26]=HIGH;
  for(int i=27;i<=29;i++){
   registers[i]=HIGH;   
  }
  writereg();
  
  delay((T_digit/240));
  for(int i=27;i<=29;i++){
   registers[i]=LOW;   
  }
  writereg();
  
  delay((T_digit/120));
  registers[29]=HIGH;
  for(int i=27;i<=28;i++){
   registers[i]=HIGH;   
  }
  writereg();
  delay((T_digit/240));

  for(int i=27;i<=28;i++){
   registers[i]=LOW;   
  }
  writereg();
  delay((T_digit/120));

  for(int i=27;i<=28;i++){
   registers[i]=HIGH;   
  }
  writereg();
  delay((T_digit/120));
  for(int i=26;i<=29;i++){
   registers[i]=LOW;   
  }
  writereg();
  delay((T_digit/4.8)-((3*T_digit/240)+(2*T_digit/120)));
  //################9over#################
  //#############12Start###########
for(int i=23;i<=29;i++){
    registers[i] = HIGH;
  }
  writereg();
  delay((T_digit/240));
  
  for(int i=23;i<=29;i++){
    registers[i] = LOW;
  }
  writereg();
  delay((T_digit/240));
  
  registers[23]=HIGH;
  registers[29]=HIGH;
  registers[26]=HIGH;
  registers[24]=HIGH;
  registers[25]=HIGH;
  writereg();
  delay((T_digit/240));
  registers[24]=LOW;
  registers[25]=LOW;
  writereg();
  delay((T_digit/120));
  registers[27]=HIGH;
  registers[28]=HIGH;
  writereg();
  delay((T_digit/240));
  for(int i=23;i<=29;i++){
    registers[i]=LOW;  
  }     
  writereg();
  delay((T_digit/4.5)-(T_digit/40));
//#############12Over###########
  //#############3###########
  for(int i=0;i<3;i++){
    for(int j=25;j<=29;j++){
      registers[j]=HIGH;
    }
    writereg();
    delay((T_digit/240));
    
    if(i<2){
      for(int j=25;j<=28;j++){
        registers[j]=LOW;  
      }
      writereg();
      delay((T_digit/120));    
    }
    //registers[30]=LOW;
    //writereg();
  }
  for(int j=23;j<=30;j++){
    registers[j]=LOW;  
  }
  writereg();
 

  
 
 }}
 t1=millis();
 if((t1-t2)>=1000){
  count++;
  t2=t1;
 }
 
}




void SLEDWrite ()
  {
  for(int i=0;i<=31;i++)
  { 
    registers[i]=LOW;
  }
   
   for(int i=0;i<=21;i++)
  { 
    registers[i]=HIGH;
  }
    registers[31]=HIGH;
    writereg();
    
  }


void MLEDWrite ()
  {
   for(int i=0;i<=31;i++)
  { 
    registers[i]=LOW;
  }
   
   for(int i=0;i<=18;i++)
  { 
    registers[i]=HIGH;
  }
    registers[31]=HIGH;
    writereg();
    
  }


void HLEDWrite ()
  {
 for(int i=0;i<=31;i++)
  { 
    registers[i]=LOW;
  }
   
   for(int i=0;i<=14;i++)
  { 
    registers[i]=HIGH;
  }
    registers[31]=HIGH;
    writereg();
    
  }

void LEDErase ()
  {
   for(int i=0;i<=31;i++)
  { 
    registers[i]=LOW;
  }
   
    registers[31]=HIGH;
    
    writereg();
    
  }


