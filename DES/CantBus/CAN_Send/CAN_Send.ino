#include <mcp_can.h>
#include <mcp_can_dfs.h>


#include <SPI.h>          //SPI is used to talk to the CAN Controller
#include <mcp_can.h>

MCP_CAN CAN(10);          //set SPI Chip Select to pin 10

int userChoice = 0;


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
    printMenu();
}


void loop()
{
    //CAN.sendMsgBuf(msg ID, extended?, #of data bytes, data array);
    selectMenu();                   
}
