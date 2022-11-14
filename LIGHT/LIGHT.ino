//#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
int a = 0;

#define LIGHT 2   // LED
#define CDS A0    //조도센서
//#define SWITCH 7  //SWITCH

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //PC-아두이노간 시리얼 통신을 위한 설정
  mySerial.begin(2400); 
  pinMode (LIGHT, OUTPUT);
  //pinMode (SWITCH, INPUT);
  digitalWrite (LIGHT, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int brightness = analogRead(CDS);
  int lighton = 1; 
  //if(mySerial.available()){
    if(brightness > 450){
      mySerial.write('0');
      Serial.println(brightness);
     // Serial.write(MasterSerial.read());
     // MasterSerial.write(lighton);
   }
   else{
    mySerial.write('1');
    Serial.println(brightness);
   }
   
  delay(1000);     //0.5초마다 밝기 감지
  //}   
}
