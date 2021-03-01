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
#include "Checker.h"

/*=============================================================================
 =======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
 =============================================================================*/

/*=============================================================================
 =======                       CONSTANTS  &  TYPES                       =======
 =============================================================================*/

/*=============================================================================
 =======                VARIABLES & MESSAGES & RESSOURCEN                =======
 ==============================================================================*/
BMS_parameters_s BMS_parameters_attributes = {
		false,
		false,
		false
};
/*=============================================================================
 =======                              METHODS                            =======
 =============================================================================*/
 
bool checkTemperature_OutOfRange(float temperature)
{
	bool retTempStatus = false;
	if(temperature < 0 || temperature > 45) 
	{
		printf("Temperature out of range!\n");
		retTempStatus = true;
	}	
	
	return retTempStatus;
}

bool checkSOC_OutOfRange(float soc)
{
	bool retSOC_Status = false;
	if(soc < 20 || soc > 80) {
		printf("State of Charge out of range!\n");
		retSOC_Status = true;
	}	
	return retSOC_Status;
}

bool checkChargeRate_OutOfRange(float chargeRate)
{
	bool retCanregeRate_Status = false;
	if(chargeRate > 0.8) {
		printf("Charge Rate out of range!\n");
		retCanregeRate_Status = true;
	}		
	return retCanregeRate_Status;
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
	
	BMS_parameters_attributes.temp_Status_b = checkTemperature_OutOfRange(temperature);
	BMS_parameters_attributes.soc_Status_b = checkSOC_OutOfRange(soc);
	BMS_parameters_attributes.chargeRate_Status_b = checkChargeRate_OutOfRange(chargeRate);
	
	if((true == BMS_parameters_attributes.temp_Status_b) || (true == BMS_parameters_attributes.soc_Status_b) || (true == BMS_parameters_attributes.chargeRate_Status_b)) 
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
