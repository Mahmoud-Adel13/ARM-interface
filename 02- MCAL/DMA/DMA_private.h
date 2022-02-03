/*******************************************************************************/
/* Author : Mahmoud Adel   *****************************************************/
/* Date : 9 September 2020 *****************************************************/
/* Version : V01           *****************************************************/
/*******************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


/* Registers definitions */
typedef struct
{
  volatile u32   CCR;
  volatile u32   CNDTR;
  volatile u32   CPAR;
  volatile u32   CMAR;
  volatile u32   Reversed;
}DMA_channel;

typedef struct
{
  volatile u32   ISR;                                                           /* Interrupt status register (Read only) */
  volatile u32   IFCR;                                                          /* Interrupt flag clear register */
  DMA_channel    Channel[7];                                                    /* 7 Channels of DMA1 */
}DMA_t;
#define   DMA     ((volatile DMA_t*) 0x40020000)


/**   Options configuration   **/
/* ENABLED or DISABLED for CCR bits (MINC, PINC, MEM2MEM, CIRC, TEIE, HTIE, TCIE, EN) */
#define     DISABLED        0
#define     ENABLED         1

/* Channel SW priority */
#define     LOW_PRIORITY                0b00
#define     MEDIUM_PRIORITY             0b01
#define     HIGH_PRIORITY               0b10
#define     VERY_HIGH_PRIORITY          0b11

/* MSIZE & PSIZE options */
#define     8_BITS          0b00
#define     16_BITS         0b01
#define     32_BITS         0b10
#define     RESERVED        0b11

/* DIR options */
#define     PRE_SRC         0
#define     MEM_SRC         1

/* Interrupt options */
#define     CCR_TCIF        1
#define     CCR_HTIF        2
#define     CCR_TEIF        3



#endif
