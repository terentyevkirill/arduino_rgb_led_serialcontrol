int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int red, green, blue;

//#define COMMON_ANODE
#include <SoftwareSerial.h>
#define BT_SERIAL_RX 11
#define BT_SERIAL_TX 10
SoftwareSerial BluetoothSerial(BT_SERIAL_RX, BT_SERIAL_TX);

void setup()
{
  Serial.begin(9600);
  BluetoothSerial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColor(0, 0, 0);
}

void loop()
{
  while (Serial.available()) {       
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();
    red = constrain(red, 0, 255);
    green = constrain(green, 0, 255);
    blue = constrain(blue, 0, 255);

    setColor(red, green, blue);
    Serial.read();
    
    
  
        
  }

}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

}
