/*******************************************************************************/
/*Author: Mahmoud Adel Hassan **************************************************/
/*Date: 28 Auguest 2019 ********************************************************/
/*Version: V01 *****************************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include  "BIT_MATH.h"
#include  "STD_TYPES.h"

#include  "MSTK_interface.h"
#include  "MSTK_private.h"
#include  "MSTK_config.h"

/* Functions definition part: */
void MSTK_voidInit(void)
{
  /* Clock inatialization */
  #if   STK_CLOCK_SRC == AHB_CLOCK
    SET_BIT(CTRL , 2);
  #elif STK_CLOCK_SRC == AHB_CLOCK_DIV_8
    CLR_BIT(CTRL , 2);
  #else
    #error "Wrong clock sourse entry."
  #endif
  /* Disable SysTick interrupt: */
  CLR_BIT(CTRL , 1);
  /* Disable SysTick: */
  CLR_BIT(CTRL , 0);
}

void MSTk_voidSetBusyWait(u32 Copy_u32Ticks)
{
  /* Clear Value Register */
	STK-> VAL  = 0 ;
  /* Set time of uP delay */
  STK-> LOAD = Copy_u32Ticks;
  /* Disable SysTick interrupt: */
  CLR_BIT(CTRL , 1);
  /* SysTick enable */
  SET_BIT(CTRL , 0);
  while (Copy_u32Ticks > 0) {}                                                  /* uP hold dela time */
}

void MSTK_voidSetIntervalSignal(u32 Copy_u32Ticks , void (*Copy_ptr) (viod))
{
  /* Clear Value Register */
	STK-> VAL  = 0 ;
  /* Set interval duration */
  STK-> LOAD = Copy_u32Ticks;
  /* Enable SysTick interrupt: */
  SET_BIT(CTRL , 1);
  /* SysTick enable */
  SET_BIT(CTRL , 0);
  MSTK_Callback = Copy_ptr;                                                     /* Callback function assignment */
  if(STK->VALUE == 0x0)                                                         /* After interval ends stop counting */
  {
    STK-> LOAD  = 0x0000;
    STK-> VALUE = 0x0000;
  }
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr) (viod))
{
  /* Clear Value Register */
	STK-> VAL  = 0 ;
  /* Set interval duration */
  STK-> LOAD = Copy_u32Ticks;
  /* Enable SysTick interrupt: */
  SET_BIT(CTRL , 1);
  /* SysTick enable */
  SET_BIT(CTRL , 0);
  MSTK_Callback = Copy_ptr;                                                     /* Callback function assignment */
}

void MSTK_voidStopInterval(void)
{
  /* Disable SysTick: */
  CLR_BIT(CTRL , 0);
}

u32 MSTK_u32FGetElapsedTime(void)
{
  u32  Local_u32Elapsed = (STK->LOAD) - (STK->VALUE);
  return Local_u32Elapsed;
}

u32 MSTK_u32FGetRemainingTime(void)
{
  u32  Local_u32Elapsed = (STK->VALUE);
  return Local_u32Elapsed;
}


/* SysTick ISR Handler: */
void SysTick_Handler(viod (*MSTK_Callback)(void))
{
  *MSTK_Callback();
}
