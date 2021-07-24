//static const uint32_t delayOneSecond =1000UL;
//static const uint32_t delayOneMinute = delayOneSecond*60UL;
//static const uint32_t delayOneHour   = delayOneMinute*60UL;

#include <Servo.h>

int tact_1 = 12; // pin 12 for the first button.
int tact_2 = 4; // pin 4 for the second button.
int tact_3 = 5; // pin 5 for the third button
int switch_state1; 
int switch_state2; //variable for reading data  from the button 2
int switch_state3; //variable for reading data  from the button 3
int pos = 0; // initial position of the servo arm 

Servo servo; // instancing of the servo class

//This initiallize the various control button
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);

servo.attach(10);

pinMode(tact_1,INPUT_PULLUP); 
pinMode(tact_2,INPUT_PULLUP);
pinMode(tact_3,INPUT_PULLUP);

}


void loop() {
  // put your main code here, to run repeatedly:
switch_state1=digitalRead(tact_1);// variable for reading data  from the button 1
switch_state2=digitalRead(tact_2);// variable for reading data  from the button 2
switch_state3=digitalRead(tact_3);// variable for reading data  from the button 3

servo.write(20);//positions the servo with at angle of 20 degrees


if(switch_state1==LOW){//check if the button 1 is pressed
  fiveHour();
}
else if(switch_state2==LOW){//check if the button 1 is presse
  twoHours();
  }
else if(switch_state3==LOW){//check if the button 1 is presse
  threeHours();
  }  
}

//**** FUNCTIONS FOR THE PERIOD FOOD MUST BE RELEASED.****

//Food is released in 5 hour interval but for demonstration purpose it is 5 seconds

int fiveHour(){
  
  while(true){
    for(pos=80; pos>=0; pos-=1){
    servo.write(pos);
    delay(2);
  }
  //delay(1*UL*delayOneHour);
  delay(5000);
  for(pos=30;pos<=120;pos+=1){
    servo.write(pos);
    delay(2);
    }}}

//Food is released in 2 hour interval but for demonstration purpose it is 2 seconds
int twoHours(){
  while(true){
    for(pos=40; pos>=0; pos-=1){
    servo.write(pos);
    delay(5);
  }
  //delay(4*UL*delayOneHour);
  delay(2000);
  for(pos=45;pos<=60;pos+=1){
    servo.write(pos);
    delay(15);
    }
  }}


 //Food is released in 3 hour interval but for demonstration purpose it is 3 seconds 
int threeHours(){
 while(true){ 
  for(pos=60; pos>=0; pos-=1){
    servo.write(pos);
    delay(15);
  }
 //delay(6*UL*delayOneHour);
 delay(3000);
  for(pos=15;pos<=35;pos+=1){
    servo.write(pos);
    delay(200);
    }
    }
    }    
