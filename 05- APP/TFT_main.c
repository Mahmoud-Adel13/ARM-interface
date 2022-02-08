/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 21 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"


/* main Function */
void main(void)
{
  /**     RCC initialization     **/
  MRCC_voidInitSysClock();                                                      /* HSE_CRY = 8 MHZ */
  MRCC_voidEnableClock(EN_GPIO_PORTA);                                          /* GPIOA enable clock */
  MRCC_voidEnableClock(EN_SPI1);                                                /* SPI1 enable clock */

  /* GPIOA pins directions */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_1 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);   /* A1 = TFT_RST_PIN as output 2 MHZ */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_2 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);   /* A2 = TFT_A0_PIN as output 2 MHZ */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_5 , OUTPUT_AF_PUSHPULL_PIN_10MHZ);  /* A5 = TFT_CLK_PIN as output 2 MHZ */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_7 , OUTPUT_AF_PUSHPULL_PIN_10MHZ);  /* A7 = TFT_MOSI_PIN as output 2 MHZ */

  /**      STK initialization    **/
  MSTK_voidInit();                                                              /* AHB / 8 = 1 MHZ */

  /**     SPI initialization     **/
  MSPI1_voidInit();                                                             /* Uc as master */

  /**     TFT initialization     **/
  HTFT_voidInit();

  /* Image Display */
  //HTFT_voidDisplayImage(image);

  while(1);
}
