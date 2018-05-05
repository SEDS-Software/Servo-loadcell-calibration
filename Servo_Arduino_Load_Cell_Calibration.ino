#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int from_daq = 8;
int CLOSE = 115; 

void setup() {
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 myservo.write(0);
 pinMode(from_daq, INPUT);
 Serial.begin(9600);
 Serial.println("In setup(). Set servo to 0deg.");
 delay(1000);
}

void loop() {
 Serial.println("In loop(). Waiting for DAQ signal");
 while(digitalRead(from_daq) == LOW); //wait until not low
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 myservo.write(CLOSE);
 Serial.println("DAQ signal recieved. Set servo to 60deg. Waiting until DAQ signal zero.");
 while(digitalRead(from_daq) == HIGH); //wait until not high
 myservo.write(0);
 myservo.write(0);
 myservo.write(0);
 myservo.write(0);
 myservo.write(0);
 myservo.write(0);
 myservo.write(0);
 myservo.write(0);
 Serial.println("DAQ signal zero. Set servo to 0deg.");
}
