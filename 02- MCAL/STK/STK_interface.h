/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 26 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

#ifndef MSTK_INTERFACE_H
#define MSTK_INTERFACE_H

/* Clock src options: */
#define   AHB_CLOCK               0
#define   AHB_CLOCK_DIV_8         1


/* Functions prototypes: */
void MSTK_voidInit(void);
void MSTk_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSignal(u32 Copy_u32Ticks , void (*Copy_ptr) (viod));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr) (viod));
void MSTK_voidStopInterval(void);
u32  MSTK_u32FGetElapsedTime(void);
u32  MSTK_u32FGetRemainingTime(void);




#endif
