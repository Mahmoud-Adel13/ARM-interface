/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/


#ifndef  AFIO_PRIVATE_H
#define  AFIO_PRIVATE_H

/* Registers definition: */
typedef struct{
  volatile u32   EVCR   ;
  volatile u32   MAPR   ;
  volatile u32   EXTICR1;                                                       /* Register to choose one EXTI bit of lines 0,1,2 or 3*/
  volatile u32   EXTICR2;                                                       /* Register to choose one EXTI bit of lines 4,5,6 or 7*/
  volatile u32   EXTICR3;                                                       /* Register to choose one EXTI bit of lines 8,9,10 or 11*/
  volatile u32   EXTICR4;                                                       /* Register to choose one EXTI bit of lines 12,13,14 or 15*/
  volatile u32   MAPR2  ;
}AFIO_t;

#define   AFIO        ((volatile AFIO_t*)0x40010000)


#endif
