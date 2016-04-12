double T_digit=42.5;
boolean registers[32];
//boolean registers[32];
int DS=10;
int SH_CP=12;
int ST_CP=11;
int IR = 13;
int a=0;
unsigned long t1=0,t2=0;
double t=0.2;
double T=0.8;
int scount=0;
int s1,s2,m1,m2,h1,h2;
int s=30,m=38,h=7;
int test=0;
int GLOBAL_COUNT=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(DS,OUTPUT);
  pinMode(SH_CP,OUTPUT);
  pinMode(ST_CP,OUTPUT);
  pinMode(IR,INPUT);
  Serial.begin(9600);

  scount=h*3600 + m*60 + s;
}

void loop() {
  a= digitalRead(IR);
  
  // put your main code here, to run repeatedly:
 
  
  if(a==1 && test==0)
  {  
     test=1;
     for(int i=10;i<18;i++)
  {
    registers[i] = LOW;
  }
  writereg();
  delay((3*T_digit/10));
  
   
   
   s2=scount%10;
   s1= (scount % 60)/10;

   m2=(scount/60)%10;
   m1= ((scount/60)%60)/10;

   h2=(scount/3600)%10;
   h1= ((scount/3600)%24)/10;
   

   
   

    displayDigit(h1);
    displayDigit(h2);
    dot();
    displayDigit(m1);
    displayDigit(m2);
    dot();
    displayDigit(s1);
    displayDigit(s2);

    
    
  }

  else if(a==1 && test==1)
  { 
    test=0;
  { for(int b=0;b<31;b++)
      {registers[b]=LOW;}

    writereg();
    delay(11);
                     //DAY
    displayF();
    displayR();
    displayI();
    displayD();
    displayA();
    displayY();
                     //DATE
    delay(5);

    Done();
    Done();
    dash();
    Dzero();
    Dthree();
    dash();
    Done();
    Dsix();
  }

   



}

 
 t1=millis();
    if(t1-t2>=1000)
    {
      scount++;
      t2=t1;
    }
     
   
}


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



void displayDigit(int k){
  switch (k){
    case 0:
    zero();
    break;
    
    case 1:
    one();
    break;

    case 2:
    two();
    break;

    case 3:
    three();
    break;

    case 4:
    four();
    break;

    case 5:
    five();
    break;

    case 6:
    six();
    break;

    case 7:
    seven();
    break;

    case 8:
    eight();
    break;

    case 9:
    nine();
    break;
    }
  }

void one(){
  for(int i=13;i<21;i++){
    registers[i] = HIGH;
  }
  writereg();
  delay((T_digit/240));
  
  for(int i=13;i<21;i++){
    registers[i] = LOW;
  }
  writereg();
  delay((T_digit/30));  
}



void Done(){
  for(int i=13+9;i<21+9;i++){
    registers[i] = HIGH;
  }
  writereg();
  delay((T_digit/480));
  
  for(int i=13+9;i<21+9;i++){
    registers[i] = LOW;
  }
  writereg();
  delay((T_digit/60));  
}

void two(){
  for(int i=13;i<18;i++){
    registers[i]=HIGH;
  }
  registers[18]=LOW;
   registers[19]=LOW;
   registers[20]=HIGH;
   writereg();
   delay(T_digit/240);
   registers[13]=HIGH;
   registers[14]=LOW;
   registers[15]=LOW;
   registers[16]=HIGH;
   registers[17]=HIGH;
   registers[18]=LOW;
   registers[19]=LOW;
   registers[20]=HIGH;
   
   writereg();
    delay(T_digit/120);
   registers[13]=HIGH;
   registers[14]=LOW;
   registers[15]=LOW;
   for(int i=16;i<21;i++){
    registers[i]=HIGH;
   }
   writereg();
   delay(T_digit/240);

   for(int i=13;i<21;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/30);
   
   
  
    
}

void three(){
   registers[13]=HIGH;
   registers[14]=LOW;
   registers[15]=LOW;
   registers[16]=HIGH;
   registers[17]=HIGH;
   registers[18]=LOW;
   registers[19]=LOW;
   registers[20]=HIGH;
   
   writereg();
    delay(3*T_digit/80);
    for(int i=13;i<21;i++){
      registers[i]=HIGH;
    }
    writereg();
    delay(T_digit/240);

    for(int i=13;i<21;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/30);
  
  
}


void Dthree(){
   registers[13+9]=HIGH;
   registers[14+9]=LOW;
   registers[15+9]=LOW;
   registers[16+9]=HIGH;
   registers[17+9]=HIGH;
   registers[18+9]=LOW;
   registers[19+9]=LOW;
   registers[20+9]=HIGH;
   
   writereg();
    delay(3*T_digit/160);
    for(int i=13+9;i<21+9;i++){
      registers[i]=HIGH;
    }
    writereg();
    delay(T_digit/480);

    for(int i=13+9;i<21+9;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/60);
  
  
}

