# Smart-Bell-System
Developing a Smart Bell System for Home. This is an altogether custom Smart Bell System made using ESP32's and LoRa modules. There is another method, I have to extend the signal sent by a pre-existing smart bell by routing it through an ESP32(Which will be out soon. Scarcity of components, and time at home is preventing the same)

## SENDER Circuit(Doorbell)
![CIRCUIT](https://github.com/Jatin7385/Smart-Bell-System/assets/73430464/80ef31ae-9696-4a73-b215-e9d02a0e8bc7)
- ESP32
- Push Button
- LED
- LoRa Module

# RECEIVER Circuit (Room inside House)
![CIRCUIT](https://github.com/Jatin7385/Smart-Bell-System/assets/73430464/167a665e-7223-4669-a800-2883244e9b9e)
- ESP32
- LoRa Module
- Pizoelectric Buzzer

Currently, when the bell is ringed(Push Button is pressed), we are transmitting the signal to the receiver and the buzzer is buzzed. Alongside that, the receiver is sending a whatsapp message to someone from the 
household.
![Whatsapp Message received](https://github.com/Jatin7385/Smart-Bell-System/assets/73430464/5be2130e-1373-4188-be87-f7206e920654)


## Future steps : 
1) Camera at front door, to send picture along with just an alert. Maybe add Facial Recognition, or voice recognition. Or even ask the person to say their identity, which is sent through WhatsApp. Maybe even voice commands
2) LCD's on both Circuits, to configure/view status of the bell system.
3) Currently everything is on a breadboard. Make a PCB out of this! Enclosed in a 3D printed box.
