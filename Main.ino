// Created by: Jaden Plugowsky
// Created on: Oct 2023
//
// This is a circuit with an ultrasonic distance sensor.

int trigPin = 10;
int echoPin = 9;
float duration, distance;  

void setup()
{
    // Setup pins.
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // Send pulse of sound out.
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Calculate distance between object.
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;

    // Print to serial monitor.
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);
}
