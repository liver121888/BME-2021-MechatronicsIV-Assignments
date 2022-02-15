import processing.serial.*;
Serial port;
String inString;
String laststring;
void setup() {
  size(10, 10);
  noStroke();
  background(0);
  printArray(Serial.list());
  ///dev/ttyACM0
  port = new Serial(this, Serial.list()[2], 9600);
  }

int now = 0;
int interval = 100;
void draw() {
    // keep draw() here to continue looping while waiting for keys

  
  if ((millis() - now > interval) && inString != null) {
    now = millis();
    fill(0); 
    rect(700, 70, 60, 60);
    textSize(60);
    fill(255);
    text(inString, 700, 120);
  }

  if ( port.available() > 0) {  // If data is available,
    serialEvent(port);
  }

}

void keyPressed()
{
  if (key == 'w')
    port.write("w");
  else if (key == 'x')
    port.write("x");
  else if (key == 's')
    port.write("s");
  else if (key == 'a')
    port.write("a");
  else if (key == 'd')
    port.write("d");
  else if (key == 'q')
    port.write("q");
  else if (key == 'e')
    port.write("e");
  else if (key == 'o')
    port.write("o");
  else if (key == 'l')
    port.write("l");
  else if (key == '2')
    port.write("2");
}

void serialEvent (Serial port) {
  inString = port.readStringUntil('\n');
  if (inString != null) {
    println(inString);
  }
}
