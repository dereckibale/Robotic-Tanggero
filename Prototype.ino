
#include <Servo.h>      
 
Servo handservo;                 
Servo armservo;
int ir = 6;
int motor = 5;
int motor2 = 11;
int handswitch = 12; 
int armswitch = 13;
int parahubog = 1;
int blackcount = 0;
int pumpmotor = 8;
int limit = 9;
int speedd = 90;
int armlimit;
int handlimit;
void setup() { 
  pinMode(ir, INPUT);
  pinMode(handswitch, INPUT_PULLUP);
  pinMode(armswitch, INPUT_PULLUP);
  pinMode(limit, INPUT_PULLUP);
  pinMode(speedd, OUTPUT);
  pinMode(motor, OUTPUT); 
  pinMode(motor2, OUTPUT);
  pinMode(pumpmotor, OUTPUT);
  handservo.attach(3); 
  armservo.attach(4);         
  Serial.begin(9600);
}

void forward(){
  analogWrite(motor, 100);
  analogWrite(motor2, 0);
  }
void reverse(){
  analogWrite(motor2, 100);
  digitalWrite(motor, 0);
  }
void stopp(){
  digitalWrite(motor, LOW);
  digitalWrite(motor2, LOW);
  }
void down(){
  armservo.write(0);
  }
void up(){
  armservo.write(180);
  }
void closee(){
  handservo.write(0);
  }
void stopclose(){
  handservo.write(48);
  }
void stopdown(){
  armservo.write(48);
  }

void loop() {
  int armlimit = digitalRead(armswitch);
  down();
  while(armlimit == 1){
     armlimit = digitalRead(armswitch);
    stopp();
    down();
    armlimit = digitalRead(armswitch);
    if(armlimit == 0){
      stopdown();
    }
  }
  stopdown();
   Serial.println("Okay lets start bitch!");
   analogWrite(speedd, 100);

  up();
  delay(5000);
  stopdown();
  int count = 0;

 while(true){
   int LMT = digitalRead(limit);
   Serial.println(LMT);
     while(LMT == 0){
      count++;
       stopp();
       LMT = digitalRead(limit);
       armlimit = digitalRead(armswitch);
       down();
       while(armlimit == 1){
         armlimit = digitalRead(armswitch);
         down();  
         Serial.println("downing");     
       }
       stopdown();
       digitalWrite(pumpmotor, HIGH);
       delay(2000); //determines the amount of tuba to be dispensed
       digitalWrite(pumpmotor, LOW);

       delay(60000); //imna na na imong baso
       up();
       delay(5000);
       stopdown();
       LMT = digitalRead(limit);     
       } 
       if(count % 2 ==0) {
        forward();
       }
       else if(!(count % 2 ==0)){
        reverse();
       }
       LMT = digitalRead(limit);
//        Serial.println("inside loop");
  }
 }  

