/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 28 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"


/* Function definitions */
void HESP_voidInit(void)
{
  u8 Local_u8Result = 0;                                                        /* validation variable */

  while(Local_u8Result == 0)
  {
    /* Stop echo */
    MUSART_voidTransmit("ATE0\r\n");
    Local_u8Result = u8ESPValidateCmd();                                        /* check for OK replay received */
  }

  Local_u8Result = 0;                                                           /* Reclear validation variable to reuse it */
  while(Local_u8Result == 0)
  {
    /* Set connection mode as station mode */
    MUSART_voidTransmit("AT+CIPMODE = 1\r\n");
    Local_u8Result = u8ESPValidateCmd();                                        /* check for OK replay received */
  }

}



/* Private functions  */
static u8 u8ESPValidateCmd(void)
{
  /* Local variable definitions */
  u8 Local_u8Response[100] = {0};                                               /* Array to hold relays from esp (char by char) */
  u8 i =0;
  u8 Local_u8Dummy;
  u8 Local_u8Result;

  /* Check for timeout or data */
  while(Local_u8Dummy != 255)
  {
    Local_u8Dummy = MUSART_u8Receive();                                         /* Receiving ESP replay char by char */
    Local_u8Response[i] = Local_u8Dummy;
    i++;
  }

  /* Check if OK received*/
  if(Local_u8Response[0] =='0' && Local_u8Response[1] == 'k')
  {
    Local_u8Result = 1;
  }

  return Local_u8Result;
}
