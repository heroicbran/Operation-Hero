#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;
//char last_command;
void setup()
{
    pinMode(7, OUTPUT);     //RIGHT WHEELS
    pinMode(6, OUTPUT);
    pinMode(4, OUTPUT);    //LEFT WHEELS
    pinMode(3, OUTPUT);
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      String c_buf = (char*)buf;
      Serial.println(c_buf);
      char f_char = c_buf[0];
      // Message with a good checksum received, dump it.
      Serial.println(f_char);
      switch(f_char)
      {
        case '1':
          digitalWrite(4, HIGH);
          digitalWrite(3,HIGH);
          digitalWrite(7, LOW);
          digitalWrite(6,LOW);
          break;   

        case '2':
          digitalWrite(4, HIGH);
          digitalWrite(3,HIGH);
          digitalWrite(7, HIGH);
          digitalWrite(6,HIGH);
          break;   

        case '3':
          digitalWrite(7, HIGH);
          digitalWrite(6,HIGH);
          digitalWrite(4, LOW);
          digitalWrite(3,LOW);
          break;   

        case '4':
          break;   
  
        case '5':
          break;   
  
        case '6':

          break;   
  
        case '7':

          break;   
  
        case '8':

          break;   
  
        case '9':

          break;   
  
        case '*':

          break;   
  
        case '0':

          break;   
  
        case '#':

          break;   
  
        default:
          break;
      }
      
      delay(1000);
      digitalWrite(4, LOW);
      digitalWrite(3,LOW);
      digitalWrite(7, LOW);
      digitalWrite(6,LOW);
    }
}
