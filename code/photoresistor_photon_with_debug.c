/**
 * Photoresistor detects when it is dark and turns on LED
 * Programmed for Particle Photon and will publish debug events to your particle console
 * 
 * Jeff Cardillo
 */

int DEBUG = 1;
int photoresistor = 0;              
int threshold = 750;                // turn light on if photoresistor is below this value

char debugOutputString[40];

void setup()
{
  pinMode(D2, OUTPUT);              //set pin D2 as an output that can be set to HIGH or LOW
}

void loop()
{
  photoresistor = analogRead(A0);   // set photoresistor to a number between 0 and 1023
  
  if (photoresistor < threshold) {
    digitalWrite(D2, HIGH);         // Turn on the LED  
  } else {
    digitalWrite(D2, LOW);          // Turn off the LED
  }

  if (DEBUG == 1) {
    sprintf(debugOutputString, "%d", photoresistor); // convert the photoresistor value to a string
    Particle.publish("Photoresistor Value", debugOutputString, 60, PRIVATE);
    Particle.publish("LED Status", (digitalRead(D2)==HIGH)?"ON":"OFF", 60, PRIVATE);
    delay(1000);
  } else {
    delay(100);
  }
}
