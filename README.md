# AM2302-DHT22-module-128x64OLED
```
Making a room thermometer with ArduinoUno,AM2302-DHT22 module(Temp/Humidity sensor),
and a small OLED to display the temperature at.

Very beginer friendly.Almost line by line explanation with comments in code.

Pinout: Oled|Arduino
         SDA: A4
         SCL: A5
         VCC: 5V(or 3.3V if the screen needs 3.3V)
         GND: GND

      DHT-22|Arduino
         VCC: 5V (or 3.3V if the sensor needs 3.3V)
         GND: GND
         DAT: Pin6 (Line 10: #define DHTPIN 6)



Scematic:
                +-------------------+
                |    Arduino        |
                |-------------------|
                |               GND |-o-----------------------┬----------------------------┐         
                |              Pin6 |-o-----------┐        GND┴o-+-------------------+     |
                |                5V |----------┐  └--------DAT-o-|   AM2302 Module   |     |
                |          (SDA) A4 |--o       ├------------5V-o-+-------------------+     |
                |          (SCL) A5 |-o|       |                                           |
                +-------------------+ ||	  |                                           |		
                                      ||       |                                           |
                                      ||       | ┌-----------------------------------------┘
                                      ||       | |  +-------------------+
                                      ||	  | |  |   128x64 OLED     |
                                      ||   	  | |  |-------------------|
                                      ||       | └o-| GND               |
                                      ||       |    |                   |
                                      ||       └o---| VCC               |
                                 	  || 	       |                   |
                                      |└-------o----| SDA               |
                                      |	       |                   |
                                      └--------o----| SCL               |
                                                    |                   |
                                                    +-------------------+

```
