char receiver_ReadBit()
{
  return digitalRead(rxPin);
}

void receiver_ReadData()
{
  for (int bufferPosition = 0; bufferPosition < maxReceivingDataSize; bufferPosition++)
  {
    receivedData[bufferPosition] = receiver_ReadBit(); //Add new databit on every position of the buffer (only databits)
  }
}

bool receiver_CheckParity(int parityBit)
{
  //Parity has to be uneven.
  int oneCount = 0;

  //count the amount of '1's
  for (int i = 0; i < maxReceivingDataSize; i++)
  {
    if (receivedData[i] == 1)
    {
      oneCount++;
    }
  }

  //Check if paritybit is 1
  if (parityBit == 1)
  {
    oneCount++;
  }

  //Check if it's even or odd by dividing by 2.
  if (oneCount % 2 == 1) //odd
  {
    return true;
  }
  else
  {
    return false;
  }
}


