

void selectMenu()
{
  unsigned char data[8] = {'0x00', '0x00', '0x00', '0x00', '0x00', '0x00', '0x00', '0x00'};
  if (Serial.available() > 0)
  {
    userChoice = Serial.parseInt(); // Read user input
    Serial.print("User entered: ");
    Serial.println(userChoice);
  }
  switch (userChoice)
  {
    case 0: //Spam berichten voorkomen
      // NIKS DOEN
      break;
    case 1:
      Serial.println("Richting kort links");
      data[0] = '0x01';
      CAN.sendMsgBuf(0x52, 0, 8, data);
      userChoice = 0;
      break;
    case 2:
      Serial.println("Richting kort rechts");
      data[0] = '0x02';
      CAN.sendMsgBuf(0x52, 0, 8, data);
      userChoice = 0;
      break;
    case 3:
      Serial.println("Richting lang links");
      data[0] = '0x01';
      data[1] = '0x01';
      CAN.sendMsgBuf(0x52, 0, 8, data);
      userChoice = 0;
      break;
    case 4:
      Serial.println("Richting lang rechts");
      data[0] = '0x02';
      data[1] = '0x01';
      CAN.sendMsgBuf(0x52, 0, 8, data);
      userChoice = 0;
      break;
    case 5:
      Serial.println("Volume omhoog");
      data[0] = '0x01';
      CAN.sendMsgBuf(0x53, 0, 8, data);
      userChoice = 0;
      break;
    case 6:
      Serial.println("Volume omlaag");
      data[0] = '0x02';
      CAN.sendMsgBuf(0x53, 0, 8, data);
      userChoice = 0;
      break;
    case 7:
      Serial.println("Volgend station");
      data[0] = '0x08';
      CAN.sendMsgBuf(0x53, 0, 8, data);
      userChoice = 0;
      break;
    case 8:
      Serial.println("Vorig station");
      data[0] = '0x10';
      CAN.sendMsgBuf(0x53, 0, 8, data);
      userChoice = 0;
      break;
    case 9:
      Serial.println("Opgeslagen Station");
      data[0] = '0x04';
      CAN.sendMsgBuf(0x53, 0, 8, data);
      userChoice = 0;
      break;
  }
}

