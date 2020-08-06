#include "um0090.h"

ultrasonic_t ultrasonic;

const int trig_pin = 3;

void debug_cb(const char* str)
{
  Serial.println(str);
}

void setup()
{
  Serial.begin(9600); 
  pinMode(trig_pin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(trig_pin, 1);
  //ultrasonic.debug = &debug_cb;
}

void loop() 
{
  static uint16_t old_millis = 0;
  if (millis() - old_millis > 3000)
  {
    old_millis = millis();
    digitalWrite(trig_pin, 0);
    delayMicroseconds(1000);
    digitalWrite(trig_pin, 1);
    delayMicroseconds(50000);
  }
}

void serialEvent()
{
  if (Serial.available() > 0) 
  {
    static int data_idx = 0;
    int val = 0;
    ultrasonic.data = Serial.read();
    ultrasonic.coming_data[data_idx++] = ultrasonic.data;
    Serial.println(ultrasonic.data, HEX);
       
    if (ultrasonic.coming_data[10] == '\xff' && ultrasonic.coming_data[11] == '\xff' && ultrasonic.coming_data[12] == '\xff')
    {
      Serial.println("Measurement Process");
      get_measurement(ultrasonic.coming_data, &val);
      Serial.print("Value: ");
      Serial.print(val);
      Serial.println();
      data_idx = 0;
      memset(ultrasonic.coming_data, 0, sizeof(ultrasonic.coming_data));
    }
  }
}
