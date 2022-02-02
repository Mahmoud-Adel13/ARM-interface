/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2020 *******************************************************/
/* Version : V02         *******************************************************/
/*******************************************************************************/

#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H

/* External interrupts line options*/
#define     LINE0           0
#define     LINE1           1
#define     LINE2           2
#define     LINE3           3
#define     LINE4           4
#define     LINE5           5
#define     LINE6           6
#define     LINE7           7
#define     LINE8           8
#define     LINE9           9
#define     LINE10          10
#define     LINE11          11
#define     LINE12          12
#define     LINE13          13
#define     LINE14          14
#define     LINE15          15

/* Line triggering technique: */
/*                 opotions:  */
#define     RISING          0
#define     FALLING         1
#define     ON_CHANGE       2


/* Functions prototype: */
void MEXTI_voidInit();                                                          /* Initialization function */
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);                                      /* Enable interrupt line function */
void MEXTI_voidDisableEXTI(u8 Copy_u8Line) ;                                    /* Disable interrupt line function */
void MEXTI_voidSwEXTI(u8 Copy_u8Line , u8 Copy_u8Bit);                          /* SW interrupt enable function: set pending flag by SW*/
void MEXTI_voidSetTriggerMode(u8 Copy_u8Line , u8 Copy_u8Mode);                 /* Enable triggering modes on any line -  function*/
void MEXTI_viodSetCallBack(void (Copy_ptr*)(viod));                             /* CallBack function to set user's ISR function */



#endif
