/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 18 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


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
  USART1->CR1 |= (DATA_WIDTH << 12);
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
  SET_BIT(USART1->CR1 , 2);                                                     /* RX enable */
  SET_BIT(USART1->CR1 , 3);                                                     /* TX enable */

  SET_BIT(USART1->CR1 , 13);                                                    /* USART1 enable */

  /* Clear status register */
  USART1->SR = 0;
}

void MUSART_voidTransmit(u8 *arr)
{
  u8 i =0;
  /* check for items in array */
  while (arr[i] != '\0')
  {
    (USART1->DR) = arr[i];
    while (GET_BIT(USART1->SR , 6) == 0);                                        /* Wait till TC = 1 */
    i++;
  }
}

u8   MUSART_u8Receive(void)
{
  /* Local variable definitions */
  u16  Local_u16Timeout = 0;
  u8   Local_u8ReceivedData = 0;
  //CLR_BIT(USART1->SR , 5);

  /* Check if reception is completed or timeout happens */
  while((GET_BIT(USART1->SR , 5) == 0) && (Local_u16Timeout < 10000))
  {
    Local_u16Timeout++;
  }

  /* when no timeout happens and complete receiving, read and return data */
  if(Local_u16Timeout == 10000)                                                 /* This is built to prevent waiting for ever in this while loop */
  {
    Local_u8ReceivedData = 255;                                             /* when received 255 then its a timeout */
  }
  else
  {
		Local_u8ReceivedData = USART1->DR;
  }

  return ((Local_u8ReceivedData) & 0xFF);
}
