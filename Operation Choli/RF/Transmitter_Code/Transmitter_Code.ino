#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
RH_ASK driver;

void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    char *msg;
    String converter;
    char key = keypad.getKey();
 
    if (key != NO_KEY)
    {
      converter += key;
      msg = converter.c_str();
      driver.send((uint8_t *)msg, strlen(msg));
      driver.waitPacketSent();
      delay(100);      
    }

    
}
