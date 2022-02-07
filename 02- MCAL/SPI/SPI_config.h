/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 16 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/**   configuration options   **/
/* Slave select pin */
/* Options: Write in pair   PORT,PIN  */
#define     SLAVE_SELECT_PIN      GPIO_PORTA, GPIO_PIN_0

/* Data frame format */
/* Options:   8_BITS  or  16_BITS   */
#define   8_BITS            0
#define   16_BITS           1

/* Data order: LSB or MSB first */
/* Options:  MSB, LSB           */
#define   DATA_ORDER          MSB

/* Master or slave */
/* Options:  Master or slave  */
#define   MASTER_SELECT       Master

/* Baud rate prescaller */
/* Options:    APB2_DIV_2,  APB2_DIV_4, APB2_DIV_8, APB2_DIV_16,
               APB2_DIV_32, APB2_DIV_64,  APB2_DIV_128, or  APB2_DIV_256  */
#define   BAUD_RATE_PRE       APB2_DIV_2

/* Clock polarity */
/* Options:  RISING_EDGE  or  FALLING_EDGE  */
#define   CLOCK_POL           RISING_EDGE

/* RX mode */
/* Options:  SEND_RECV  or  SEND_ONLY */
#define   RX_MODE             SEND_RECV

/* Slave select mode */
/* Options:  BY_SW  or  BY_HW */
#define   SLAVE_MANAGE        BY_SW                                             /* To choose SSM bit value */
#if   SLAVE_MANAGE == BY_SW
  #define   INT_SLAVE_SELECT    INT_MASTER                                      /* Set SSI bit value */
#endif

/* Clock phase */
/* Options:  READ_WRITE   or  WRITE_READ  */
#define   CLOCK_PHASE         READ_WRITE



#endif
