#include <Servo.h>
#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10, 11);
SoftwareSerial bt(4,5);
Servo SERVO_MOTOR;
#define LIGHT 2   // LED
#define CDS A0    //조도센서
#define SMOTOR 7 //서보모터
//#define SWITCH 7  //SWITCH
char data = '0';
//bool lighton = false;
char SwitchControl = '0';
int lighton = 0; 

void setup() {
  // put your setup code here, to run once:
  SERVO_MOTOR.attach(SMOTOR);
  // SERVO_MOTOR.writeMicroseconds(1000);
  Serial.begin(9600); //PC-아두이노간
  //mySerial.begin(2400); 
  bt.begin(9600);
  pinMode (LIGHT, OUTPUT);
  //pinMode (SWITCH, INPUT);
  digitalWrite (LIGHT, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int brightness = analogRead(CDS);

  //if(mySerial.available()){
 bt.listen();
   if(bt.available()>0){
    SwitchControl = bt.read(); 
    Serial.write(bt.read());
    if(SwitchControl == '1'){
       SERVO_MOTOR.write(1000);
       delay(500);
       SERVO_MOTOR.write(100);
       delay(500);
       }
     else if(SwitchControl == '0'){
       SERVO_MOTOR.write(100);
       delay(500);
       SERVO_MOTOR.write(1000);
       delay(500);
       }
     delay(20);
   }
   
   if(brightness < 680){
    
      //mySerial.write('0');
      //Serial.println(brightness);
     // Serial.write(MasterSerial.read());
     // MasterSerial.write(lighton);
     if (lighton == 1)
       {SERVO_MOTOR.write(1000);
          delay(500);
          SERVO_MOTOR.write(100);
          delay(500);
          lighton = 0;
           delay(1000);
           
          }
       }
       //else if (lighton =0){
     //   }
   else{
    lighton = 1;
   }
    //mySerial.write('1');
   // Serial.println(brightness);
     
  
  
 /* mySerial.listen(); */
 /* if(bt.available()){
    
    }*/
  /*  else if(mySerial.available()>0){
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
