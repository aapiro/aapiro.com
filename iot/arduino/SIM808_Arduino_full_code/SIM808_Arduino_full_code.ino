#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial sim808(7,8);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
char phone_no[] = "924232597"; // replace with your phone no.
String data[5];
#define DEBUG true
String state,timegps,latitude,longitude;

void setup() {
 sim808.begin(9600);
 Serial.begin(9600);
 delay(50);

 sim808.print("AT+CSMP=17,167,0,0\r");  // set this parameter if empty SMS received
 delay(100);
 sim808.print("AT+CMGF=1\r"); 
 delay(400);

 sendData("AT+CGNSPWR=1",1000,DEBUG);
 delay(50);
 sendData("AT+CGNSSEQ=RMC",1000,DEBUG);
 delay(20000);
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  sendTabData("AT+CGNSINF",3000,DEBUG);
  if (state !=0) {
    Serial.println("State  :"+state);
    Serial.println("Time  :"+timegps);
    Serial.println("Latitude  :"+latitude);
    Serial.println("Longitude  :"+longitude);
    //sim808.println("AT+CMGS=\"924232597\"");
    // screen output
    lcd.setCursor(0, 0);
    lcd.print("Lat:"+latitude.substring(0, 9));
    lcd.setCursor(0, 1);
    lcd.print("Lon:"+longitude.substring(0, 9));

  // sending sms
    sim808.print("AT+CMGS=\"");
    sim808.print(phone_no);
    sim808.println("\"");

    delay(300);
    sim808.print("LOCATION SUCCESSFULLY FOUND!\nPlease use Google Maps link provided below.\n");
    sim808.print("http://www.google.com/maps/place/");
    sim808.print(latitude);
    sim808.print(",");
    sim808.print (longitude);
    delay(200);
    sim808.println((char)26); // End AT command with a ^Z, ASCII code 26
    delay(200);
    sim808.println();
    delay(20000);
    sim808.flush();

  } else {
    Serial.println("GPS Initialising...");
  }

    latitude = "";
    longitude = "";
    lcd.setCursor(0, 0);
    lcd.print("Cleaning...");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(1000);
    // limpiando pantalla
    lcd.setCursor(0, 0);
    lcd.print("                ");

  
}

void sendTabData(String command , const int timeout , boolean debug){

  sim808.println(command);
  long int time = millis();
  int i = 0;

  while((time+timeout) > millis()){
    while(sim808.available()){
      char c = sim808.read();
      if (c != ',') {
        if(c == ' '){
          c="X";
          }
         data[i] +=c;
         delay(100);
      } else {
        i++;  
      }
      if (i == 5) {
        delay(100);
        goto exitL;
      }
    }
  }exitL:
  if (debug) {
    state = data[1];
    timegps = data[2];
    latitude = data[3];
    longitude =data[4];  
  }
}
String sendData (String command , const int timeout ,boolean debug){
  String response = "";
  sim808.println(command);
  long int time = millis();
  int i = 0;

  while ( (time+timeout ) > millis()){
    while (sim808.available()){
      char c = sim808.read();
      response +=c;
    }
  }
  if (debug) {
     Serial.print(response);
     }
     return response;
}
