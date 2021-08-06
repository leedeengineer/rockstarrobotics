char data; // Variable to store data
String msg;
int ledpin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())
  {
    data = Serial.read();
    if (data == '1')
    {
      digitalWrite(ledpin,HIGH);
      Serial.println("light on");
    }
    else if (data == '0')
    {
      digitalWrite(ledpin,LOW);
      Serial.println("light off");
    }
  
    
  }

}
