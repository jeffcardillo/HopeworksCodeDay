/**
 * Photoresistor detects when it is dark and turns on LED
 * Programmed for Particle Photon
 * 
 * Jeff Cardillo
 */

int photoresistor = 0;              
int threshold = 750;                // turn light on if photoresistor is below this value

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

  delay(100);
}
