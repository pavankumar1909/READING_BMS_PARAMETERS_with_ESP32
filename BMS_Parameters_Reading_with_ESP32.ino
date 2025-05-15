// CAN MCP2515= ESP32 SEND 1A DATA 
/*
SI-23
S0-19
SCK-18
CS -5
INT-14

*/
#include "headers.hpp"
#include "defines.hpp"
#include "read_parameter.hpp"

#define SEND_ID 0x18500A40  // CAN ID to send
#define RECEIVE_ID 0x0000002A  // Expected CAN ID to receive


#define CAN0_INT 14  //ESP32 pin14
#define CS_PIN 5     //ESP32 pin5

// enum RegisterNames {
//   REG1=50,
//   REG2,
//   REG3,
//   REG_COUNT
// };

#define paste(x) READ_REG_ ## x
MCP_CAN CAN0(CS_PIN); //initialise an object
unsigned long previousMillis = 0;
const int sendInterval = 1000;

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
int CANcurrent , CANvoltage;
byte sendData[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
unsigned long WRITE_REG_ADD[10] = {WRITE_REG_50,WRITE_REG_51,WRITE_REG_52, WRITE_REG_60,WRITE_REG_5F,WRITE_REG_59,WRITE_REG_5A, WRITE_REG_5D,WRITE_REG_5E};
char msgString[128];



void setup() 
{
  Serial.begin(9600);


  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) 
  {
    Serial.println("MCP2515 Initialized Successfully!");
  } 
  else 
  {
    Serial.println("Error Initializing MCP2515...");
    while (1);
  }

  CAN0.setMode(MCP_NORMAL);
  pinMode(CAN0_INT, INPUT);
  Serial.println("Starting CAN Communication...");
}

void sendCANMessage(unsigned long REG) 
{
  byte sndStat = CAN0.sendMsgBuf(REG, 1, 8, sendData); // Sending Extended Frame with data
  if (sndStat == CAN_OK) 
  {
    Serial.println("CAN Message Sent Successfully!");
    //Serial.println(addr);
  } 
  else 
  {
    Serial.println("CAN Error Sending ...");
  }
}

float parameter_f1=0,parameter_f2=0,parameter_f3,parameter_f4;
int parameter_i1=0,parameter_i2=0;
void receiveCAN_BMS() 
{
  if (!digitalRead(CAN0_INT)) 
  {
    
    CAN0.readMsgBuf(&rxId, &len, rxBuf);
     String S = String(rxId, HEX);
    Serial.print("The String is ["); Serial.print(S); Serial.println("]");
    if(rxId==0x9850400A)
    {
      Rated_Cap_and_Volt_read(parameter_f1,parameter_f2);
      Serial.print("Rated_Capacity:");
      Serial.print(parameter_f1);
      Serial.print("Ah ");
      Serial.print("Rated_CellVolt:");
      Serial.print(parameter_f2);
      Serial.println("V");
    }
    else if(rxId==0x985F400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      Balance_StartVolt_and_StartDiffVolt_read(parameter_f1,parameter_f2);
      Serial.print("Balance_StartVolt:");
      Serial.print(parameter_f1);
      Serial.print("V ");
      Serial.print("Balance_StartDiffVolt:");
      Serial.print(parameter_f2);
      Serial.println("V");
    }
    else if(rxId==0x9852400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      Cumulative_charge_and_Discharge_read(parameter_f1,parameter_f2);
      Serial.print("Cumulative_charge:");
      Serial.print(parameter_f1);
      Serial.print("Ah ");
      Serial.print("Cumulative_Discharge:");
      Serial.print(parameter_f2);
      Serial.println("Ah");
    }
    else if(rxId==0x9860400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      ShortCurrent_and_CurrentSamplingResistance_read(parameter_f1,parameter_f2);
      Serial.print("ShortCurrent:");
      Serial.print(parameter_f1);
      Serial.print("A ");
      Serial.print("CurrentSamplingResistance:");
      Serial.print(parameter_f2);
      Serial.println("mOhm");
    }
    else if(rxId==0x9851400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      BoardCellsCount_and_NTC_read(parameter_i1,parameter_i2);
      Serial.print("BoardCellsCount:");
      Serial.print(parameter_i1);
      Serial.print(" ");
      Serial.print("BoardNTC:");
      Serial.println(parameter_i2);
     }
      else if(rxId==0x9859400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      CellVolt_High_and_Low_read(parameter_f1,parameter_f2,parameter_f3,parameter_f4);
      Serial.print("CellVoltHigh1:");
      Serial.print(parameter_f1);
      Serial.print(" ");
      Serial.print("CellVoltHigh2:");
      Serial.print(parameter_f2);
      Serial.print(" ");
      Serial.print("CellVoltLow1:");
      Serial.print(parameter_f3);
      Serial.print(" ");
      Serial.print("CellVoltLow2:");
      Serial.println(parameter_f4);
     }
      else if(rxId==0x985A400A)
     {
      //  Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      CellVolt_High_and_Low_read(parameter_f1,parameter_f2,parameter_f3,parameter_f4);
      Serial.print("SumVoltHigh1:");
      Serial.print(parameter_f1);
      Serial.print(" ");
      Serial.print("SumVoltHigh2:");
      Serial.print(parameter_f2);
      Serial.print(" ");
      Serial.print("SumVoltLow1:");
      Serial.print(parameter_f3);
      Serial.print(" ");
      Serial.print("SumVoltLow2:");
      Serial.println(parameter_f4);
     }
      else if(rxId==0x985B400A)
      {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      //  Serial.println();
     }
     else if(rxId==0x9853400A)
     {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      //  Serial.println();
     }
      else if(rxId==0x985E400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      Volt_and_temp_difference_Large_read(parameter_f1,parameter_f2,parameter_f3,parameter_f4);
      Serial.print("VoltDifferenceLarge1:");
      Serial.print(parameter_f1);
      Serial.print(" ");
      Serial.print("VoltDifferenceLarge2:");
      Serial.print(parameter_f2);
      Serial.print(" ");
      Serial.print("TempDifferenceLarge1:");
      Serial.print(parameter_f3);
      Serial.print(" ");
      Serial.print("TempDifferenceLarge12:");
      Serial.println(parameter_f4);
     }
    else if(rxId==0x985D400A)
    {
      // Serial.print("Data: ");
      // for (byte i = 0; i < len; i++) 
      // {
      //   sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //   Serial.print(msgString);
      // }
      // Serial.println();
      SOC_High_and_Low_read(parameter_f1,parameter_f2,parameter_f3,parameter_f4);
      Serial.print("SOC_High1:");
      Serial.print(parameter_f1);
      Serial.print(" ");
      Serial.print("SOC_High2:");
      Serial.print(parameter_f2);
      Serial.print(" ");
      Serial.print("SOC_Low1:");
      Serial.print(parameter_f3);
      Serial.print(" ");
      Serial.print("SOC_Low2:");
      Serial.println(parameter_f4);
     }
  
    }
}
int count=0;
void loop() 
{

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= sendInterval) 
  {
    previousMillis = currentMillis;
    if(count==10)
     count=0;
    Serial.println(count);
    sendCANMessage(WRITE_REG_ADD[count]); // Sending Extended Frame with data
    //Serial.println(paste(50),HEX);
    count++;
     
  }
  // Check for incoming messages
  receiveCAN_BMS();
}