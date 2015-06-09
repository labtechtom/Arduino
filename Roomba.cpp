/*
   for Roomba class
	Tom Dodge, 6/8/15
*/

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Roomba.h>


Roomba::Roomba(int rx, int tx) {
  if (rooSerial != NULL) {
    delete rooSerial;
  }
  rooSerial = new SoftwareSerial(rx, tx);
  rooSerial->begin(57600);
  _name = "Astro";
}

Roomba::~Roomba() {
  if (rooSerial != NULL) {
    delete rooSerial;
  }
}

void Roomba::Send(byte data) {
  rooSerial->write(data);
}

String Roomba::getName() {
  return _name;
}

void Roomba::Forward() {
  rooSerial->write(DRIVE);
  rooSerial->write(0x01);
  rooSerial->write(0x2c);
  rooSerial->write(0x80);
  rooSerial->write(ZERO);
}

void Roomba::Stop() {
  rooSerial->write(DRIVE);
  rooSerial->write(ZERO);
  rooSerial->write(ZERO);
  rooSerial->write(0x80);
  rooSerial->write(ZERO);
}

void Roomba::Reverse() {
  rooSerial->write(DRIVE);
  rooSerial->write(0xfe);
  rooSerial->write(0xd4);
  rooSerial->write(0x80);
  rooSerial->write(ZERO);
}


void Roomba::CCW() {
  rooSerial->write(DRIVE);
  rooSerial->write(0x01);
  rooSerial->write(0xf4);
  rooSerial->write(ZERO);
  rooSerial->write(0x01);
//  delay(1000*PI()*258/4/300); // at speed 300mm/sec
  Stop();
}

void Roomba::CW() {
  rooSerial->write(DRIVE);
  rooSerial->write(0x01);
  rooSerial->write(0xf4);
  rooSerial->write(0xff);
  rooSerial->write(0xff);
//  delay(1000*PI()*258/4/300); // at speed 300mm/sec
  Stop();
}

void Roomba::SafeMode() {
  rooSerial->write(START);
  delay(50);
  rooSerial->write(CONTROL);
  delay(50);
}

void Roomba::PowerOff() {
  rooSerial->write(POWER);
  delay(50);
}