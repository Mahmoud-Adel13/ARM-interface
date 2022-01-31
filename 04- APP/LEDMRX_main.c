/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 31 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "RCC_interface.h"
#include "LEDMRX_interface.h"

u8 DataArray[8] = {129, 195, 165, 153, 129, 129, 129, 129};
/* main function: */
void main(void)
{
  /* Initialization for prepherals */
  MRCC_voidInitSysClock();                                                      /* Intialize system clock */
  MRCC_voidEnableClock(APB2 , GPIO_PORTA);                                      /* GPIOA enable clock */
  MRCC_voidEnableClock(APB2 , GPIO_PORTB);                                      /* GPIOB enable clock */
  MSTK_voidInit();                                                              /* Systick Initialization */
  HLEDMRX_voidInit();                                                           /* Led matrix Initialization */

  /* main code: */
  /* Send data to led matrix */
  HLEDMRX_voidDisplay(DataArray);
}
