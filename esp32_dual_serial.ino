/* Dual serial example.*/

/* VERY IMPORTANT:
 *  In addition to connecting RX-to-TX and TX-to-RX, make sure you have
 *  a common ground between boards!!!
 */
#include <HardwareSerial.h>

void setup( void )
{
  Serial.begin(115200);
  Serial2.begin(115200);

  Serial.println("ESP32 Dual Serial initialized");
}

void loop( void )
{
  char c2;
  char c;
  static uint32_t last_send_ms = 0;
  uint32_t current_ms;

  /* Print out anything we see on the secondary serial port to our serial monitor */
  while (Serial2.available())
  {
    c2 = Serial2.read();
    Serial.print(c2);
  }



  /* normal operation:  send stuff from serail monitor through S2 */
  while (Serial.available())
  {
    c = Serial.read();
    Serial2.write(c);

    Serial.print("Sent: ");
    Serial.println(c);
  }
    
  
}
