/*******************************************************************************/
/* Author : Mahmoud Adel   *****************************************************/
/* Date : 5 Septemper 2020 *****************************************************/
/* Version : V01           *****************************************************/
/*******************************************************************************/

/* Inclusion part */
/* LIB layer*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* MCAL layer */
#include "STK_interface.h"
/* Services layer */
#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"


/* Functions definitions */
void SOS_viodCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*ptr)(void) , u8 Copy_u8FirstDelay , state Copy_u8State)
{
  OS_Tasks[Copy_u8Priority].firstDelay = Copy_u8FirstDelay;
  OS_Tasks[Copy_u8Priority].state = Copy_u8State;
  OS_Tasks[Copy_u8Priority].priodicity = Copy_u16Periodicity;
  OS_Tasks[Copy_u8Priority].Fptr = ptr;
}

void SOS_viodOSStart(void)
{
  /* Initialization */
  /* Tick time initialization */
  MSTK_voidInit();                                                              /* SysTich initialization: AHB_CRY / 8 = 1MHZ */
  MSTK_voidSetIntervalPeriodic(1000000 , Scheduler);                            /* 1 ms Tick time then interrupt */
}

//void SOS_voidKillTask(u8 Copy_u8Priority)
//{
//  OS_Tasks[Copy_u8Priority] = NULL;
//}

void SOS_voidPauseTask(u8 Copy_u8Priority)
{
  OS_Tasks[Copy_u8Priority].state = Task_Suspended;
}

void SOS_voidResumeTask(u8 Copy_u8Priority)
{
  OS_Tasks[Copy_u8Priority].state = Task_Ready;
}

/* Static functions */
volatile u16 TickCounts = 0;
static void Scheduler(void)
{
  for(u8 i= 0 ; i<NUM_OF_TASKS ; i++)
  {
    /* To check if its time to call a specific task at certain tick count & first delay check & Task is ready */
    if( ((TickCounts % OS_Tasks[i].state) == Task_Ready ) && ((TickCounts % OS_Tasks[i].priodicity) == 0) && (OS_Tasks[i].firstDelay == TickCounts) )
    {
      /* Call task's function */
      OS_Tasks[i].Fptr();
    }
  }
  TickCounts++;
}
