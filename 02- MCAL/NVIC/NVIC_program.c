/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 18 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

/*Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/* Functions definition part: */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)                             /* External interrupts enable function */
{
  if (Copy_u8IntNumber <= 31)
  {
    NVIC_ISER0 = (1 << Copy_u8IntNumber);
  }
  else if (Copy_u8IntNumber <= 59)
  {
	  Copy_u8IntNumber -= 32;
	  NVIC_ISER1 = (1 << Copy_u8IntNumber);
  }
  else
  {
	  /* return Error*/
  }
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)                            /* External interrupts disable function */
{
  if (Copy_u8IntNumber <= 31)
  {
    NVIC_ICER0 = (1 << Copy_u8IntNumber);
  }
  else if (Copy_u8IntNumber <= 59)
  {
    Copy_u8IntNumber -= 32;
    NVIC_ICER1 = (1 << Copy_u8IntNumber);
  }
  else
  {
    /* return Error*/
  }
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)                              /* External interrupts setting pending falg function */
{
  if (Copy_u8IntNumber <= 31)
  {
    NVIC_ISPR0 = (1 << Copy_u8IntNumber);
  }
  else if (Copy_u8IntNumber <= 59)
  {
    Copy_u8IntNumber -= 32;
    NVIC_ISPR1 = (1 << Copy_u8IntNumber);
  }
  else
  {
    /* return Error*/
  }
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)                            /* External interrupts clearing pending falg function */
{
  if (Copy_u8IntNumber <= 31)
  {
    NVIC_ICPR0 = (1 << Copy_u8IntNumber);
  }
  else if (Copy_u8IntNumber <= 59)
  {
    Copy_u8IntNumber -= 32;
    NVIC_ICPR1 = (1 << Copy_u8IntNumber);
  }
  else
  {
    /* return Error*/
  }
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)                                   /* External interrupts get active falg function */
{
  u8 Local_u8Result;
  if (Copy_u8IntNumber <= 31)
  {
    Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
  }
  else if (Copy_u8IntNumber <= 59)
  {
    Copy_u8IntNumber -= 32;
    Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
  }
  else
  {
    /* return Error*/
  }
  return Local_u8Result;
}

void MNVIC_voidSetIntPriority(u8 Copy_u8IntNumber , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u8 Copy_u8PriGroup)      /* Interrupt priorityt control function */
{
  u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority <<( Copy_u8PriGroup - 3));
  /*Internal/ core prepheral interrupt */

  /*External prepheral interrupt */
  if(Copy_u8IntNumber >= 0)
  {
    NVIC_IPR[Copy_u8IntNumber] = Local_u8Priority << 4;
  }
  SCB_AIRCR = 0x05FA0000 | (Local_u8Priority << 8);                             /* Foul as layered archeticture */
}
