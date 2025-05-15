#include"headers.h"
#include"read_parameter.h"
#include"hexa_to_decimal.h"

void Rated_Cap_and_Volt_read(float &Rated_Capacity,float &Rated_CellVolt)
{
   float value;
      value=hex_to_dec_singleByte(rxBuf[2],1,4);
      value+=hex_to_dec_singleByte(rxBuf[3],0,2);
      Rated_Capacity=value/1000;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[6],1,4);
      value+=hex_to_dec_singleByte(rxBuf[7],0,2);
      Rated_CellVolt=value/1000;
      memset(rxBuf,0,8);
}

void Balance_StartVolt_and_StartDiffVolt_read(float & Balance_StartVolt,float &Balance_StartDiffVolt)
{
    float value;
      value=hex_to_dec_singleByte(rxBuf[0],1,4);
      value+=hex_to_dec_singleByte(rxBuf[1],0,2);
      Balance_StartVolt=value/1000;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[3],1,2);
      Balance_StartDiffVolt=value/1000;
      memset(rxBuf,0,8);
}
void Cumulative_charge_and_Discharge_read(float & Cumulative_charge,float &Cumulative_Discharge)
{
      float value;
      value=hex_to_dec_singleByte(rxBuf[3],1,2);
      Cumulative_charge=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[7],1,2);
      Cumulative_Discharge=value;
      memset(rxBuf,0,8);
}
void ShortCurrent_and_CurrentSamplingResistance_read(float & ShortCurrent,float &CurrentSamplingResistance)
{
      float value;
      value=hex_to_dec_singleByte(rxBuf[0],1,4);
      value+=hex_to_dec_singleByte(rxBuf[1],0,2);
      ShortCurrent=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[3],1,2);
      CurrentSamplingResistance=value/1000;
      memset(rxBuf,0,8);
}
void BoardCellsCount_and_NTC_read(int &BoardCellsCount,int &BoardNTC)
{
      int value;
      value=hex_to_dec_singleByte(rxBuf[1],1,2);
      BoardCellsCount=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[4],1,2);
      BoardNTC=value;
      memset(rxBuf,0,8);
}
void CellVolt_High_and_Low_read(float& CellVoltHigh1,float& CellVoltHigh2,float& CellVoltLow1,float& CellVoltLow2)
{
      float value;
      value=hex_to_dec_singleByte(rxBuf[0],2,4);
      value+=hex_to_dec_singleByte(rxBuf[1],0,2);
      CellVoltHigh1=value/1000;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[2],2,4);
      value+=hex_to_dec_singleByte(rxBuf[3],0,2);
      CellVoltHigh2=value/1000;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[4],2,4);
      value+=hex_to_dec_singleByte(rxBuf[5],0,2);
      CellVoltLow1=value/1000;
      value=hex_to_dec_singleByte(rxBuf[6],2,4);
      value+=hex_to_dec_singleByte(rxBuf[7],0,2);
      CellVoltLow2=value/1000;
      memset(rxBuf,0,8);
}
void SumVolt_High_and_Low_read(float &SumVoltHigh1 ,float &SumVoltHigh2,float&SumVoltLow1,float&SumVoltLow2)
{
      float value;
      value=hex_to_dec_singleByte(rxBuf[0],2,4);
      value+=hex_to_dec_singleByte(rxBuf[1],0,2);
      SumVoltHigh1=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[2],2,4);
      value+=hex_to_dec_singleByte(rxBuf[3],0,2);
      SumVoltHigh2=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[4],2,4);
      value+=hex_to_dec_singleByte(rxBuf[5],0,2);
      SumVoltLow1=value;
      value=hex_to_dec_singleByte(rxBuf[6],2,4);
      value+=hex_to_dec_singleByte(rxBuf[7],0,2);
      SumVoltLow2=value;
      memset(rxBuf,0,8);
}
// void Discharge_and_Charge_Cuurent_Large_read(float & Discharge,float &)
// {

// }
void Volt_and_temp_difference_Large_read(float & VoltDifferenceLarge1,float &VoltDifferenceLarge2,float &TempDifferenceLarge1,float &TempDifferenceLarge2)
{
      float value;
      value=hex_to_dec_singleByte(rxBuf[0],1,4);
      value+=hex_to_dec_singleByte(rxBuf[1],0,2);
      VoltDifferenceLarge1=value/100;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[2],1,4);
      value+=hex_to_dec_singleByte(rxBuf[3],0,2);
      VoltDifferenceLarge2=value/100;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[4],1,4);
      value+=hex_to_dec_singleByte(rxBuf[5],0,2);
      TempDifferenceLarge1=value/100;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[6],1,4);
      value+=hex_to_dec_singleByte(rxBuf[7],0,2);
      TempDifferenceLarge2=value/100;
      memset(rxBuf,0,8);
}
void SOC_High_and_Low_read(float &SOC_High1,float &SOC_High2,float &SOC_Low1,float &SOC_Low2)
{
      float value;
      value=hex_to_dec_singleByte(rxBuf[0],2,4);
      value+=hex_to_dec_singleByte(rxBuf[1],0,2);
      SOC_High1=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[2],2,4);
      value+=hex_to_dec_singleByte(rxBuf[3],0,2);
      SOC_High2=value;
      value=0;
      value=hex_to_dec_singleByte(rxBuf[6],2,4);
      value+=hex_to_dec_singleByte(rxBuf[7],0,2);
      SOC_Low1=value;
      value=hex_to_dec_singleByte(rxBuf[4],2,4);
      value+=hex_to_dec_singleByte(rxBuf[5],0,2);
      SOC_Low2=value;
      memset(rxBuf,0,8);
}

//void sleep_time();
// void Charge_temp_high_and_low_read()
// {}
// void Discharge_temp_high_and_low_read()
// {}