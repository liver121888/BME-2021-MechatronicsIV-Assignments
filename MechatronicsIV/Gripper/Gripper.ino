
void setup() 
{
  Serial.begin(9600); // start serial port at 9600 bps
  myservo.attach(3);  // 設定要將伺服馬達接到哪一個PIN腳
  establishContact();
}

//#include <Servo.h>
//
//Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo
//
//int pos = 0;    // 設定 Servo 位置的變數
//
//void setup() {
//  myservo.attach(9);  // 將 servo 物件連接到 pin 9
//}
//
//void loop() {
//  // 正轉 180度，從 0 度旋轉到 180 度，每次 1 度
//  for (pos = 0; pos <= 60; pos += 1)  
//  {     
//    myservo.write(pos);    // 告訴 servo 走到 'pos' 的位置
//    delay(15);        // 等待 15ms 讓 servo 走到指定位置
//  }
//
//  // 反轉 180度，從 180 度旋轉到 0 度，每次 1 度 
//  for (pos = 60; pos >= 0; pos -= 1) 
//  { 
//    myservo.write(pos);   // 告訴 servo 走到 'pos' 的位置
//
//    delay(15);   // 等待 15ms 讓 servo 走到指定位置
//  }
//}

void loop() 
{   
//  myservo.write(0);
//  delay(1000);
//  myservo.write(30);
//  delay(1000);
      
  if (Serial.available() > 0)
  {
    char serialread = Serial.read();
    switch(serialread){
      case 'r':
      myservo.write(0);
      Serial.print("r\n");
      break;
      case 'g':
      myservo.write(60);
      Serial.print("r\n");
      break;
    }
    
  }
  
}


void establishContact() 
{
  while (Serial.available() <= 0) 
  {
    Serial.print("A\n");   // send a capital A
    delay(1000);
  }
}
