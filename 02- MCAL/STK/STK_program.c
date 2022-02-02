/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 28 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include  "BIT_MATH.h"
#include  "STD_TYPES.h"

#include  "STK_interface.h"
#include  "STK_private.h"
#include  "STK_config.h"

/* Global variable */
u8 Global_u8PeriodicState;


/* Functions definition part: */
void MSTK_voidInit(void)
{
  /* Clock inatialization */
  #if   STK_CLOCK_SRC == AHB_CLOCK
    SET_BIT(STK->CTRL , 2);
  #elif STK_CLOCK_SRC == AHB_CLOCK_DIV_8
    CLR_BIT(STK->CTRL , 2);
  #else
    #error "Wrong clock sourse entry."
  #endif
  /* Disable SysTick interrupt: */
  CLR_BIT(STK->CTRL , 1);
  /* Disable SysTick: */
  CLR_BIT(STK->CTRL , 0);
}

void MSTk_voidSetBusyWait(u32 Copy_u32Ticks)
{
  /* Clear Value Register */
	STK-> VALUE  = 0 ;
  /* Set time of uP delay */
  STK-> LOAD = Copy_u32Ticks - 1;
  /* Disable SysTick interrupt: */
  CLR_BIT(STK->CTRL , 1);
  /* SysTick enable */
  SET_BIT(STK->CTRL , 0);
  while (Copy_u32Ticks > 0) {}                                                  /* uP hold dela time */
}

void MSTK_voidSetIntervalSignal(u32 Copy_u32Ticks , void (*Copy_ptr) (viod))
{
  /* Disable timer */
  CLR_BIT(STK->CTRL , 0);
  /* Clear Value Register */
	STK-> VALUE  = 0 ;
  /* Set interval duration */
  STK-> LOAD = Copy_u32Ticks - 1;
  /* SysTick enable / start */
  SET_BIT(STK->CTRL , 0);
  /* Save callback */
  MSTK_Callback = Copy_ptr;                                                     /* Callback function assignment */
  /* Enable SysTick interrupt: */
  SET_BIT(STK->CTRL , 1);
  /* Periodic flag state */
  Global_u8PeriodicState = 0;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr) (viod))
{
  /* Clear Value Register */
	STK-> VALUE  = 0 ;
  /* Set interval duration */
  STK-> LOAD = Copy_u32Ticks - 1;
  /* Enable SysTick interrupt: */
  SET_BIT(STK->CTRL , 1);
  /* SysTick enable */
  SET_BIT(STK->CTRL , 0);
  MSTK_Callback = Copy_ptr;                                                     /* Callback function assignment */
  Global_u8PeriodicState = 1;
}

void MSTK_voidStopInterval(void)
{
  /* Disable SysTick: */
  CLR_BIT(STK->CTRL , 0);
}

u32 MSTK_u32FGetElapsedTime(void)
{
  STK->VALUE &= ~(0xFF000000);                                                  /* Setting reserved bits as zeros */
  u32  Local_u32Elapsed = (STK->LOAD) - (STK->VALUE);
  return Local_u32Elapsed;
}

u32 MSTK_u32FGetRemainingTime(void)
{
  STK->VALUE &= ~(0xFF000000);                                                  /* Setting reserved bits as zeros */
  u32  Local_u32Elapsed = (STK->VALUE);
  return Local_u32Elapsed;
}


/* SysTick ISR Handler: */
void SysTick_Handler(void (*MSTK_Callback)(void))
{
  MSTK_Callback();
  if(Global_u8PeriodicState == 0)
  {
    STK-> LOAD  = 0x0000;
    STK-> VALUE = 0x0000;
  }
}
