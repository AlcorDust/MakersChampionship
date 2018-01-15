// Museum.pde
 
import processing.serial.*;
Serial myPort;  
String val;  

PImage img;
PFont f;

void setup() {
  size(800, 398);

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);

  img = loadImage("pianta.jpg");
  image(img, 0, 0);

  fill(0,255,0);  
  ellipse(36, 246, 25, 25);

  fill(0,255,0);
  ellipse(89, 282, 25, 25);

  fill(255,0,0);
  textSize(28); 
  text("Crowd Manager", 490, 50); 

  fill(0,0,255);
  textSize(20); 
  text("Stanza Lavagnone", 440, 150); 

  textSize(15);
  text("Stato", 440, 180); 

  fill(0,255,0);
  rect(650, 130, 25, 25);

  fill(0,0,255);
  textSize(20);
  text("Sala Collezioni", 440, 270);

  textSize(15);
  text("Stato", 440, 300); 

  fill(0,255,0);
  rect(650, 250, 25, 25);

}

void draw() {

 if ( myPort.available() > 0) {
  val = myPort.readStringUntil('\n');
  //println(val.charAt(val.length()-2)); 
  
  if(val != null){
  println(val);
  
   if(val.charAt(0) == 'A'){
    println("Apro A"); 
    textSize(15);
    fill(255,0,0);
    rect(650, 130, 25, 25);
    fill(0,255,0);
    rect(650, 250, 25, 25);
    
    fill(255,0,0);
    ellipse(36, 246, 25, 25);
    fill(0,255, 0);
    ellipse(89, 282, 25, 25);
    
    fill(255,0,0);
    //text("OK", 440, 180); 
    //text("TOO MANY!", 440, 300); 
    
  }else if(val.charAt(0) == 'B'){
    println("Apro B"); 
    fill(0,255,0);
    rect(650, 130, 25, 25);
    fill(255,0,0);
    rect(650, 250, 25, 25);
    
    fill(0,255,0);
    ellipse(36, 246, 25, 25);
    fill(255,0,0);
    ellipse(89, 282, 25, 25);

    fill(255,0,0);
    //text("TOO MANY!", 440, 180); 
    //text("OK", 440, 300); 
    
    }
   }
  }
 }
