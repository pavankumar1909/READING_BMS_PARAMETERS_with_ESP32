#ifndef __READ_PARAMETER_H__
#define __READ_PARAMETER_H__


void Rated_Cap_and_Volt_read(float &,float &);
void Balance_StartVolt_and_StartDiffVolt_read(float &,float &);
void Cumulative_charge_and_Discharge_read(float &,float &);
void ShortCurrent_and_CurrentSamplingResistance_read(float &,float &);
void BoardCellsCount_and_NTC_read(int &,int &);
void CellVolt_High_and_Low_read(float &,float &,float&,float&);
void SumVolt_High_and_Low_read(float &,float &,float&,float&);
void Discharge_and_Charge_Cuurent_Large_read(float &,float &);
void Volt_and_temp_difference_Large_read(float &,float &,float &,float &);
void SOC_High_and_Low_read(float &,float &,float &,float &);
void Charge_temp_high_and_low_read(float &,float &);
void Discharge_temp_high_and_low_read(float &,float &);

#endif //__READ_PARAMETER_H__