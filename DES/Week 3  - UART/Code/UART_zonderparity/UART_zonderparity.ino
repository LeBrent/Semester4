#define BitRate 9600
#define SampleRate 104 //berekend aantal microsec per sec : bitrate. 104 microsec
#define StartBit 0
#define StopBit 1

unsigned long lastMicroSecs = 0;

//Pins
const int RXPin = 2;
const int TXPin = 3;

//Buffers
char bufRX = 0;
char bufTX = 0;


void setup() 
{
  DDRD |= 0x08; //0 input 1 output pin 0-7 TXPIN
  DDRD &= ~0x04; // RXPIN
  sei(); // toelaten van interrupts. Cli() is voor het niet toelaten.
  // NOTE: NOG INTERRUPT MAKEN VOOR RECEIVEN
  
  
  
  
  

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
