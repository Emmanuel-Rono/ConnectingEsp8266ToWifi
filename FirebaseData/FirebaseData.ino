#include <FirebaseArduino.h> 
#include <ESP8266WiFi.h>              

#define FIREBASE_HOST "moisturedata-182b0-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "LUZeKYJ1wPSZ1mDBL1hhuwAtUee8ZiCritNj5XKN"            
#define WIFI_SSID "Accesspoint"                                  
#define WIFI_PASSWORD ".CT1.CT2"            
 
int MoistureData=A0;
int moisturelevel;
string  sensorString;
                                       
void setup() 
{ 
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);               
 
}
 
void loop() 
{
  moisturelevel=analogRead(MoistureData);

  Serial.print("MoistureLevel: ");  
  Serial.print(moisturelevel);
  sensorString = String(moisturelevel) + String("%");                   
  delay(50000);
 
  Firebase.setFloat("/DHT11/Humidity", sensorString);            
  Firebase.setFloat("Temprature: ",34.2); 
  delay(3000);
  Firebase.setFloat("Temprature: ",40.2); 
    if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
}