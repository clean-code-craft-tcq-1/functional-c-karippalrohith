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

typedef enum {	false, 
				true
}bool;

typedef struct {
    bool temp_Status_b;
    bool soc_Status_b;
    bool chargeRate_Status_b;
    bool bms_Status_b;
} BMS_parameters_s;

bool checkTemperature_OutOfRange(float temperature);
bool checkSOC_OutOfRange(float soc);
bool checkChargeRate_OutOfRange(float chargeRate);
void setBMSStatus(bool bms_Status);
void printParameterStatus(char param[]);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif /*BMS_MAIN_H_*/


