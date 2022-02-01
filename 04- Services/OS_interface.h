/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 5 Septemper 2020 *****************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/


#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

/* Task state union */
typedef union
{
  u8 Task_Ready;
  u8 Task_Suspended;
}state;


/* Functions prototype: */
void SOS_viodCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , viod (*ptr)(viod) , u8 Copy_u8FirstDelay , state Copy_state);
viod SOS_viodOSStart(viod);
void SOS_voidKillTask(u8 Copy_u8Priority);
void SOS_voidPauseTask(u8 Copy_u8Priority);
void SOS_voidResumeTask(u8 Copy_u8Priority);


#endif
