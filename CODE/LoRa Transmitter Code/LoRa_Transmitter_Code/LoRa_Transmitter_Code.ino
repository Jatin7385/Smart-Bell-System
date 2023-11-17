#include <LoRa.h>
#include <SPI.h>
 
#define ss 5
#define rst 14
#define dio0 2
 
// set pin numbers
const int buttonPin = 4;  // the number of the pushbutton pin
int LED_BUILTIN = 13;
int counter = 0;

// variable for storing the pushbutton status 
int buttonState = 0;

 
void setup() 
{
  Serial.begin(115200); 
  while (!Serial);
  Serial.println("LoRa Sender");

  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
 
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);

  LoRa.setPins(ss, rst, dio0);    //setup LoRa transceiver module
  
  while (!LoRa.begin(433E6))     //433E6 - Asia, 866E6 - Europe, 915E6 - North America
  {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xA5);
  Serial.println("LoRa Initializing OK!");
}
 
void loop() 
{

  // read the state of the pushbutton value
    buttonState = digitalRead(buttonPin);
    // Serial.println(buttonState);
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH
    if (buttonState == HIGH) {
      // turn LED on
      Serial.println("LED ON");
      digitalWrite(LED_BUILTIN, HIGH);

      Serial.print("Sending packet: ");
      Serial.println(counter);
      LoRa.beginPacket();   //Send LoRa packet to receiver
      LoRa.print("hello ");
      LoRa.print(counter);
      LoRa.endPacket();

      counter++;

      delay(3000);
    } 
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  
  // delay(10000);
}