/*
 Chat  Server

 A simple server that distributes any incoming messages to all
 connected clients.  To use telnet to  your device's IP address and type.
 You can see the client's input in the serial monitor as well.
 Using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <Wire.h>
#include <Nanoshield_Ethernet.h>
#include <Nanoshield_EEPROM.h>

// The MAC address will be read from the EEPROM on the Ethernet Nanoshield
byte mac[6];

// Inialize EEPROM with MAC address
Nanoshield_EEPROM eeprom(1, 1, 0, true);

// telnet defaults to port 23
EthernetServer server(23);
boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
  // Read the MAC address from the Ethernet Nanoshield EEPROM and show it on the terminal
  eeprom.begin();
  eeprom.startReading(0x00FA);
  Serial.println();
  Serial.print("MAC address: ");
  for (int i = 0; i < 5; i++) {
    mac[i] = eeprom.read();
    Serial.print(mac[i], HEX);
    Serial.print(":");
  }
  mac[5] = eeprom.read();
  Serial.println(mac[5], HEX);


  // initialize the ethernet device
  Ethernet.begin(mac);

  // start listening for clients
  server.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      // clead out the input buffer:
      client.flush();
      Serial.println("We have a new client");
      client.println("Hello, client!");
      alreadyConnected = true;
    }

    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();
      // echo the bytes back to the client:
      server.write(thisChar);
      // echo the bytes to the server as well:
      Serial.write(thisChar);
    }
  }
}
