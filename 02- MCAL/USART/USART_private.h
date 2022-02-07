/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 18 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* Register definitions */
typedef struct
{
  volatile  u32   SR;
  volatile  u32   DR;
  volatile  u32   BRR;
  volatile  u32   CR1;
  volatile  u32   CR2;
  volatile  u32   CR3;
  volatile  u32   GTPR;
}USART_t;

#define   USART1       ((volatile USART_t*)0x40013800)

/**       Configuration options       **/
/* Data width */
#define   EIGHT_BITS         0
#define   NINE_BITS          1

/* Parity control , Asynchronous clock & LIN */
#define   DISABLED        0
#define   ENABLED         1

/* Parity type */
#define   EVEN            0
#define   ODD             1

/* Stop bits */
#define   ONE_BIT           0b00
#define   HALF_BIT         0b01
#define   TWO_BITS          0b10
#define   ONE_HALF_BITS        0b11

/* Asynchronous clock parity */
#define   RISING_EDGE      0
#define   FALLING_EDGE     1

/* Asynchronous clock phase */
#define   READ_WRITE       0
#define   WRITE_READ       1

/* Baud rate */
#define   BAUD_9600         0x341
#define   BAUD_115200       0x046

#endif
