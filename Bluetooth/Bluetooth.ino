#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bt(4,5);
Servo SERVO_MOTOR;


#define SMOTOR 7 //서보모터
char data = '0';
char SwitchControl = '0';

void setup() {
  // put your setup code here, to run once:
  SERVO_MOTOR.attach(SMOTOR);
  Serial.begin(9600); //PC-아두이노간
  bt.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available()>0){
    SwitchControl = bt.read(); 
    Serial.write(bt.read());
    if(SwitchControl == '1'){
       SERVO_MOTOR.write(1000);
       delay(500);
       SERVO_MOTOR.write(100);
       delay(500);
       }
     else if(SwitchControl == '1'){
       SERVO_MOTOR.write(100);
       delay(500);
       SERVO_MOTOR.write(1000);
       delay(500);
       }
     delay(20);
   }
}
