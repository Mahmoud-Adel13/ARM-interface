/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H

/* Functions prototype: */
void MEXTI_voidInit();                                                          /* Initialization function */
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);                                      /* Enable interrupt line function */
void MEXTI_voidDisableEXTI(u8 Copy_u8Line) ;                                    /* Disable interrupt line function */
void MEXTI_voidSwEXTI(u8 Copy_u8Line);                                          /* SW interrupt enable function: set pending flag by SW*/
void MEXTI_voidTriggerMode(u8 Copy_u8Line , u8 Copy_u8Mode);                    /* Enable triggering modes on any line -  function*/



#endif
