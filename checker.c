/* ******************************************************************************
 ***
 ***     \file        Checker.c
 ***     \ingroup     Session2-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Main file to check BMS
 ***
 ***     \par         File_description
 ***                  This file explores more about functions
 ***
 *****************************************************************************/
 
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
 /*------ standard includes -------*/
#include <stdio.h>
#include <assert.h>

/*------ module includes --------*/
#include "checker.h"

/*=============================================================================
 =======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
 =============================================================================*/

/*=============================================================================
 =======                       CONSTANTS  &  TYPES                       =======
 =============================================================================*/

/*=============================================================================
 =======                VARIABLES & MESSAGES & RESSOURCEN                =======
 ==============================================================================*/
static BMS_parameters_s BMS_parameters_attributes = {
		false,
		false,
		false,
		false
};
/*=============================================================================
 =======                              METHODS                            =======
 =============================================================================*/

bool checkAttribute_OutOfRange(float bms_attribute, float attribute_Min_Value, float attribute_Max_Value, char param[])
{
	bool retAtributeStatus = false;
	if(bms_attribute < attribute_Min_Value || bms_attribute > attribute_Max_Value) 
	{
		printParameterStatus_As_OutOfRange(param);
		retAtributeStatus = true;
		setBMSStatus(true);
	}	
	
	return retAtributeStatus;
}

void printParameterStatus_As_OutOfRange(char param[])
{
	printf("%s out of range!\n",param);
}

void setBMSStatus(bool bms_Status)
{
	BMS_parameters_attributes.bms_Status_b = true;
}
/*---------------------------------------------------------------------------*/
/*     FUNCTION: batteryIsOk
 */
/*!    \brief   Function to test BMS parameters 
 *
 *
 *     \param    none
 *     \returns  int
 *
 *//*------------------------------------------------------------------------*/
int batteryIsOk(float temperature, float soc, float chargeRate) {
	
	BMS_parameters_attributes.temp_Status_b = checkAttribute_OutOfRange(temperature,BMS_ATTRIBUTE_TEMPERATURE_MIN_VALUE,BMS_ATTRIBUTE_TEMPERATURE_MAX_VALUE,"Temperature");
	BMS_parameters_attributes.soc_Status_b = checkAttribute_OutOfRange(soc,BMS_ATTRIBUTE_SOC_MIN_VALUE,BMS_ATTRIBUTE_SOC_MAX_VALUE,"State of Charge");
	BMS_parameters_attributes.chargeRate_Status_b = checkAttribute_OutOfRange(chargeRate,BMS_ATTRIBUTE_CHARGE_RATE_MIN_VALUE,BMS_ATTRIBUTE_CHARGE_RATE_MAX_VALUE,"Charge Rate");
	
	//BMS_parameters_attributes.bms_Status_b = ((true == BMS_parameters_attributes.temp_Status_b) || (true == BMS_parameters_attributes.soc_Status_b) || (true == BMS_parameters_attributes.chargeRate_Status_b))?1:0;
	
	if( true == BMS_parameters_attributes.bms_Status_b) 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: main
 */
/*!    \brief   Function to test BMS parameters 
 *
 *
 *     \param    none
 *     \returns  int
 *
 *//*------------------------------------------------------------------------*/
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
