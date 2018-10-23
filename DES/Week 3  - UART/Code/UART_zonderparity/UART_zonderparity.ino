#define SampleRate 104 //berekend aantal microsec per sec : bitrate. 104 microsec

//Cli and Sei vertaling
#define EnableInterrupt() sei()
#define DisableInterrupt() cli()


//Pins
#define RXPin (PIND & 0x04)
#define TXPin (PIND & 0x08)



void setup()
{
  DisableInterrupt(); //Voor de zekerheid alle interrupts weigeren.
  DDRD |= 0x08; //0 input 1 output pin 0-7 TXPIN
  DDRD &= ~0x04; // RXPIN 
  //attachInterrupt(digitalPinToInterrupt(RXPin), RX_ISR, FALLING);
  EIMSK |= _BV(INT0);
  EnableInterrupt(); // toelaten van interrupts. Sei() is voor het niet toelaten.
  //ISR: the ISR to call when the interrupt occurs; this function must take no parameters and return nothing. This function is sometimes referred to as an interrupt service routine.
  //mode: defines when the interrupt should be triggered. Four constants are predefined as valid values:

}
ISR(INT0_vect)
{
  RXTab_Receive();
}


void loop()
{
 
}


//void RX_ISR()
//{
//  RXTab_Receive(); //attachinterrupt werkt niet.
//}


