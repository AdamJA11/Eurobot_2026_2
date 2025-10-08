#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
const int encoderPin = 2;
volatile int pulseCount = 0;
void countPulse();

void setup() {
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);
  Serial.begin(9600);
  Serial.println("Demarrage du programme...");

  if (!AFMS.begin()) {
    Serial.println("Erreur : Motor Shield non detectee !");
    while (1);
  }
  Serial.println("Motor Shield OK !");

  motor1->setSpeed(150);
  motor1->run(FORWARD);
  Serial.println("Moteur 1 tourne vers l'avant a 150");
}

void loop() {
 
  motor1->setSpeed(200);
  motor1->run(FORWARD);
  Serial.println("Moteur 1 avance a 200");
  Serial.println(pulseCount);
  delay(3000);

  motor1->run(RELEASE);
  Serial.println("Moteur 1 arrete");
  Serial.println(pulseCount);
  delay(1000);

 
  motor1->setSpeed(200);  
  motor1->run(BACKWARD);
  Serial.println("Moteur 1 recule a 200");
  Serial.println(pulseCount);
  delay(3000);

  
  motor1->run(RELEASE);
  Serial.println("Moteur 1 arrete");
  Serial.println(pulseCount);
  delay(1000);
}

void countPulse() {
  pulseCount++;
}