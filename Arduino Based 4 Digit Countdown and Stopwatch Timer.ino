const int VCC1=8;//VCC of 1st 7 Segment
const int VCC2=9;//VCC of 2nd 7 Segment
const int VCC3=10;//VCC of 3rd 7 Segment
const int VCC4=11;//VCC of 4th 7 Segment
int dp=A4; 
int buzzer=A3;
int reset;
int set;
int ones=0;
int tens=0;
int hundreds=0;
int thousands=0;
int pause;
int inc; //increment
long t=0; 
long d=200;
int z=LOW;
int y=HIGH;
int a=0;
int dec; //decrement
int w=HIGH;
int sones;
int stens;
int shundreds;
int sthousands;
int sec;

void setup(){
PORTD=0x00;
DDRD=0xFF;
pinMode(VCC1,OUTPUT);
pinMode(VCC2,OUTPUT);
pinMode(VCC3,OUTPUT);
pinMode(VCC4,OUTPUT);
pinMode(12,INPUT); //increment
pinMode(13,INPUT); //decrement
pinMode(A0,INPUT); //set
pinMode(A1,INPUT); //pause
pinMode(A2,INPUT);//­reset
pinMode(buzzer,OUTPUT); //buzzer
pinMode(dp,OUTPUT);
}
void loop(){

//INCREMENTING

start:
inc=digitalRead(12);
dec=digitalRead(13);
if(inc==HIGH and dec==LOW){
display(ones);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(tens);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(hundreds);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,LOW);
delay(1);
display(thousands);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
delay(1);

pause=digitalRead(A1);
if(pause==HIGH){
for(thousands=0;thousands<=5;thousands++){
for(hundreds=0;hundreds<=9;hundreds++){
for(tens=0;tens<=5;tens++){
for(ones=0;ones<=9;ones++){

increment:                                      //INCREMENTING
for(sec=0;sec<=241;sec++){
display(ones);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(tens);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(hundreds);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,LOW);
delay(1);
display(thousands);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
delay(1);

if (ones==1 or ones==3 or ones==5 or ones==7 or ones==9){
  digitalWrite(dp,HIGH);
  }else if (ones==0 or ones==2 or ones==4 or ones==6 or ones==8){
        digitalWrite(dp,LOW);
        }
  
inc=digitalRead(12);
if (inc ==LOW){
ones=0;
tens=0;
hundreds=0;
thousands=0;
sones=0;
stens=0;
shundreds=0;
sthousands=0;
display(ones);
display(tens);
display(hundreds);
display(thousands);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,HIGH);
goto start;
}
if (ones==0 and tens==0 and hundreds==0 and thousands==1){
    tone(buzzer,3000);
    }


pause=digitalRead(A1);
if(pause==HIGH and a>=1 and z==LOW and millis()-t>d){ //prevent the bounce 
if(y==HIGH)
y=LOW;
else
y=HIGH;
t=millis();
}
while(y==LOW){ 
display(ones);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(tens);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(hundreds);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,LOW);
delay(1);
display(thousands);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,HIGH);
delay(1);


pause=digitalRead(A1);
if(pause==HIGH and z==LOW and millis()-t>d){ 
//display(tens);
goto increment; 
}
reset = digitalRead(A2);
if (reset==HIGH){
ones=0;
tens=0;
hundreds=0;
thousands=0;
y=LOW;
goto start; 
}
}
}
a++;
}
}
}
}

thousands=0;
hundreds=0;
tens=0;
ones=0;
goto start;
}
}

//DECREMENTING


inc=digitalRead(12);
dec=digitalRead(13);
if(dec==HIGH and inc==LOW){
display(ones);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(tens);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(hundreds);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,LOW);
delay(1);
display(thousands);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,HIGH);
delay(1);

