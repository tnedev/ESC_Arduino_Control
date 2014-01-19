#include <Servo.h>

#define MAX_SIGNAL 2000 // най-дълъг сигнал. микросекунди
#define MIN_SIGNAL 700 // най-къс сигнал микросекунди
#define MOTOR_PIN 9 

Servo motor;

byte message=0; // Стойността която ще пази съобщение въведено от серийната комуникация

void setup() 
{

  Serial.begin(9600);
  motor.attach(MOTOR_PIN);

}

void loop() {  
  
  if(Serial.available()>0)
  {
    message = Serial.read(); 
  }
  
  if(message=='0')
   {
        motor.writeMicroseconds(MIN_SIGNAL);
        Serial.println("min");

   }
    else if(message=='1')
   {
        motor.writeMicroseconds(MAX_SIGNAL);
           Serial.println("max");

   }
   else if(message=='2')
   {
        motor.writeMicroseconds(MIN_SIGNAL+120);
        Serial.println("Some Low Speed Example");
   }
   else if(message=='3')
   {
        motor.writeMicroseconds(MIN_SIGNAL+700);
        Serial.println("Some High Speed Example");

   }
   message=0;
}
