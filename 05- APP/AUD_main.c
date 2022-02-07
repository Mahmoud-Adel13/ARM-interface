/*******************************************************************************/
/* Author : Mahmoud Adel   *****************************************************/
/* Date : 7 September 2020 *****************************************************/
/* Version : V01           *****************************************************/
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "song.h"

/* Prototypes & variables */
void voidSetDAC(void);
volatile u16 i = 0;

/* Main function */
void main(void)
{
	/** RCC initialization **/
	MRCC_voidInitSysClock();
  MRCC_voidEnableClock( EN_GPIO_PORTA);			                                    /* GPIOA clock enable */

  /* Pin directions */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_0 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_1 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_2 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_3 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_4 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_5 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_6 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_7 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);

  /* STK initialization */
  MSTK_voidInit();                                                              /* AHB /  8 = HSE_CRY / 8 = 1MHZ */
  MSTK_voidSetIntervalPeriodic(125 , voidSetDAC );

  while(1);
}

/* Function definitions */
void voidSetDAC(void)
{
  MGPIO_voidSetPortValue(GPIO_PORTA , Song_Array[i]);
  i++;
  if(i == 24242UL)
  {
    i = 0;
  }
}
