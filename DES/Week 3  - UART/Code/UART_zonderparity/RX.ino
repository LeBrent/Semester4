void RXTab_Receive()
{
 char tempByte = 0;
  
  //DisableInterrupt(); //voorkomen dat een andere receive interrupt voorkomt terwijl dit process nog bezig is. Kan waarschijnlijk ook weggelaten worden.
  delayMicroseconds(SampleRate * 1.5);
  {
    for(int tempCount = 0; tempCount < 8; tempCount++)
    {
      tempByte |= (RXPin >> 2) << tempCount;
      delayMicroseconds(SampleRate); //dirty delay
    }
  }
  TXTab_Transmit(tempByte);
}