void four(){
  for(int i=15;i<21;i++){
    registers[i]=HIGH;
  }
  writereg();
  delay((T_digit/240));
  for(int i=16;i<21;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay((4*T_digit/120));
  for(int i=13;i<21;i++){
    registers[i]=HIGH;  
  }
  writereg();
  
  delay((T_digit/120));

  for(int i=13;i<21;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/30);
}

void five(){
  registers[13]=HIGH;
  for(int i=16;i<21;i++){
    registers[i]=HIGH;
  }
  
  
  for(int i=17;i<=18;i++){
     registers[i]=HIGH; 
  }
  writereg();
  delay(T_digit/120);

  for(int i=17;i<=19;i++){
     registers[i]=LOW; 
  }
  writereg();
  delay(T_digit/60);

  for(int i=14;i<=15;i++){
     registers[i]=HIGH; 
  }
  writereg();
  delay(T_digit/120);
  
  for(int i=13;i<21;i++){
     registers[i]=LOW; 
  }
  writereg();
  delay(T_digit/30);

 
}

void nine(){
  registers[13]=HIGH;
  registers[14]=LOW;
  registers[15]=LOW;
  for(int i=16;i<21;i++){
    registers[i]=HIGH;
  }
  writereg();
  delay(T_digit/240);
  
  registers[13]=HIGH;
  registers[14]=LOW;
  registers[15]=LOW;
  for(int i=16;i<21;i++){
    registers[i]=HIGH;
  }
  registers[18]=LOW;
  registers[19]=LOW;
  writereg();
  delay(T_digit/60);
  for(int i=13;i<21;i++){
    registers[i]=HIGH;
  }
  writereg();
  delay(T_digit/240);

  for(int i=13;i<21;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/30);
    
}
void seven(){
  registers[20]=HIGH;
  //registers[21]=HIGH;
  writereg();
  delay(4*T_digit/120);
  for(int i=13;i<21;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);
  for(int i=13;i<21;i++){
    registers[i]=LOW;  
  }
  delay(T_digit/120);
    for(int i=13;i<21;i++){
    registers[i] = LOW;
  }
  writereg();
  delay((T_digit/30));      
}

void eight(){
  registers[20]=HIGH;
  registers[13]=HIGH;
  registers[16]=HIGH;
  registers[17]=HIGH;

  for(int i=13;i<21;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);

  registers[14]=LOW;
  registers[15]=LOW;
  registers[19]=LOW;
  registers[18]=LOW;
  writereg();
  delay(4*T_digit/120);

  for(int i=13;i<21;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);

  for(int i=13;i<21;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/30);
    
}

void six(){
  for(int i=13;i<21;i++){
    registers[i]=HIGH;
  }
  writereg();
  delay(T_digit/240);
  for(int i=13;i<21;i++){
    registers[i]=HIGH;
  }
  registers[14]=LOW;
  registers[15]=LOW;
   registers[16]=LOW;
  registers[17]=HIGH;
  registers[18]=LOW;
    registers[19]=LOW;
  
  writereg();
  delay(3*T_digit/120);
  for(int i=13;i<18;i++){
    registers[i]=HIGH;
  }
   registers[18]=LOW;
  registers[19]=LOW;
  registers[20]=HIGH;
  writereg();
  delay(T_digit/240);

  for(int i=13;i<21;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/30);
}


void Dsix(){
  for(int i=13+9;i<21+9;i++){
    registers[i]=HIGH;
  }
  writereg();
  delay(T_digit/480);
  for(int i=13+9;i<21+9;i++){
    registers[i]=HIGH;
  }
  registers[14+9]=LOW;
  registers[15+9]=LOW;
   registers[16+9]=LOW;
  registers[17+9]=HIGH;
  registers[18+9]=LOW;
    registers[19+9]=LOW;
  
  writereg();
  delay(3*T_digit/240);
  for(int i=13+9;i<18+9;i++){
    registers[i]=HIGH;
  }
   registers[18+9]=LOW;
  registers[19+9]=LOW;
  registers[20+9]=HIGH;
  writereg();
  delay(T_digit/480);

  for(int i=13+9;i<21+9;i++){
    registers[i]=LOW;
   }
   writereg();
   delay(T_digit/60);
}
/*
void ten(){
  //#########1##########
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
  //###########1over############
  //##########0############
  for(int i=10;i<=18;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);

  for(int i=12;i<=16;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/120);

  for(int i=10;i<=18;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);

  for(int i=10;i<=18;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/120);
}*/
/*
void eleven(){
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
}
*/
 
/*  
void twelve(){
  //##################12##################
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
  delay(T_digit/5-(T_digit/40));
  
}*/

void zero(){
  //##########0############
  for(int i=13;i<21;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);

  for(int i=15;i<19;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/30);

  for(int i=13;i<21;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/240);

  for(int i=13;i<21;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/30);  
}


void Dzero(){
  //##########0############
  for(int i=13+9;i<21+9;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/480);

  for(int i=15+9;i<19+9;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/60);

  for(int i=13+9;i<21+9;i++){
    registers[i]=HIGH;  
  }
  writereg();
  delay(T_digit/480);

  for(int i=13+9;i<21+9;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/60);  
}

void dot(){
  for(int i=13;i<21;i++){
    registers[i]=LOW; 
  }
  registers[15]=HIGH;
  registers[17]=HIGH;
  writereg();
  delay(T_digit/240);
  for(int i=13;i<=19;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/30);  
  
}



void dash(){
  for(int i=13+9;i<21+9;i++){
    registers[i]=LOW; 
  }
  registers[16+9]=HIGH;
  
  writereg();
  delay(T_digit/240);
  for(int i=13+9;i<=19+9;i++){
    registers[i]=LOW;  
  }
  writereg();
  delay(T_digit/60);  
  
}


//***********S**************
void displayS(){
registers[19+3]=HIGH;
registers[23+3]=HIGH;
registers[24+3]=HIGH;
writereg();
delay(t);
registers[19+3]=LOW;
registers[23+3]=LOW;
registers[24+3]=LOW;
registers[19+3]=HIGH;
registers[22+3]=HIGH;
registers[25+3]=HIGH;
writereg();
delay(2*t);
registers[19+3]=LOW;
registers[22+3]=LOW;
//registers[25]=LOW;
//registers[19]=HIGH;
registers[21+3]=HIGH;
registers[20+3]=HIGH;
writereg();
delay(t);
for(int b=(19+3);b<(26+3);b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

void displayA(){
//*************A******************
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
registers[19+3]=LOW;
registers[20+3]=LOW;
registers[21+3]=LOW;
registers[23+3]=LOW;
registers[24+3]=LOW;
writereg();
delay(2*t);
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}



//************T*************
void displayT(){
registers[25+3]=HIGH;
writereg();
delay(2*t);
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=19+3;b<25+3;b++)
{registers[b]=LOW;}
writereg();
delay(2*t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}


//***************U***************
void displayU(){
for(int b=20+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=20+3;b<26+3;b++)
{registers[b]=LOW;}
registers[19+3]=HIGH;
writereg();
delay(2*t);
for(int b=20+3;b<26+3;b++)
{registers[b]=HIGH;}
registers[19+3]=LOW;
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

//************D*************
void displayD(){
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=20+3;b<25+3;b++)
{registers[b]=LOW;}
writereg();
delay(t);
registers[19+3]=LOW;
registers[25+3]=LOW;
registers[20+3]=HIGH;
registers[24+3]=HIGH;
writereg();
delay(t);
registers[20+3]=LOW;
registers[24+3]=LOW;
registers[21+3]=HIGH;
registers[22+3]=HIGH;
registers[23+3]=HIGH;
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

//*************Y*********
void displayY(){
registers[24+3]=HIGH;
registers[25+3]=HIGH;
writereg();
delay(t);
registers[24+3]=LOW;
registers[25+3]=LOW;
registers[22+3]=HIGH;
registers[23+3]=HIGH;
writereg();
delay(t);
registers[22+3]=LOW;
registers[23+3]=LOW;
registers[19+3]=HIGH;
registers[20+3]=HIGH;
registers[21+3]=HIGH;
writereg();
delay(t);
registers[22+3]=HIGH;
registers[23+3]=HIGH;
registers[19+3]=LOW;
registers[20+3]=LOW;
registers[21+3]=LOW;
writereg();
delay(t);
registers[22+3]=LOW;
registers[23+3]=LOW;
registers[24+3]=HIGH;
registers[25+3]=HIGH;
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);

}

//************F*************
void displayF(){
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
registers[19+3]=LOW;
registers[20+3]=LOW;
registers[21+3]=LOW;
registers[23+3]=LOW;
registers[24+3]=LOW;
writereg();
delay(3*t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

//**************R*******************
void displayR(){
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
registers[21+3]=HIGH;
registers[22+3]=HIGH;
registers[25+3]=HIGH;
writereg();
delay(t);
registers[21+3]=LOW;
registers[20+3]=HIGH;
writereg();
delay(t);
registers[20+3]=LOW;
registers[19+3]=HIGH;
registers[23+3]=HIGH;
registers[24+3]=HIGH;
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

//************I*************
void displayI(){
registers[19+3]=HIGH;
registers[25+3]=HIGH;
writereg();
delay(2*t);
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=20+3;b<25+3;b++)
{registers[b]=LOW;}
writereg();
delay(2*t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

//*****************N************
void displayN(){
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=19+3;b<23+3;b++)
{registers[b]=LOW;}
registers[25+3]=LOW;
writereg();
delay(t);
registers[24+3]=LOW;
registers[23+3]=LOW;
registers[22+3]=HIGH;
writereg();
delay(t);
registers[20+3]=HIGH;
registers[21+3]=HIGH;
registers[22+3]=LOW;
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=HIGH;}
writereg();
delay(t);
for(int b=19+3;b<26+3;b++)
{registers[b]=LOW;}
writereg();
delay(T);
}

