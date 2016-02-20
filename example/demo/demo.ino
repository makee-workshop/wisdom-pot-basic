// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"
#include <Bridge.h>#
#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
  
  Bridge.begin(); 
 
  dht.begin();
  
  
  delay(5000);
  
  
  
}

void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  
  
   Serial.println("dirty:");
   int dirtyVal = analogRead(1);
   Serial.println(dirtyVal);
  
  Serial.println("light:");
   int lightVal = analogRead(2);
   Serial.println(lightVal); 

  Bridge.put("t", String(t));
  Bridge.put("h", String(h));
  Bridge.put("l", String(lightVal));
  Bridge.put("d", String(dirtyVal));
   
   delay(1000);
}
