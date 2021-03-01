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
		FALSE,
		FALSE,
		FALSE
};
/*=============================================================================
 =======                              METHODS                            =======
 =============================================================================*/
 
bool checkTemperature_OutOfRange(float temperature)
{
	bool retTempStatus = FALSE;
	if(temperature < 0 || temperature > 45) 
	{
		printf("Temperature out of range!\n");
		retTempStatus = TRUE;
	}	
	
	return retTempStatus;
}

bool checkSOC_OutOfRange(float soc)
{
	bool retSOC_Status = FALSE;
	if(soc < 20 || soc > 80) {
		printf("State of Charge out of range!\n");
		retSOC_Status = TRUE;
	}	
	return retSOC_Status;
}

bool checkChargeRate_OutOfRange(float chargeRate)
{
	bool retCanregeRate_Status = FALSE;
	if(chargeRate > 0.8) {
		printf("Charge Rate out of range!\n");
		retCanregeRate_Status = TRUE;
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
	
	if((TRUE == BMS_parameters_attributes.temp_Status_b) || (TRUE == BMS_parameters_attributes.soc_Status_b) || (TRUE == BMS_parameters_attributes.chargeRate_Status_b)) 
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
