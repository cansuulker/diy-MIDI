import themidibus.*; //Import the library

import processing.serial.*;

Serial myPort;  // The serial port

MidiBus myBus; // The MidiBus

void setup() {
  size(400, 400);
  background(0);

  //Serial
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[1], 9600);

  //midi

  MidiBus.list(); // List all available Midi devices on STDOUT. This will show each device's index and name.

  // Either you can
  //                   Parent In Out
  //                     |    |  |
  myBus = new MidiBus(this, 0, 1); // Create a new MidiBus using the device index to select the Midi input and output devices respectively.

  // or you can ...
  //                   Parent         In                   Out
  //                     |            |                     |
  //myBus = new MidiBus(this, "IncomingDeviceName", "OutgoingDeviceName"); // Create a new MidiBus using the device names to select the Midi input and output devices respectively.

  // or for testing you could ...
  //                 Parent  In        Out
  //                   |     |          |
  //myBus = new MidiBus(this, -1, "Java Sound Synthesizer"); // Create a new MidiBus with no input device and the default Java Sound Synthesizer as the output device.
}

void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    println(inByte);
    if(inByte == 67) //c
      convertSerialtoMidi(60,127);
    if(inByte == 35)
      convertSerialtoMidi(61,127);
    else if(inByte == 68) //d
      convertSerialtoMidi(62,127);
    else if(inByte == 51)
      convertSerialtoMidi(63,127);
    else if(inByte == 69) //e
      convertSerialtoMidi(64,127);
    else if(inByte == 70)//f
      convertSerialtoMidi(65,127);
    else if(inByte == 71)//g
      convertSerialtoMidi(67,127);
    else if(inByte == 65)
      convertSerialtoMidi(69,127); 
   else if(inByte == 66)
      convertSerialtoMidi(71,127);
   //else if(inByte > 0 && inByte <15){
   //  convertSerialtoMidi(24,127);
   //  convertSerialtoMidi(25,127);
   //}
      
     
  }
  
  
}

void convertSerialtoMidi(int pitch, int velocity){
  int channel = 0;
  
  myBus.sendNoteOn(channel, pitch, velocity); // Send a Midi noteOn
  delay(200);
  myBus.sendNoteOff(channel, pitch, velocity); // Send a Midi nodeOff

}


//void noteOn(int channel, int pitch, int velocity) {
//  // Receive a noteOn
//  println();
//  println("Note On:");
//  println("--------");
//  println("Channel:"+channel);
//  println("Pitch:"+pitch);
//  println("Velocity:"+velocity);
//}

//void noteOff(int channel, int pitch, int velocity) {
//  // Receive a noteOff
//  println();
//  println("Note Off:");
//  println("--------");
//  println("Channel:"+channel);
//  println("Pitch:"+pitch);
//  println("Velocity:"+velocity);
//}

void controllerChange(int channel, int number, int value) {
  // Receive a controllerChange
  println();
  println("Controller Change:");
  println("--------");
  println("Channel:"+channel);
  println("Number:"+number);
  println("Value:"+value);
}

void delay(int time) {
  int current = millis();
  while (millis () < current+time) Thread.yield();
}