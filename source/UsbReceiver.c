/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    UsbReceiver.c
 * @brief   Application entry point.
 */

/* TODO: insert other include files here. */
#include "Configs.h"



/*******************************************************************************
 * Variables
 ******************************************************************************/
extern bool SW3;
extern bool SW2;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t dadoSalvo[I2C_DATA_LENGTH], dadoEEpromLido[I2C_DATA_LENGTH];
int main(void) {

		uint8_t data;
		i2cDados_t i2c_data;

 	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    //Inicia todos os perigéricos
    iniciaPerifericos();



    while(1)
    {
    	if(!Ds3_GetVal())
    	{
    		SW2 = 0;
    		Led1_PutVal(1);
    		Led2_PutVal(1);
    		Led3_PutVal(1);
    		//Led4_PutVal(1);
    		//Led5_PutVal(1);
    	//	Led6_PutVal(1);
    	}
    	else
    	{
    		Led1_PutVal(0);
    		Led2_PutVal(0);
    		Led3_PutVal(0);
    	}

    	if(!Ds4_GetVal())
    	{
    		SW3 = 0;
    		//Led1_PutVal(0);
    		//Led2_PutVal(0);
    		//Led3_PutVal(0);
    		Led4_PutVal(1);
    		Led5_PutVal(1);
    		Led6_PutVal(1);
    	}
    	else
    	{
    		Led4_PutVal(0);
    		Led5_PutVal(0);
    		Led6_PutVal(0);
    	}


    	__asm volatile ("nop");
    }


    return 0 ;
}
