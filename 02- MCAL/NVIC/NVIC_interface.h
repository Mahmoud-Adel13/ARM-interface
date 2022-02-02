/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 18 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/* Priority grouping control options: */
#define     PRIGROUP3             0b011                                         /* 4 bits of IPR for group priority and 0 bits for subgroup priority*/
#define     PRIGROUP4             0b100                                         /* 3 bits of IPR for group priority and 1 bits for subgroup priority*/
#define     PRIGROUP5             0b101                                         /* 2 bits of IPR for group priority and 2 bits for subgroup priority*/
#define     PRIGROUP6             0b110                                         /* 1 bits of IPR for group priority and 3 bits for subgroup priority*/
#define     PRIGROUP7             0b111                                         /* 0 bits of IPR for group priority and 4 bits for subgroup priority*/

/* Enable interrupt macros */
#define     EXTI0     6
#define     EXTI1     7
#define     EXTI2     8
#define     EXTI3     9
#define     EXTI4     10


/* Functions prototypes: */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8   MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetIntPriority(u8 Copy_u8IntNumber , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u8 Copy_u8PriGroup)


#endif
