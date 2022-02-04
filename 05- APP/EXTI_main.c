/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 27 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "AFIO_Interface.h"

void PressBottun(void);

void main(void)
{
  /* RCC initialization */
  MRCC_voidInitSysClock();
  MRCC_voidEnableClock(APB2 , GPIO_PORTA);                                      /* GPIOA clock activation */
  MRCC_voidEnableClock(APB2 , 0);                                               /* AFIO Rcc clock activation */

  /* GPIO directions */
  MGPIO_voidSetPinDir(GPIO_PORTA , 0 , INPUT_PUSHPULL_PIN);                     /* Set A0 as input with pull up resistor */
  MGPIO_voidSetPinDir(GPIO_PORTA , 2 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);            /* Set A2 as output of 2 MHZ */

  /* EXTI initialization */
  MEXTI_viodSetCallBack(PressBottun);                                           /* Set CallBack function */
  MEXTI_voidInit();                                                             /* A0 triggered on falling edge */
  /* EXTI0 enable */
  MEXTI_voidEnableEXTI(LINE0);                                                  /* enable EXTI0 on line 0*/
  MEXTI_voidSetTriggerMode( LINE0 , RISING);                                    /* set rising edge trigger for EXTI0 */
  MAFIO_voidConfigurateEXTILineBit(LINE0 , PA);                                 /* Choose A0 as EXTI0 pin */
  MNVIC_voidSetIntPriority(6 , 2 , 1 , PRIGROUP4);                              /* Set priority for EXTI0 */
  MNVIC_voidEnableInterrupt(6);                                                 /* Enable EXTI0 */

  /* SysTick initialization */
  MSTK_voidInit();

  //MNVIC_voidSetPendingFlag(6);

  while (1)
  {

  }
}


/* ISR */
void PressBottun(void)
{
  /* SET A2 as High output */
  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_2 , HIGH);
  /* Delay for 1 sec */
  MSTk_voidSetBusyWait(1000000);
  /* SET A2 as Low output */
  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_2 , LOW);
  /* Delay for 1 sec */
  MSTk_voidSetBusyWait(1000000);
}
