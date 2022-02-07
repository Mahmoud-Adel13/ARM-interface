/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 18 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

/* Function definitions */
void MUSART_voidInit(void)
{
  /* Clear CR1 register */
  USART1->CR1 = 0x0000;
  /* Clear CR1 register */
  USART1->CR2 = 0x0000;
  /**       Configuration options       **/
  /* Data width */
  USART1->CR1 |= (Data_WIDTH << 12);
  /* Stop bits */
  USART1->CR2 |= (STOP_BITS << 12);
  /* Parity check */
  USART1->CR1 |= (PARITY << 10);                                                /* parity check enable or disable */
  USART1->CR1 |= (PARITY_TYPE << 9);                                            /* Odd or Even parity */
  /* Asynchronous mode */
  USART1->CR2 |= (ASYNCH_CLOCK << 11);                                          /* Asynchronous enable or disable */
  #if ASYNCH_CLOCK == ENABLED
    USART1->CR2 |= (CLOCk_POL << 10);                                           /* Clock polarity */
    USART1->CR2 |= (CLOCk_PHASE << 9);                                          /* Clock phase */
  #endif

  /**   Baud rate   **/
  USART1->BRR = BAUD_RATE;

  /**   USART enable    **/
  SET_BIT(USART1->CR1 , 3);                                                     /* TX enable */
  SET_BIT(USART1->CR1 , 2);                                                     /* RX enable */
  SET_BIT(USART1->CR1 , 13);                                                    /* USART1 enable */

  /* Clear status register */
  USART1->SR = 0x0000;
}

void MUSART_voidTransmit(u8 arr[])
{
  u8 i =0;
  /* check for items in array */
  while (arr[i] == '\0')
  {
    USART1->DR = arr[i];
    while (GET_BIT(USART1->SR , 6) == 0);                                        /* Wait till TC = 1 */
    i++;
  }
}

u8   MUSART_u8Receive(void)
{
  /* Wait till reception is completed and ready to read */
  while(GET_BIT(USART1->SR , 5) == 0);
  return (0xFF & (USART1->DR));
}