/*
 * Copyright (C) 2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Example for demonstrating SAUL and the SAUL registry
 *
 * @author      Der ich
 *
 * @}
 */

#include <stdio.h>

#include "shell.h"
#include "saul.h" // SAUL_SENSE_TEMP == TYPE

int sensorTempFunction(void);

int main(void)
{

	

	int returnOfsensorTempFunction = 0;

	


	/*Getting Request*/	
	
	sensorTempFunction();

	/* STARTEN DER SHELL */
	char line_buf[SHELL_DEFAULT_BUFSIZE];
	shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);


	return 0;
}

sensorTempFunction() {
	
	saul_reg_t* prt2Sensor = NULL;
	phydat_t valueOfSensor;
	int returnOfSensor = 0;

	prt2Sensor = saul_reg_find_type (SAUL_SENSE_TEMP);// TYPE
	/* nach Typ fragen und dann mit der ID weiter arbeiten!*/
	
	returnOfSensor = saul_reg_read ( prt2Sensor, &valueOfSensor );	
	
	if(returnOfSensor != 0){
		return 1;		
	}
	else{
		printf("%d", valueOfSensor.val[0]);
	}
	return 0;
}