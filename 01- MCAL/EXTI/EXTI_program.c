/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MEXTI_interface.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"


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

void MEXTI_voidSwEXTI(u8 Copy_u8Line)                                           /* SW interrupt enable function: set pending flag by SW*/
{
  SET_BIT(EXTI-> SWIER)
}

void MEXTI_voidTriggerMode(u8 Copy_u8Line , u8 Copy_u8Mode)                     /* Enable triggering modes on any line -  function*/
{
  switch (Copy_u8Mode) {
    case RISING   :   SET_BIT(EXTI -> PTSR , EXTI_LINE);                                      break;
    case FALLING  :   SET_BIT(EXTI -> FTSR , EXTI_LINE);                                      break;
    case ON_CHANGE:   SET_BIT(EXTI -> PTSR , EXTI_LINE);   SET_BIT(EXTI -> FTSR , EXTI_LINE); break;
    default       :   #error"Wrong triggering mode choise"                                    break;
  }
}
