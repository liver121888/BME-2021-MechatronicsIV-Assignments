#include <Servo.h> 
Servo myservo;  // 建立SERVO物件
int Motorforward_B = 6;   
int Motorbackward_B = 5; 
int en_B = 4;//right  
int en_A = 8;//left
int Motorforward_A = 11;   
int Motorbackward_A = 3;

void setup()

{
  Serial.begin(9600); // start serial port at 9600 bps:
  pinMode(en_A, OUTPUT);  // sets the pin as output
  pinMode(Motorforward_A, OUTPUT); // sets the pin as output
  pinMode(Motorbackward_A, OUTPUT);
  pinMode(en_B, OUTPUT);  // sets the pin as output
  pinMode(Motorforward_B, OUTPUT); // sets the pin as output
  pinMode(Motorbackward_B, OUTPUT);  
  myservo.attach(2);
  establishContact(); 
}



void loop()
{
  digitalWrite(en_A, HIGH);  
  digitalWrite(en_B, HIGH);
  
  if (Serial.available() > 0) 
  {
    char serialread = Serial.read();
    switch(serialread)
    {
      case 'w':
      analogWrite(Motorforward_A, 200);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 230);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case 'x':
      analogWrite(Motorforward_A, 0);
      analogWrite(Motorbackward_A, 200);
      analogWrite(Motorforward_B, 0);
      analogWrite(Motorbackward_B, 230);
      break;
      
      case 's':
      analogWrite(Motorforward_A, 0);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 0);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case 'a':
      analogWrite(Motorforward_A, 0);
      analogWrite(Motorbackward_A, 200);
      analogWrite(Motorforward_B, 200);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case 'd':
      analogWrite(Motorforward_A, 200);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 0);
      analogWrite(Motorbackward_B,200);
      break;
            
      case 'o':
      myservo.write(0);
      break;
      
      case 'l':
      myservo.write(60);
      break;

      default:
        break;
      
    }
    Serial.print(serialread);
    Serial.print('\n');    
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print("A\n");   // send a capital A
    delay(1000);
  }
}
