/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 18 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "USART_interface.h"


/* main Function */
void main(void)
{
  /**     RCC initialization     **/
  MRCC_voidInitSysClock();                                                      /* RCC_HSE_CRY = 8 MHz */
  MRCC_voidEnableClock(EN_GPIO_PORTA);                                          /* GPIOA clock enable */
  MRCC_voidEnableClock(EN_USART1);                                              /* GPIOA clock enable */
  /* Pins directions */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_9 , OUTPUT_GP_PUSHPULL_PIN_50MHZ);  /* A9 = TX : output 50 MHZ */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_10 , INPUT_FLOATING_PIN);           /* A10 = RX : input floating */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_0 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);   /* A0 as output 2 MHZ */

  /* USART initialization */
  MUSART_voidInit();

  u8 x;
  while (1)
  {
    MUSART_voidTransmit("97");
    x = MUSART_u8Receive();
    if (x == '5')
    {
      MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_0 , HIGH);
    }
    else if (x == 'R')
    {
      MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_0 , LOW);
    }

  }
}
