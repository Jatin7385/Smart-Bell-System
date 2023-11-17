#include <LoRa.h>
#include <SPI.h>
#include <WiFi.h>    
#include <HTTPClient.h>
#include <UrlEncode.h>

const char* ssid = "Team Sammard is recruiting(VTOP)";
const char* password = "12345678";

const int ledPin =  17;    // the number of the LED pin

// variable for storing the pushbutton status 
int buttonState = 0;
 
#define ss 5
#define rst 14
#define dio0 2

void sendMessage(String message){

  // Data to send with HTTP POST
  String url = "https://api.whatabot.net/whatsapp/sendMessage?apikey=13679369&text=" + message + "&phone=917021856131";    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  if (httpResponseCode == 200){
    Serial.println("Message sent successfully");
    Serial.print("Payload : ");
    Serial.println(http.getString());
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}
 
void setup() 
{
  Serial.begin(115200);  
  
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  while (!Serial);
  Serial.println("LoRa Receiver");
 
  LoRa.setPins(ss, rst, dio0);    //setup LoRa transceiver module
 
  while (!LoRa.begin(433E6))     //433E6 - Asia, 866E6 - Europe, 915E6 - North America
  {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xA5);
  Serial.println("LoRa Initializing OK!");

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() 
{
  int packetSize = LoRa.parsePacket();    // try to parse packet
  if (packetSize) 
  {
    
    Serial.print("Received packet '");
 
    if(LoRa.available())              // read packet
    {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
    }
    
    Serial.print("' with RSSI ");         // print RSSI of packet
    Serial.println(LoRa.packetRssi());

    // Send Message to WhatsAPP
    sendMessage("The bell has been rung! There seems to be someone at the door!");
  }
}