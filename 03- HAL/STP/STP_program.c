/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 14 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

/* Function definition part */
void HSTP_voidSendSynchronous(u8 Copy_u8DataToSend)                             /* Send bit by bit starting with MSB */
{
  s8 Local_u8Counter;
  u8 Local_u8Bit;
  for(Local_u8Counter = 7 ; Local_u8Counter >= 0 ; Local_u8Counter--)
  {
    Local_u8Bit = GET_BIT(Copy_u8DataToSend , Local_u8Counter);
    MGPIO_voidSetPinValue(STP_SERIAL_DATA , Local_u8Bit);

    /* Send pulse to shift clock pin */
    MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , 1);
    MSTk_voidSetBusyWait(1);
    MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , 0);
    MSTk_voidSetBusyWait(1);
  }
  /* Send pulse to Storage clock pin */
  MGPIO_voidSetPinValue(STP_STORAGE_CLOCK , 1);
  MSTk_voidSetBusyWait(1);
  MGPIO_voidSetPinValue(STP_STORAGE_CLOCK , 0);
  MSTk_voidSetBusyWait(1);
}
