#include <IRremote.h>

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  //irrecv.blink13(true);
    // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
}

void loop(){

  //analogWrite(9, 100); //ENA pin
  //analogWrite(10, 100); //ENB pin
  
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          Serial.println("CH-");
          break;
          case 0xFF629D:
          Serial.println("CH");
          break;
          case 0xFFE21D:
          Serial.println("CH+");
          break;
          case 0xFF22DD:
          Serial.println("|<<");
          break;
          case 0xFF02FD:
          Serial.println(">>|");
          break ;  
          case 0xFFC23D:
          Serial.println(">|");
          break ;               
          case 0xFFE01F:
          Serial.println("-");
          break ;  
          case 0xFFA857:
          Serial.println("+");
          break ;  
          case 0xFF906F:
          Serial.println("EQ");
          break ;  
          case 0xFF6897:
          Serial.println("0");
          break ;  
          case 0xFF9867:
          Serial.println("100+");
          break ;
          case 0xFFB04F:
          Serial.println("200+");
          break ;
          case 0xFF30CF:
          Serial.println("1");
          break ;
          case 0xFF18E7:
          Serial.println("2");
          break ;
          case 0xFF7A85:
          Serial.println("3");
          break ;
          case 0xFF10EF:
          Serial.println("4");
          break ;
          case 0xFF38C7:
          Serial.println("5");
          break ;
          case 0x574355AA:
          Serial.println("Stop");
          analogWrite(9, 0); //ENA pin
          analogWrite(10, 0); //ENB pin
          digitalWrite(motor1pin1, HIGH);
          digitalWrite(motor1pin2, LOW);
          digitalWrite(motor2pin1, HIGH);
          digitalWrite(motor2pin2, LOW);
          break ;
          case 0x57437986:
          Serial.println("Left");
          analogWrite(9, 0); //ENA pin
          analogWrite(10, 100); //ENB pin
          digitalWrite(motor1pin1, HIGH);
          digitalWrite(motor1pin2, LOW);
          digitalWrite(motor2pin1, HIGH);
          digitalWrite(motor2pin2, LOW);
          break ;
          case 0x5743B54A:
          Serial.println("Right");
          analogWrite(9, 100); //ENA pin
          analogWrite(10, 0); //ENB pin
          digitalWrite(motor1pin1, HIGH);
          digitalWrite(motor1pin2, LOW);
          digitalWrite(motor2pin1, HIGH);
          digitalWrite(motor2pin2, LOW);
          break ;
          case 0x5743CD32:
          Serial.println("Backwards");
          analogWrite(9, 100); //ENA pin
          analogWrite(10, 100); //ENB pin
          digitalWrite(motor1pin1, LOW);
          digitalWrite(motor1pin2, HIGH);
          digitalWrite(motor2pin1, LOW);
          digitalWrite(motor2pin2, HIGH);
          break ;
          case 0x57439966:
          Serial.println("Forward");
          analogWrite(9, 100); //ENA pin
          analogWrite(10, 100); //ENB pin
          digitalWrite(motor1pin1, HIGH);
          digitalWrite(motor1pin2, LOW);
          digitalWrite(motor2pin1, HIGH);
          digitalWrite(motor2pin2, LOW);
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
