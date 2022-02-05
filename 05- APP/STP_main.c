/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 14 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"


/* main function */
void main(void)
{
  /**   RCC initialization     **/
  MRCC_voidInitSysClock();                                                      /* RCC input clock as HSE_CRY = 8MHZ */
  MRCC_voidEnableClock(APB2 , GPIO_PORTA);                                      /* GPIOA clock activation */
  /* Pin direxction configuration */
  MGPIO_voidSetPinDir(STP_SERIAL_DATA , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(STP_SHIFT_CLOCK , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  MGPIO_voidSetPinDir(STP_STORAGE_CLOCK , OUTPUT_GP_PUSHPULL_PIN_2MHZ);

  /*STk initialization */
  MSTK_voidInit();                                                              /* AHB /  8 = HSE_CRY / 8 = 1MHZ */

  HSTP_voidSendSynchronous(125);

while(1);
}
