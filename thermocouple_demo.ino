#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h>
#include <rgb_lcd>
#define ONE_WIRE_BUS 3

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(115200);
  sensors.begin();
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
}

void loop(void)
{ 
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
 // Serial.println("DONE");
   lcd.print("temperature");
   lcd.setCursor(0,1);
  while(1)
  {
  //  Serial.print("Temperature for the device 1 (index 0) is: ");
 //   Serial.println(sensors.getTempCByIndex(0)); 
    sensors.requestTemperatures(); // Send the command to get temperatures

    tem=sensors.getTempCByIndex(0);
    delay(10);
    lcd.print(tem);
    lcd.setCursor(0,1);

    if (tem > 400)
    {
      lcd.setRGB(255, 000, 000);
      digitalWrite(led, HIGH);
      
    }
    
    else 
      lcd.setRGB(255, 255, 255);
      
      
  }

}
