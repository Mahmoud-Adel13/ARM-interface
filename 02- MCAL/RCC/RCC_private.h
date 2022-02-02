/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 12 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

#ifndef RCC_private_H
#define RCC_private_H


/* Register Definition */
#define     RCC_CR              *((u32*)0x40021000)
#define     RCC_CFGR            *((u32*)0x40021004)
#define     RCC_CIR             *((u32*)0x40021008)
#define     RCC_APB2RSTR        *((u32*)0x4002100C)
#define     RCC_APB1RSTR        *((u32*)0x40021010)
#define     RCC_AHBENR          *((u32*)0x40021014)
#define     RCC_APB2ENR         *((u32*)0x40021018)
#define     RCC_APB1ENR         *((u32*)0x4002101C)
#define     RCC_BDCR            *((u32*)0x40021020)
#define     RCC_CSR             *((u32*)0x40021024)

/*RCC_CSS options:    ON or OFF*/
#define     RCC_CSS_OFF         0
#define     RCC_CSS_ON          1

/*RCC_HSI_Trim configuration: */
/*RCC_HSI_Trim options: */
#define    ZERO               0
#define    ONE                1
#define    TWO                2
#define    THREE              3
#define    FOUR               4
#define    FIVE               5
#define    SIX                6
#define    SEVEN              7
#define    EIGHT              8
#define    NINE               9
#define    TEN                10
#define    ELEVEN             11
#define    TWELVE             12
#define    THERTEEN           13
#define    FOURTEEN           14
#define    FIFTEEN            15
#define    SIXTEEN            16

/*RCC_HSI_TRIM configuration: */
/*#if RCC_HSI_TRIM == 0
  RCC_CR = (((((RCC_CR) >> 3) + RCC_HSI_TRIM_STEP) << 3) + (0x01));
#else
  RCC_CR = (((((RCC_CR) >> 3) - RCC_HSI_TRIM_STEP) << 3) + (0x01));
#endif*/

/*RCC_PLL_INPUT options: */
#define    RCC_PLL_IN_HSI_DIV_2     0
#define    RCC_PLL_IN_HSE_DIV_2     1
#define    RCC_PLL_IN_HSE           2

/*RCC_PLL_MUL_VAL options: */
#define   MUL_X_2               0
#define   MUL_X_3               1
#define   MUL_X_4               2
#define   MUL_X_5               3
#define   MUL_X_6               4
#define   MUL_X_7               5
#define   MUL_X_8               6
#define   MUL_X_9               7
#define   MUL_X_10              8
#define   MUL_X_11              9
#define   MUL_X_12              10
#define   MUL_X_13              11
#define   MUL_X_14              12
#define   MUL_X_15              13
#define   MUL_X_16              14
#define   MUL_X_16              15


#endif
