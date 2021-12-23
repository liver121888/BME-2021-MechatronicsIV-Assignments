#include <Servo.h> 
Servo myservo;  // 建立SERVO物件
int Motorforward_B = 3;   
int Motorbackward_B = 11; 
int en_B = 4;//right  
int en_A = 8;//left
int Motorforward_A = 5;   
int Motorbackward_A = 6;

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
      analogWrite(Motorforward_A, 170);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 140);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case '2':
      analogWrite(Motorforward_A, 220);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 160);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case 'x':
      analogWrite(Motorforward_A, 0);
      analogWrite(Motorbackward_A, 170);
      analogWrite(Motorforward_B, 0);
      analogWrite(Motorbackward_B, 140);
      break;
      
      case 's':
      analogWrite(Motorforward_A, 0);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 0);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case 'a':
      analogWrite(Motorforward_A, 0);
      analogWrite(Motorbackward_A, 150);
      analogWrite(Motorforward_B, 150);
      analogWrite(Motorbackward_B, 0);
      break;

      case 'q':
      analogWrite(Motorforward_A, 100);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 255);
      analogWrite(Motorbackward_B, 0);
      break;
      
      case 'd':
      analogWrite(Motorforward_A, 150);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 0);
      analogWrite(Motorbackward_B,150);
      break;

      case 'e':
      analogWrite(Motorforward_A, 255);
      analogWrite(Motorbackward_A, 0);
      analogWrite(Motorforward_B, 100);
      analogWrite(Motorbackward_B,0);
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
