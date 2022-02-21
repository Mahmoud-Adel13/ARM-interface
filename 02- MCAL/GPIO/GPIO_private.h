/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 14 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*Register definition: */
/*1. Port A */
#define     GPIOA_CRL       *((u32*)0x40010800)
#define     GPIOA_CRH       *((u32*)0x40010804)
#define     GPIOA_IDR       *((u32*)0x40010808)
#define     GPIOA_ODR       *((u32*)0x4001080C)
#define     GPIOA_BSRR      *((u32*)0x40010810)
#define     GPIOA_BRR       *((u32*)0x40010814)
#define     GPIOA_LCKR      *((u32*)0x40010818)
/*2. Port B */
#define     GPIOB_CRL       *((u32*)0x40010800)
#define     GPIOB_CRH       *((u32*)0x40010804)
#define     GPIOB_IDR       *((u32*)0x40010808)
#define     GPIOB_ODR       *((u32*)0x4001080C)
#define     GPIOB_BSRR      *((u32*)0x40010810)
#define     GPIOB_BRR       *((u32*)0x40010814)
#define     GPIOB_LCKR      *((u32*)0x40010818)
/*3. Port C */
#define     GPIOC_CRL       *((u32*)0x40010800)
#define     GPIOC_CRH       *((u32*)0x40010804)
#define     GPIOC_IDR       *((u32*)0x40010808)
#define     GPIOC_ODR       *((u32*)0x4001080C)
#define     GPIOC_BSRR      *((u32*)0x40010810)
#define     GPIOC_BRR       *((u32*)0x40010814)
#define     GPIOC_LCKR      *((u32*)0x40010818)




#endif
