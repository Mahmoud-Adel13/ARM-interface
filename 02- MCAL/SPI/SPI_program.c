/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 16 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/* Function definitions */
/* Initialization function */
void MSPI1_voidInit(void)
{
  /* Disable SPI  & clear register */
  SPI1->CR1 = 0x0000;
  /*  clock phase */
  SPI1->CR1 |= (CLOCK_PHASE << 0);
  /* clocl polarity */
  SPI1->CR1 |= (CLOCK_POL << 1);
  /* Master-slave selection */
  SPI1->CR1 |= (MASTER_SELECT << 2);
  /* Baud rate prescaller selection */
  SPI1->CR1 |= (BAUD_RATE_PRE << 3);
  /* Data order */
  SPI1->CR1 |= (DATA_ORDER << 7);
  /* Slave select mode */
  SPI1->CR1 |= (SLAVE_SELECT << 9);
  /* RX mode */
  SPI1->CR1 |= (RX_MODE << 10);
  /* Data frame format */
  SPI1->CR1 |= (DATA_FRAME << 11);

  /* slave_select_pin direction */
  MGPIO_voidSetPinDir(SLAVE_SELECT_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);

  /* Enable SPI */
  SET_BIT(SPI1-> CR1 , 6);
}

/* Send-Receive Synch function */
void MSOI1_voidSendReceiveSynch(u8 Copy_u8DataToSend , u8 *Copy_u8VariableToReceive)
{
  /* set slave select to LOW */
  MGPIO_voidGetPinValue(SLAVE_SELECT_PIN , LOW);
  /* Send data*/
  SPI1->DR = Copy_u8DataToSend;
  /* Wait for Busy flag */
  while(GET_BIT(SPI1->SR , 6) == 1);
  /* Return to the receive variable */
  Copy_u8VariableToReceive = SPI1->DR;
  /* set slave select to HIGH */
  MGPIO_voidGetPinValue(SLAVE_SELECT_PIN , HIGH);
}

/* Send-Receive Asynch function */
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToSend , void (*Copy_CallBack) (u8))
{
  /* MSPI_CallBack  assignment */
  MSPI_CallBack = Copy_CallBack;
  /* set slave select to LOW */
  MGPIO_voidGetPinValue(SLAVE_SELECT_PIN , LOW);
  /* Send data*/
  SPI1->DR = Copy_u8DataToSend;
}


/**     ISR Handler      **/
void MSPI1_IRQHandler(void)
{
  MSPI1_CallBack(SPI1->DR);
}
