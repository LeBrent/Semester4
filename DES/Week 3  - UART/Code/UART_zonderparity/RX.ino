void Receive()
{
  cli(); //voorkomen dat een andere receive interrupt voorkomt terwijl dit process nog bezig is
  lastMicroSecs = micros();
  
}

