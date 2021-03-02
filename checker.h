/* ******************************************************************************
 ***     \file        Checker.h
 ***     \ingroup     Session2-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Header file for the module
 ***
 ***     \par         File_description
 ***                  This file have the declarations of the variables and methods of the module
 ***
 *****************************************************************************/
#ifndef BMS_MAIN_H_
#define BMS_MAIN_H_
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
 /*------ standard includes -------*/
#include <stdio.h>

#define BMS_ATTRIBUTE_TEMPERATURE_MIN_VALUE            	0u
#define BMS_ATTRIBUTE_TEMPERATURE_MAX_VALUE            	45u

#define BMS_ATTRIBUTE_SOC_MIN_VALUE            			20u
#define BMS_ATTRIBUTE_SOC_MAX_VALUE            			80u

#define BMS_ATTRIBUTE_CHARGE_RATE_MIN_VALUE            	0u
#define BMS_ATTRIBUTE_CHARGE_RATE_MAX_VALUE            	0.8u

typedef enum {	false, 
				true
}bool;

typedef struct {
    bool temp_Status_b;
    bool soc_Status_b;
    bool chargeRate_Status_b;
    bool bms_Status_b;
} BMS_parameters_s;

void setBMSStatus(bool bms_Status);
void printParameterStatus_As_OutOfRange(char param[]);
bool checkAttribute_OutOfRange(float bms_attribute, float attribute_Min_Value, float attribute_Max_Value, char param[]);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif /*BMS_MAIN_H_*/
