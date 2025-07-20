#include <Servo.h>

const int motor_1 =4;
const int motor_2 =5;
const int motor_3 =6;
const int motor_4 =7;
const int servo_pin =11;
const int water_pump =12;
int photodiode1 = A0;
int photodiode2 = A1;
int photodiode3 = A2;
int temp1 = A3;
int temp2 = A4;
int temp3 = A5;
int piezo = 10;
int LED = 13;
int threshold = 20; 
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
float temp_reading1;
float temp_reading2;
float temp_reading3;
float voltage1;
float voltage2;
float voltage3;
float temp_celsius1;
float temp_celsius2;
float temp_celsius3;

 
Servo myservo;
int pos = 0;


void setup() {
  Serial.begin(9600);
  pinMode(water_pump, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(photodiode1, INPUT);
  pinMode(photodiode2, INPUT);
  pinMode(photodiode3, INPUT);
  pinMode(temp1, INPUT);
  pinMode(temp2, INPUT);
  pinMode(temp3, INPUT);
  myservo.write(90);    
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
  digitalWrite(motor_3, LOW);  
  digitalWrite(motor_4, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
   temp_reading3 = analogRead(temp3);
   voltage3 = temp_reading3*5/1024;
   temp_celsius3 = (voltage3-0.5)*100;
   Serial.print("Celsius reading: ");
   Serial.print(temp_celsius3);
   Serial.println("C ");

   temp_reading2 = analogRead(temp2);
   voltage2 = temp_reading2*5/1024;
   temp_celsius2 = (voltage2-0.5)*100;
   Serial.print("Celsius reading: ");
   Serial.print(temp_celsius2);
   Serial.println("C ");

   temp_reading1 = analogRead(temp1);
   voltage1 = temp_reading1*5/1024;
   temp_celsius1 = (voltage1-0.5)*100;
   Serial.print("Celsius reading: ");
   Serial.print(temp_celsius1);
   Serial.println("C ");

  
  sensorValue3 = analogRead(photodiode3);
  Serial.println(sensorValue3);
  sensorValue2 = analogRead(photodiode2);
  Serial.println(sensorValue2);
  sensorValue1 = analogRead(photodiode1);
  Serial.println(sensorValue1);
  
  if (temp_celsius3 >100 && sensorValue3 > threshold)
  { 
    digitalWrite(piezo, HIGH); 
    digitalWrite(LED, HIGH);
    digitalWrite(motor_1, HIGH);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, HIGH);  
    digitalWrite(motor_4, LOW);  
    delay(3000);
    digitalWrite(piezo, LOW); 
    digitalWrite(LED, LOW);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW); 
     delay(15);
    
    myservo.attach(servo_pin);
    myservo.attach(servo_pin); 
     for(int j = 0 ; j<4;j++)
     {
       for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
        }
        for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15); 
        }
     }
    
     myservo.detach();
  }

  else if(temp_celsius2 >100 && sensorValue2 > threshold)
  { 
    digitalWrite(piezo, HIGH); 
    digitalWrite(LED, HIGH);
    digitalWrite(motor_1, HIGH);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, HIGH);  
    delay(2000);
    
    digitalWrite(piezo, LOW); 
    digitalWrite(LED, LOW);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW);  
    delay(1000);
      
     myservo.attach(servo_pin); 
     for(int j = 0 ; j<4;j++)
     {
       for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
        }
        for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
     }
    
     myservo.detach();
  }
  else if(temp_celsius1 >100 && sensorValue1 > threshold)
  { 
    digitalWrite(piezo, HIGH); 
    digitalWrite(LED, HIGH);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, HIGH);   
    digitalWrite(motor_3, HIGH);  
    digitalWrite(motor_4, LOW);  
    delay(2000);
    digitalWrite(piezo, LOW); 
    digitalWrite(LED, LOW);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW);  
    delay(1000);
         delay(15);
      
     myservo.attach(servo_pin); 
     for(int j = 0 ; j<4;j++)
     {
       for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
        }
        for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
     }
      myservo.detach();
  }
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW);  
    
  


}