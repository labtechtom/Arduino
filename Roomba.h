/* class of Roomba to control the operations of a roomba
*	- includes a SoftwareSerial connection with the Arduino
*	- includes some mode selection commands
*	- includes a few driving commands
*	- would like to add sensor commands
*/

#ifndef Roomba_h
#define Roomba_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class Roomba {
  public:
    Roomba(int rx, int tx);
    ~Roomba(void);
    SoftwareSerial* rooSerial;

    // driving commands
    void Forward();
    void Reverse();
    void CCW();
    void CW();
    void Stop();

    // mode commands
    void SafeMode();
    void PowerOff();

    // other commands
    String getName();
    void Send(byte data);

  private:
  // Roomba commands
    byte START = 128;
    byte CONTROL = 130;
    byte SAFE = 131;
    byte DRIVE = 137;
    byte SENSORS = 142;
    byte POWER = 133;

  // needed
    int ZERO = 0;

  // internal variables
    int _speed = 300;  // in mm/sec
    String _name;
};

#endif