/*******************************************************************************/
/* Author: Mahmoud Adel ********************************************************/
/* Date: 12 August 2020 ********************************************************/
/* Version: V01         ********************************************************/
/*******************************************************************************/

#ifndef RCC_interface_H
#define RCC_interface_H

/*Buses Macros: */
#define   AHB    0
#define   APB1   1
#define   APB2   2

/*SysClk-options Macros: */
#define   RCC_HSI       0
#define   RCC_HSE_CRY   1
#define   RCC_HSE_CR    2
#define   RCC_PLL       3

/*RCC_HSI_TRIM options: */
#define   PLUS_TRIM     0
#define   MINCE_TRIM    1

/* RCC Enable prepherals */
#define   AFIO          0
#define   GPIO_PORTA    2
#define   GPIO_PORTB    3
#define   GPIO_PORTC    4



/* Functions prototypes: */
void MRCC_voidInitSysClock(void);                                                /*Sytem-clock-choise in action/ pre-build configuration version*/
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);                     /*peripheral's-Clock-Activation function*/
void MRCC_voidDisableBusClock(u8 Copy_u8BusId , u8 Copy_u8PerId);                /*Peripheral's-Clock-Activation function*/
void MRCC_voidCssEnable(void);                                                   /*Clock-security-system Activation function*/



#endif
