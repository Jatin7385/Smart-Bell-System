#include <WiFi.h>    
#include <HTTPClient.h>
#include <UrlEncode.h>

const char* ssid = "Team Sammard is recruiting(VTOP)";
const char* password = "12345678";

const char* host = "api.whatabot.net";
const int httpsPort = 443;

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

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // Send Message to WhatsAPP
  sendMessage("Hello from ESP32!");
}

void loop() {
  
}