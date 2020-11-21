#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int thumbServo = 4;
int indexServo = 3;
int middleServo = 2;
int ringServo = 1;
int pinkyServo = 0;

const int thumbFlexPin = A0;
const int indexFlexPin = A1;
const int middleFlexPin = A2;
const int ringFlexPin = A3;
const int pinkyFlexPin = A4;

int thumbFlexValue;
int indexFlexValue;
int middleFlexValue;
int ringFlexValue;
int pinkyFlexValue;

int pulseWidth(int angle){
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
 // Serial.println(analog_value);
  return analog_value;
}

void setup(){
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}


void loop(){
  thumbFlexValue = analogRead(thumbFlexPin);
  indexFlexValue = analogRead(indexFlexPin);
  middleFlexValue = analogRead(middleFlexPin);
  ringFlexValue = analogRead(ringFlexPin);
  pinkyFlexValue = analogRead(pinkyFlexPin);
  
  pinkyFlexValue = map(pinkyFlexValue, 890, 960, 110, 70);
  ringFlexValue = map(ringFlexValue, 870, 930, 110, 30);
  middleFlexValue = map(middleFlexValue, 777, 880, 110, 30);
  indexFlexValue = map(indexFlexValue, 770, 850, 110, 20);
  thumbFlexValue = map(thumbFlexValue, 747, 802, 110, 90);
   
  pwm.setPWM(thumbServo, 0, pulseWidth(thumbFlexValue));
  pwm.setPWM(indexServo, 0, pulseWidth(indexFlexValue));
  pwm.setPWM(middleServo, 0, pulseWidth(middleFlexValue));
  pwm.setPWM(ringServo, 0, pulseWidth(ringFlexValue));
  pwm.setPWM(pinkyServo, 0, pulseWidth(pinkyFlexValue));

}
