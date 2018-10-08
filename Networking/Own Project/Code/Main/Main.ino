#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
 
// Update these with values suitable for your network.
byte mac[]    = {  0xC8, 0x5B, 0x76, 0x43, 0x0f, 0x1C };
IPAddress ip(172, 16, 0, 100);
const char* server = "broker.example.com"; 
 
EthernetClient ethClient;
PubSubClient mqttClient(ethClient);
 
void setup()
{
  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
  mqttClient.setServer(server, 1883);
 
  if (mqttClient.connect("myClientID")) {
    // connection succeeded
  } else {
    // connection failed
    // mqttClient.state() will provide more information
    // on why it failed.
}
 
void loop()
{
  mqttClient.loop();
}
