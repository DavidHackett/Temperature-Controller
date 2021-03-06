/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <SPI.h>


// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
#define SteadyTemp 75

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 


// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 
void setup(void) 
{ 
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
 
 // start serial port 
 Serial.begin(9600); 
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 
 sensors.begin(); 

} 
void loop() 
{ 


 sensors.requestTemperatures(); // Send the command to get temperature readings 
 
/********************************************************************/
float temp = sensors.getTempFByIndex(0);
 Serial.println("Temperature is: "); 
 Serial.println(temp);
 Serial.println();

 
/********************************************************************/

 
   delay(1000); 
} 
