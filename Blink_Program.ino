/*
 * Program Name: Blink Program
 * Programer:Deengineer
 * Discription: This program will blink the light connected to pin 13 
 */



void setup() {
  // This intializes LED_BUILTIN (pin 13) as a output. 
  pinMode(LED_BUILTIN,OUTPUT);
}


void loop() {
  
  digitalWrite(LED_BUILTIN, HIGH); //This turns the LED light (Pin13) on
  delay(1000); //this tells the computer to wait for 1000 milliseconds (1 second)
  digitalWrite(LED_BUILTIN, LOW); //This turns the LED light (Pin13) off
  delay(1000); //this tells the computer to wait for 1000 milliseconds (1 second)

}
