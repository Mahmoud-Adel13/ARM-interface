/*******************************************************************************/
/* Author : Mahmoud Adel   *****************************************************/
/* Date : 5 Septemper 2020 *****************************************************/
/* Version : V01           *****************************************************/
/*******************************************************************************/

/* Inclution part */
/* LIB layer*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* MCAL layer */
#include "STK_interface.h"
/* Sercices layer */
#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"


/* Functions definitions */
void SOS_viodCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , viod (*ptr)(viod) , u8 Copy_u8FirstDelay , state Copy_State)
{
  OS_Tasks[Copy_u8Priority].firstDelay = Copy_u8FirstDelay;
  OS_Tasks[Copy_u8Priority].state = Copy_u8State;
  OS_Tasks[Copy_u8Priority].priodicity = Copy_u16Periodicity;
  OS_Tasks[Copy_u8Priority].Fptr = ptr;
}

viod SOS_viodOSStart(viod)
{
  /* Initialization */
  /* Tick time initialization */
  MSTK_voidInit();                                                              /* SysTich initialization: AHB_CRY / 8 = 1MHZ */
  MSTK_voidSetIntervalPeriodic(1000000 , Scheduler);                            /* 1 ms Tick time then interrupt */
}

void SOS_voidKillTask(u8 Copy_u8Priority)
{
  OS_Tasks[Copy_u8Priority] = NULL;
}

void SOS_voidPauseTask(u8 Copy_u8Priority)
{
  OS_Tasks[Copy_u8Priority].state = Task_Suspended;
}

void SOS_voidResumeTask(u8 Copy_u8Priority)
{
  OS_Tasks[Copy_u8Priority].state = Task_Ready;
}
