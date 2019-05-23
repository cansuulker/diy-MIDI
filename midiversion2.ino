#include <MIDI.h>
#include "pitches.h"
#include <Wire.h>
#include "Adafruit_MPR121.h"

uint16_t lasttouched = 0;
uint16_t currtouched = 0;
Adafruit_MPR121 sensor = Adafruit_MPR121();

MIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  MIDI.begin();
  Serial.begin(9600);

  while (!Serial) { 
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!sensor.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {

currtouched = sensor.touched();

if((currtouched & _BV(0)) && !(lasttouched & _BV(0))){
  Serial.write("C"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(0)) && (lasttouched & _BV(0)) ){
  Serial.write("0"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(1)) && !(lasttouched & _BV(1))){
  Serial.write("C#"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(1)) && (lasttouched & _BV(1)) ){
  Serial.write("1"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(2)) && !(lasttouched & _BV(2))){
  Serial.write("D"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(2)) && (lasttouched & _BV(2)) ){
  Serial.write("2"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(3)) && !(lasttouched & _BV(3))){
  Serial.write("D#"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(3)) && (lasttouched & _BV(3)) ){
  Serial.write("3"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(4)) && !(lasttouched & _BV(4))){
  Serial.write("E"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(4)) && (lasttouched & _BV(4)) ){
  Serial.write("4"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(5)) && !(lasttouched & _BV(5))){
  Serial.write("F"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(5)) && (lasttouched & _BV(5)) ){
  Serial.write("5"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(6)) && !(lasttouched & _BV(6))){
  Serial.write("F#"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(6)) && (lasttouched & _BV(6)) ){
  Serial.write("6"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(7)) && !(lasttouched & _BV(7))){
  Serial.write("G"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(7)) && (lasttouched & _BV(7)) ){
  Serial.write("7"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(8)) && !(lasttouched & _BV(8))){
  Serial.write("G#"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(8)) && (lasttouched & _BV(8)) ){
  Serial.write("8"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(9)) && !(lasttouched & _BV(9))){
  Serial.write("A"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(9)) && (lasttouched & _BV(9)) ){
  Serial.write("9"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(10)) && !(lasttouched & _BV(10))){
  Serial.write("A#"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(10)) && (lasttouched & _BV(10)) ){
  Serial.write("10"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}

if((currtouched & _BV(11)) && !(lasttouched & _BV(11))){
  Serial.write("B"); 
  //Serial.println(" touched");
  //MIDI.sendNoteOn(61,127,0);
}
if(!(currtouched & _BV(11)) && (lasttouched & _BV(11)) ){
  Serial.write("11"); 
  //Serial.println(" not touched");
  //MIDI.sendNoteOff(61,0,0);
}
//
lasttouched = currtouched;
////////




  // comment out this line for detailed data from the sensor!
  return;
    Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(sensor.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(sensor.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i=0; i<12; i++) {
    Serial.print(sensor.baselineData(i)); Serial.print("\t");
  }
  Serial.println();
  
  // put a delay so it isn't overwhelming
  delay(100);
  }


