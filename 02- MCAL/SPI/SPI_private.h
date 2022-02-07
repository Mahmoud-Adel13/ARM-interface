/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 16 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/**   registers definitions   **/
typedef struct
{
  volatile  u32   CR1;
  volatile  u32   CR2;
  volatile  u32   SR;
  volatile  u32   DR;
  volatile  u32   SRCPR;
  volatile  u32   RXCRCR;
  volatile  u32   TXCRCR;
  volatile  u32   I2SCFGR;
  volatile  u32   I2SPR;
}SPI_t;
#define   SPI1     ((volatile SPI_t*)0x40013000)



/**   configuration options   **/
/* Data frame format */
#define   DATA_FRAME             8_BITS
#define   DATA_FRAME             16_BITS

/* Data order: LSB or MSB first */
#define   MSB         0
#define   LSB         1

/* Master or slave */
#define   SLAVE       0
#define   MASTER      1

/* Baud rate prescaller */
#define   APB2_DIV_2             0b000
#define   APB2_DIV_4             0b001
#define   APB2_DIV_8             0b010
#define   APB2_DIV_16            0b011
#define   APB2_DIV_32            0b100
#define   APB2_DIV_64            0b101
#define   APB2_DIV_128           0b110
#define   APB2_DIV_256           0b111

/* Clock polarity */
#define   RISING_EDGE      0
#define   FALLING_EDGE     1

/* RX mode */
#define   SEND_RECV        0
#define   RECV_ONLY        1

/* Slave select managment */
#define   BY_HW            0
#define   BY_SW            1

/* Internal slave select */
#define   INT_SLAVE        0
#define   INT_MASTER       1

/* Clock phase */
#define   READ_WRITE       0
#define   WRITE_READ       1

/*  CallBack   variable */
void (*MSPI1_CallBack) (u8);

#endif
