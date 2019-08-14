#include <SoftwareSerial.h>
#include <Gpsneo.h>

Gpsneo gps;


char latitud[15];
char latitudHemisphere[2];
char longitud[15];
char longitudMeridiano[15];

void  setup()
{
    Serial.begin(9600);
}

void loop()
{
    gps.getDataGPRMC(latitud,latitudHemisphere,longitud,longitudMeridiano);

    Serial.println(latitud);
    Serial.println(latitudHemisphere);
    Serial.println(longitud);
    Serial.println(longitudMeridiano);
}
