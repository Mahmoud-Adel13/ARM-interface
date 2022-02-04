/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2020 *******************************************************/
/* Version : V02         *******************************************************/
/*******************************************************************************/

#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

/* Global variables*/
#define 	NULL 		(*void)0
static void (*EXTI0_CallBack)(void) = NULL;

/* Register definition using struct and pointer: */
typedef struct{
  volatile u32 IMR;
  volatile u32 EMR;
  volatile u32 RTSR;
  volatile u32 FTSR;
  volatile u32 SWIER;
  volatile u32 PR;
}EXTI_t;

#define   EXTI      ((volatile EXIT_t*)0x40010400)                              /* pointer to struct */

#endif
