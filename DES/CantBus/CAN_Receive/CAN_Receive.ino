#include <mcp_can.h>
#include <mcp_can_dfs.h>


#include <SPI.h>          //SPI is used to talk to the CAN Controller
#include <mcp_can.h>

MCP_CAN CAN(10);          //set SPI Chip Select to pin 10

unsigned char len = 0;
unsigned char buf[8];
unsigned int canID;

void setup()
{
  Serial.begin(115200);   //to communicate with Serial monitor
  
//tries to initialize, if failed --> it will loop here for ever
START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))      //setting CAN baud rate to 500Kbps
    {
        Serial.println("CAN BUS Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
        goto START_INIT;
    }
}



void loop()
{
    if(CAN_MSGAVAIL == CAN.checkReceive())    //check if data is coming
    {
        
        CAN.readMsgBuf(&len, buf);    //read data,  len: data length, buf: data buffer
        canID = CAN.getCanId();       //getting the ID of the incoming message

        Serial.print("ID is: ");
        Serial.print(canID, HEX);     //printing the ID in its standard form, HEX

        Serial.print("    Length is: ");
        Serial.println(len);
        
        for(int i = 0; i<len; i++)    //looping on the incoming data to print them
        {
            Serial.write(buf[i]);     //Serial.write prints the character itself
        }
        if (canID == 0x53) // ID = 53, Stuurwiel radio controle
        {
          if (buf[0] & 0x01)
          {
            Serial.println("\n Volume up");
          }
          else if (buf[0] & 0x02)
          {
            Serial.println("\n Volume down");
          }
          else if (buf[0] & 0x04)
          {
            Serial.println("\n Saved Station");
          }
          else if (buf[0] & 0x08)
          {
            Serial.println("\n Next station");
          }
          else if (buf[0] & 0x10)
          {
            Serial.println("\n Previous station");
          }
          
        }
        else if (canID == 0x52)
        {
          if (buf[0] & 0x01)
          {
            Serial.println("\n Richting kort links");
          }
          else if (buf[0] & 0x02)
          {
            Serial.println("\n Richting kort rechts");
          }
           else if (buf[0] & 0x01 && buf[1] & 0x01)
          {
            Serial.println("\n Richting lang links");
          }
           else if (buf[0] & 0x02 && buf[1] & 0x01)
          {
            Serial.println("\n Richting lang rechts");
          }
        }
        Serial.println("\n\t*****************\n");
    }
}
