/*
 * Interrupcoes.c
 *
 *  Created on: 18 de mai de 2021
 *      Author: Rosimar
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL33Z644.h"
#include "configs.h"
#include "fsl_lpuart.h"
/* TODO: insert other include files here. */

bool SW3;
bool SW2;

typedef struct _dataDisplay
{
	uint8_t highByte;
	uint8_t lowByte;
	uint8_t ByteLeght;
	uint8_t function;
	uint8_t datavp1;
	uint8_t datavp2;
	uint8_t dataUnsolved;
	uint8_t dataKeyValue1;
	uint8_t dataKeyValue2;
	uint8_t dataSeven;

	uint8_t byteDisp;

	uint8_t  pontDisp;

}dataDisplay;

/* LPUART0_IRQn interrupt handler */
void LPUART0_SERIAL_RX_TX_IRQHANDLER(void) {
	char dado;
	dataDisplay data;

	  if ((kLPUART_RxOverrunFlag ) & LPUART_GetStatusFlags(LPUART0))
	  {
		  LPUART_ClearStatusFlags(LPUART0_PERIPHERAL, kLPUART_RxOverrunFlag);
	  }

    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART0))
    {
    	dado = LPUART_ReadByte(LPUART0);
    	switch(data.pontDisp)
    	{
    		case 0: data.highByte = LPUART_ReadByte(LPUART0); break;

    		case 1: data.lowByte = LPUART_ReadByte(LPUART0);break;

    		case 2: {data.ByteLeght = LPUART_ReadByte(LPUART0); data.byteDisp = data.ByteLeght;}break;

    		case 3: data.function = LPUART_ReadByte(LPUART0);break;

    		case 4: data.datavp1 = LPUART_ReadByte(LPUART0);break;

    		case 5: data.datavp2 = LPUART_ReadByte(LPUART0);break;

    		case 6: data.dataUnsolved = LPUART_ReadByte(LPUART0);break;

    		case 7: data.dataKeyValue1 = LPUART_ReadByte(LPUART0);break;

    		case 8: data.dataKeyValue1 = LPUART_ReadByte(LPUART0);break;

    		case 9: data.dataSeven = LPUART_ReadByte(LPUART0);break;

    	}

    	data.pontDisp++;

    	if(data.pontDisp > 3)
    	{
    		if(data.pontDisp == data.byteDisp)
    		{
    			//leituraDisplay(&data);
    			data.pontDisp = 0;

    			data.byteDisp = 0;
    		}
    	}


    }


  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

/* PORTB_PORTC_PORTD_PORTE_IRQn interrupt handler */

// Nesta interrupção faz a leitura das entradas SW2 e SW3 somente
void GPIOC_IRQHANDLER(void) {
  /* Get pin flags */

  uint32_t pin_flags = GPIO_PortGetInterruptFlags(GPIOC);

 switch(pin_flags)
 {
 	 case 4:SW3 = 1; break;
 	 case 8: SW2 = 1; break;
 	 default :
 	 {
 		 SW3 = 0;
 		 SW2 = 0;
 	 }break;
 }


  /* Place your interrupt code here */

  /* Clear pin flags */
  GPIO_PortClearInterruptFlags(GPIOC, pin_flags);

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}



