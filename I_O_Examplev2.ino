//how to use words in a input

String data; // Variable to store data
String msg;
String msg2;
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
    data = Serial.readString();
    data = Serial.readStringUntil('/r');
    //msg = String("hello");
    msg2 = String("bye");
    Serial.println(data);
  
    if (data == msg)
    {
      digitalWrite(ledpin,HIGH);
      Serial.println("light on");
    }
    else if (data == msg2)
    {
      digitalWrite(ledpin,LOW);
      Serial.println("light off");
    }
  
    
  }

}
