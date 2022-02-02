/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2020 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

#ifndef  AFIO_INTERFACE_H
#define  AFIO_INTERFACE_H

/* EXTI Bit line choice options: */
#define   PA      0b0000
#define   PB      0b0001
#define   PC      0b0010

/* Functions prototypes: */
void MAFIO_voidConfigurateEXTILineBit(u8 Copy_u8Line , u8 Copy_u8Bit);


#endif
