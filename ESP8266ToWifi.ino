

#include "ESP8266WiFi.h"
const char* ssid = "Accesspoint"; 
const char* password = ".CT1.CT2"; 

void setup(void)
{ 
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}
void loop() {
  // Nothing
}
