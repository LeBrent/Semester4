void TXTab_Transmit(char tempByte)
{
   PORTD &= ~0x08; //Startbit op 0 zetten.
   delayMicroseconds(SampleRate);

   for(int tempCount = 0; tempCount < 8; tempCount++)
    {
      PORTD = ((tempByte & (0x01 << tempCount)) >> tempCount) << 3; // eerste bit weghalen, juiste positie.
      delayMicroseconds(SampleRate); //dirty delay
    }
   PORTD = 0x01 << 3; //stopbit
}



