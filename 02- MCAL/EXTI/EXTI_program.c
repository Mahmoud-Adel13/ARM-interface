/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2019 *******************************************************/
/* Version : V02         *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/* Functions definition part: */
void MEXTI_voidInit()                                                           /* Initialization function */
{
  #if   EXTI_MODE == RISING
    SET_BIT(EXTI -> PTSR , EXTI_LINE);
  #elif EXTI_MODE == FALING
    SET_BIT(EXTI -> FTSR , EXTI_LINE);
  #elif EXTI_MODE == ON_CHANGE
    SET_BIT(EXTI -> PTSR , EXTI_LINE);
    SET_BIT(EXTI -> FTSR , EXTI_LINE);
  #else
    #error"Wrong triggering mode choise"
  #endif
  /*Disable interrupts on chosen line */
  CLR_BIT(EXTI-> IMR , EXTI_LINE);
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)                                       /* Enable interrupt line function */
{
  SET_BIT(EXTI-> IMR , Copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)                                      /* Disable interrupt line function */
{
  CLR_BIT(EXTI-> IMR , Copy_u8Line);
}

void MEXTI_voidSwEXTI(u8 Copy_u8Line , u8 Copy_u8Bit)                           /* SW interrupt enable function: set pending flag by SW*/
{
  /* line interrupt enable */
  SET_BIT(EXTI-> IMR , Copy_u8Line);
  /* Settting 1 to desired SW interrupt */
  SET_BIT(EXTI-> SWIER , Copy_u8Bit);
}

void MEXTI_voidSetTriggerMode(u8 Copy_u8Line , u8 Copy_u8Mode)                  /* Enable triggering modes on any line -  function*/
{
  switch (Copy_u8Mode) {
    case RISING   :   SET_BIT(EXTI -> PTSR , EXTI_LINE);                                      break;
    case FALLING  :   SET_BIT(EXTI -> FTSR , EXTI_LINE);                                      break;
    case ON_CHANGE:   SET_BIT(EXTI -> PTSR , EXTI_LINE);   SET_BIT(EXTI -> FTSR , EXTI_LINE); break;
    default       :   #error"Wrong triggering mode choise"                                    break;
  }
}

void MEXTI_viodSetCallBack(void (Copy_ptr*)(viod))                              /* CallBack function to set user's ISR function */
{
  EXTI0_CallBack = Copy_ptr;
}


/* ISR Handler*/
void EXTI0_IRQHandler(void)
{
  /* User ISR funcyion call */
  EXTI0_CallBack();
  /* clear pending flag*/
  SET_BIT(EXTI->PR , 0);
}
