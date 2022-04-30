// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>





int analogvalue = 0;
int light;
TCPClient client;

unsigned long myChannelNumber = 1720711;
const char * myWriteAPIKey = "J0P588C12CYKHZGE";

void setup(){

  ThingSpeak.begin(client);
  
  Particle.variable("analogvalue", analogvalue);
  Particle.variable("light", light);
 
Serial.begin(9600);

  pinMode(A0, INPUT);
}

void loop()
{
    delay(500);

  analogvalue = analogRead(A0);
 
  light = (analogvalue); 

  
  
  Particle.publish("Light",String (light), ALL_DEVICES);// sends data to cloud
  ThingSpeak.setField(1,light);
  Serial.print(light);
  Serial.println("light");
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(2000);

}