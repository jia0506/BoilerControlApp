#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
SoftwareSerial bt(4,5);
Servo SERVO_MOTOR;

#define SMOTOR 7 //서보모터
char data = '0';
bool lighton = false;
char SwitchControl = '0';
 
void setup() {
  // put your setup code here, to run once:
  SERVO_MOTOR.attach(SMOTOR);
  // SERVO_MOTOR.writeMicroseconds(1000);
  Serial.begin(9600); //PC-아두이노간
  mySerial.begin(2400); 
  //bt.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 /* bt.listen();
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
   
  mySerial.listen(); */
    if(mySerial.available()>0){
      data = mySerial.read();
      Serial.println(data);

     if(data == '1'){
     Serial.println("SWITCH OFF");
     if(lighton == true)
        {
          SERVO_MOTOR.write(1000);
          delay(500);
          SERVO_MOTOR.write(100);
          delay(500);
        lighton = false;
        }
   }
      
    else if(data == '0'){
      Serial.println("SWITCH ON");
      lighton = true;
     }
    }
    
    /*if(data == '0'){
      Serial.println("SWITCH OFF");
      SERVO_MOTOR.write(100);
       delay(500);
   }
      
    else if(data == '1'){
      Serial.println("SWITCH ON");
      SERVO_MOTOR.write(1000);
       delay(500);
   }*/
    //Serial.write(mySerial.read());
   
  }
