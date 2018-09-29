//Some variables to prevent magic numbers
const int baudRate = 9600;
const int startBit = 0;
const int stopBit = 1;
const int maxReceivingDataSize = 8;

//switch case states
int cases = 0;

//Buffers
int receivedData[maxReceivingDataSize]; // size of data including stopbit or not? Data is between 5-9 databits according to the slides.

//bools for states, can be deleted afterwards I guess.
bool receiving = false;
bool sending = false;

//RX & TX Pins
const int rxPin = 10;
const int txPin = 11;

//States for Receiving & Sending
enum states
{
  waitingForStartBit, // High to Low | 1 > 0
  readData, //Read the data and put it in a buffer
  checkingParity, // Odd or Even
  clearEverything
};



void setup()
{
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  cases = waitingForStartBit; //waitingForStartBit is 0 translated, a.k.a. begin state.

  Serial.begin(baudRate);
}

void loop()
{
  switch (cases)
  {
    case waitingForStartBit:
      if ((int) receiver_ReadBit() == startBit)
      {
        cases = readData;
      }
      break;
      
    case readData:
      receiver_ReadData();
      cases = checkingParity;
      break;
      
    case checkingParity:
      int parityBit = (int) receiver_ReadBit();
      if (receiver_CheckParity(parityBit) == true)
      {
        cases = waitingForEndBit; //state can be removed
      }
      else
      {
        cases = clearEverything; //wait for next byte
      }
      
      break;
  }
}
