#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <SPI.h>

#include <PubSubClient.h>
#include <Stream.h>

const int ledPin =  9;      // the number of the LED pin
String payloadString;
//Wifi data
char ssid[] ="12connect";
int wifiStatus = WL_IDLE_STATUS;
WiFiClient client;

IPAddress server(145,85,4,91);
PubSubClient mqttClient(client);

// Get these at https://apps.fhict.nl/selfservice
char mqttUser[] = "i368111_cihan";
char mqttPass[] = "Num74KuA4WZ8Dn";

// This is the client Id that will be used, the wifi mac will be append!
String mqttClientId = "arduino-";
// This topic will be subscribed to.
// We subscribe to all public topics, but you could make this more specific.
String subscribeTopic = "private/i368111/led";

void callback(char* topic, byte* payload, unsigned int len)
  String received = "";
  for (unsigned int i = 0; i < len; i++)
  {
    char receivedChar = (char)payload[i];
    received += receivedChar;
  }
  Serial.print("ontvangen: ");
  Serial.println(received);
  if (received == "SwitchLed")
  {
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // Try to start and wait for serial connection (or timeout after 5 seconds)
  while ((!Serial) && (millis() < 5000));
  Serial.begin(9600);
  Serial.println("Arduino MQTT to LED");

  // Get the mac and setup the ClientID and topic
  uint8_t mac[6];
  WiFi.macAddress(mac);
  mqttClientId += macToStr(mac);
  Serial.println("Client ID: " + mqttClientId);

  connectWifi();
  if( wifiStatus != WL_CONNECTED) {
    Serial.println("Could not connect to Wifi");
    Serial.println("Try to reset the board inside network range!");
    while(true);
  } else {
    Serial.println("Connected to Wifi");
    Serial.println(WiFi.localIP());
  }

  // Set the correct server for MQTT (either by name or by IPAddress)
  mqttClient.setServer(server,1883);
  // Set the callback, will be called when a message is received.
  mqttClient.setCallback(callback);
  //Try to connect to MQTT
  connectMqtt();
  
}

void loop() {
  // We always try to connect to the wifi.
  if(wifiStatus != WL_CONNECTED)
      connectWifi();

  // Connect to mqtt if nog connected
  while (!mqttClient.connected())
    connectMqtt();

  // Call mqttClient.loop() inside to loop to keep the conection open and listening for events.
  mqttClient.loop();
  
}


// Call to (re)connect to wifi.
void connectWifi(){
  Serial.println("Initializing Wifi...");
  wifiStatus = WiFi.begin(ssid);
}

// Call to connect to the MQTT server
void connectMqtt(){
  if(!mqttClient.connect((char*) mqttClientId.c_str(),mqttUser,mqttPass))
  {
    Serial.println("ERROR: Cannot connect to MQTT server! Error code: " +String(mqttClient.state()));
  }
  else
  {
    Serial.println("Connected to MQTT");
    if(mqttClient.subscribe((char *)subscribeTopic.c_str())){
      Serial.println("Subscribed to topic: "+ subscribeTopic);
    }
  }
}

// Convert the MAC to a string
String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
  }
  return result;
}
 

