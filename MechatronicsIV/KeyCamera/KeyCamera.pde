import processing.serial.*;
import processing.video.*;
Serial port;
Capture cam;
String inString;
String laststring;
void setup() {
  size(10, 10);
  noStroke();
  background(0);
  printArray(Serial.list());
  ///dev/ttyACM0
  port = new Serial(this, Serial.list()[2], 9600);
  
  String[] cameras = Capture.list();    
  if (cameras.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  } else {
    println("Available cameras:");
    for (int i = 0; i < cameras.length; i++) {
      println(cameras[i]);
    }
    // The camera can be initialized directly using an 
    // element from the array returned by list():
    cam = new Capture(this, cameras[0]);
    cam.start();  
  }
}
int now = 0;
int interval = 100;
void draw() {
    // keep draw() here to continue looping while waiting for keys
    if (cam.available() == true) {
    cam.read();
  }
  image(cam, 0, 0);
  // The following does the same, and is faster when just drawing the image
  // without any additional resizing, transformations, or tint.
  //set(0, 0, cam);
  
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
  else if (key == 'o')
    port.write("o");
  else if (key == 'l')
    port.write("l");
}

void serialEvent (Serial port) {
  inString = port.readStringUntil('\n');
  if (inString != null) {
    println(inString);
  }
}
