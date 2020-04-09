//Sayed Tanimun Hasan, B.Sc in EEE, IIUC

#include <Servo.h>   //servo library
Servo servo1, servo2;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin1 = 7;
int servoPin2 = 8;
//int led= 10;
long duration, dist, average;   
long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo1.attach(servoPin1);  
    servo2.attach(servoPin2);
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo1.write(0);         //close cap on power on
    servo2.write(0);
    delay(100);
    servo1.detach(); 
    servo2.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(100);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist<50 ) {
//Change distance as per your need
 servo1.attach(servoPin1);
 servo2.attach(servoPin2);
  delay(1);
 servo1.write(0);
 servo2.write(0);  
 delay(1000);       
 servo1.write(150);    
 servo2.write(150);
 delay(1000);
 servo1.detach();
 servo2.detach();      
}
Serial.print(dist);
}
