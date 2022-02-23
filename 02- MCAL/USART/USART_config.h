/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 18 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H


/**       Configuration options       **/

/* Data width */
/* Options:  8_BITS   or  9_BITS   */
#define     DATA_WIDTH        EIGHT_BITS

/* Stop bits */
/* Options:   1_BIT   , 0.5_BIT  ,  2_BITS  or  1.5_BITS  */
#define     STOP_BITS         ONE_BIT

/* Parity control */
/* Options:   ENABLED (EVEV or ODD)  or  DISABLED  */
#define     PARITY            ENABLED
#define     PARITY_TYPE       EVEN

/* Asynchronous clock */
/* Options:   ENABLED   or  DISABLED   */
#define     ASYNCH_CLOCK      DISABLED
#if ASYNCH_CLOCK == ENABLED
  #define    CLOCk_POL       RISING_EDGE
  #define    CLOCk_PHASE     READ_WRITE
#endif

/* LIN status */
/* Options:   ENABLED   or  DISABLED   */
#define   LIN_STATUS        DISABLED

/* Baud rate */
/* Options:   BAUD_9600 , BAUD_115200 */
#define   BAUD_RATE         BAUD_115200

#endif