set=digitalRead(A0);
if(set==HIGH and z == LOW and millis()-t>d){
if(w==HIGH)
w=LOW;
else
w=HIGH;
t=millis();
hundreds++;
if(hundreds>=10){
thousands++;
hundreds=0;
}
if(thousands>=6 and hundreds>=0){
hundreds=0;
thousands=0;
}
}
pause=digitalRead(A1);
if(pause==HIGH and (ones>=1 or tens>=1 or hundreds>=1 or thousands>=1) and z==LOW and millis()-t>d){
if(tens>=1 and ones==0){
tens--;
ones=9;
if(hundreds>=1 and tens==0){
hundreds--;
tens=5;
ones=9;
if(thousands>=1 and hundreds==0){
thousands--;
hundreds=9;
tens=5;
ones=9;
goto startdecrementing;
}
}
}
startdecrementing:
for(sthousands=thousands;sthousands>=0;sthousands--){
for(shundreds=hundreds;shundreds>=0;shundreds--){
for(stens=tens;stens>=0;stens--){
for(sones=ones;sones>=0;sones--){
decrement:
for(sec=0;sec<=241; sec++){                        //DECREMENTING
display(sones);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(stens);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(shundreds);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,LOW);
delay(1);
display(sthousands);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,HIGH);
delay(1);

if (sones==1 or sones==3 or sones==5 or sones==7 or sones==9){
  digitalWrite(dp,HIGH);
  }else if (sones==0 or sones==2 or sones==4 or sones==6 or sones==8){
        digitalWrite(dp,LOW);
        }
  
if(sones==0 and stens==0 and shundreds==0 and sthousands==0){
sones=0;
stens=0;
shundreds=0;
sthousands=0;
ones=0;
tens=0;
hundreds=0;
thousands=0;
noTone(buzzer);
goto start;
}

dec=digitalRead(13);
if (dec ==LOW){
ones=0;
tens=0;
hundreds=0;
thousands=0;
sones=0;
stens=0;
shundreds=0;
sthousands=0;
display(ones);
display(tens);
display(hundreds);
display(thousands);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
goto start;
}
if (sones==0 and stens==1 and shundreds==0 and sthousands==0 or shundreds==0 and sthousands==0 and sones==8 and stens==0 or shundreds==0 and sthousands==0 and sones==6 and stens==0 or shundreds==0 and sthousands==0 and sones==4 and stens==0 or shundreds==0 and sthousands==0 and sones==2 and stens==0){
      tone(buzzer,2000);
      } 
      if (shundreds==0 and sthousands==0 and sones==9 and stens==0 or shundreds==0 and sthousands==0 and sones==7 and stens==0 or shundreds==0 and sthousands==0 and sones==5 and stens == 0 or shundreds==0 and sthousands==0 and sones==3 and stens==0 or sones==1 and stens==0 and shundreds==0 and sthousands==0){
        noTone(buzzer);
        
        }

pause=digitalRead(A1);
if(pause==HIGH and a>=1 and z==LOW and millis()-t>d){ //prevent the bounce 
if(y==HIGH)
y=LOW;
else
y=HIGH;
t=millis();
}
while(y==LOW){ 
display(sones);
digitalWrite(VCC1,HIGH);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(stens);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,HIGH);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,LOW);
delay(1);
display(shundreds);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,HIGH);
digitalWrite(VCC4,LOW);
delay(1);
display(sthousands);
digitalWrite(VCC1,LOW);
digitalWrite(VCC2,LOW);
digitalWrite(VCC3,LOW);
digitalWrite(VCC4,HIGH);
delay(1);
pause=digitalRead(A1);
if(pause == HIGH and z==LOW and millis()-t>d){
goto decrement;
}
reset = digitalRead(A2);
if (reset==HIGH){
ones=0;
tens=0;
hundreds=0;
thousands=0;
sthousands=0;
shundreds=0;
stens=0;
sones=0;
w=HIGH;
goto start;
}
} 
}
a++;
ones=9;
tens=5;
hundreds=9;
thousands=5;
}
}
}
}
}
}
}




void display(int num){
switch(num){
case 0:
PORTD=B01000000;
break;
case 1:
PORTD=B01111001;
break;
case 2:
PORTD=B00100100;
break;
case 3:
PORTD=B00110000;
break;
case 4:
PORTD=B00011001;

break;
case 5:
PORTD=B00010010;
break;
case 6:
PORTD=B00000010;
break;
case 7:
PORTD=B01111000;
break;
case 8:
PORTD=B00000000;
break;
case 9:
PORTD=B00010000;
break;
}
}
