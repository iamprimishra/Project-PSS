#include <Servo.h>
Servo myservo;
int angle =00;
int angleStep =50;

#define I1 13
#define I2 12
#define en1 8
#define B1 11
#define switch_ A5
#define LEFT 3
#define RIGHT  2

void setup(){

  Serial.begin(9600);

  myservo.attach(9);

  pinMode(LEFT,INPUT_PULLUP);

  pinMode(RIGHT,INPUT_PULLUP);

  myservo.write(angle);

 Serial.println("Robojax Servo Button ");
  
  pinMode(I1,OUTPUT);
  
  pinMode(I2,OUTPUT);
  
  pinMode(en1,OUTPUT);
  
  pinMode(switch_,INPUT);
  
  digitalWrite(en1,HIGH);
  
  pinMode(B1,OUTPUT);
  
  Serial.begin(9600);

}

void loop(){

  while(digitalRead(RIGHT) == LOW){

    if (angle > 0 && angle <= 100){

      angle = angle - angleStep;

       if(angle < 0){

        angle = 0;

       }else{

      myservo.write(angle);

      Serial.print("Moved to: ");

      Serial.print(angle);

      Serial.println(" degree");

       }

    }

  delay(100);

  }

  while(digitalRead(LEFT) == LOW){

    if (angle >= 0 && angle <= 100){

      angle = angle + angleStep;

      if(angle >100){

        angle =100;

       }else{

      myservo.write(angle);
      
      Serial.print("Moved to: ");

      Serial.print(angle);
      
      Serial.println(" degree");

      }

    }

 delay(100);

  }
  
  if(digitalRead(switch_)==HIGH){
    
    tone(B1,440,2000);
    
    delay(2000);
    
    digitalWrite(I1,HIGH);
    
    digitalWrite(I2,LOW);
    
    analogWrite(en1,255);
    
    delay(5000);
    
    analogWrite(en1,0);
  }

}