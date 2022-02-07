/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 5 Septemper 2020 *****************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

/* Inclution part */
/* LIB layer*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* MCAL layer */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "STK_interface.h"
/* Services layer */
#include "OS_interface.h"

/* Functions prototypes */
void LED1(void);
void LED2(void);
void LED3(void);


/* Main function */
void main(void)
{
  /**    Initialization     **/
  /* RCC initialization */
  MRCC_voidInitSysClock();                                                      /* HSE_CRY / 8 = 1MHZ */
  MRCC_voidEnableClock(EN_GPIO_PORTA);                                          /* GPIOA active clock */
  /* GPIO directions */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_0 , OUTPUT_AF_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_1 , OUTPUT_AF_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_2 , OUTPUT_AF_PUSHPULL_PIN_2MHZ);

  /* Tasks creation */
  SOS_viodCreateTask(0 , 100 , LED1, 1 , Task_Ready);                                           /* Task 0 creation */
  SOS_viodCreateTask(1 , 200 , LED2, 1 , Task_Ready);                                           /* Task 1 creation */
  SOS_viodCreateTask(2 , 300 , LED3, 1,  Task_Ready);                                           /* Task 2 creation */

  /* Start OS */
  SOS_viodOSStart();

  while(1);
}


/* Tasks' functions */
/* Function of task 0 */
void LED1(void)
{
  u8 Local_u8Pin = 0;
  TOG_BIT(Local_u8Pin , 0);
  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_0 , Local_u8Pin);
}

/* Function of task 1 */
void LED2(void)
{
  u8 Local_u8Pin = 0;
  TOG_BIT(Local_u8Pin , 0);
  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_1 , Local_u8Pin);
}
/* Function of task 2 */
void LED3(void)
{
  u8 Local_u8Pin = 0;
  TOG_BIT(Local_u8Pin , 0);
  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_2 , Local_u8Pin);
}
