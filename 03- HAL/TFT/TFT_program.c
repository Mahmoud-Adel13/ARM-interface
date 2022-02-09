/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 21 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

/* Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


/* Function definitions */
void HTFT_voidInit(void)
{
  /* Reset pulse creation */
  MGPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
  MSTk_voidSetBusyWait(110);
  MGPIO_voidSetPinValue(TFT_RST_PIN, LOW);
  MSTk_voidSetBusyWait(1);
  MGPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
  MSTk_voidSetBusyWait(110);
  MGPIO_voidSetPinValue(TFT_RST_PIN, LOW);
  MSTk_voidSetBusyWait(110);
  MGPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
  MSTk_voidSetBusyWait(130000);

  /* Sleep out command */
  voidWriteCommand(0x11);
  /* Wait 150 ms */
  MSTk_voidSetBusyWait(150000);
  /* Color mode */
  voidWriteCommand(0x3A);
  voidWriteData(0x05);                                                          /* LED565 color mode */
  /* Display ON */
  voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(const u16 *Copy_u16Image)
{
  u16 counter;
  /* Set X Address*/
  voidWriteCommand(0x2A);
  /* Start point */
  voidWriteData(0);
  voidWriteData(0);
  /* End point */
  voidWriteData(0);
  voidWriteData(127);

  /* Set Y Address */
  voidWriteCommand(0x2B);
  /* Start point */
  voidWriteData(0);
  voidWriteData(0);
  /* End point */
  voidWriteData(0);
  voidWriteData(159);

  /* RAM write */
  voidWriteCommand(0x2C);


  for(counter = 0 ; counter <= 20480 ; counter++)
  {
    /* Write high byte */
    voidWriteData(Copy_u16Image[counter] >> 8);
    /* Write low byte */
    voidWriteData(Copy_u16Image[counter] & 0xff);
  }
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
  u16 counter;
  /* Set X Address*/
  voidWriteCommand(0x2A);
  /* Start point */
  voidWriteData(0);
  voidWriteData(0);
  /* End point */
  voidWriteData(0);
  voidWriteData(127);

  /* Set Y Address */
  voidWriteCommand(0x2B);
  /* Start point */
  voidWriteData(0);
  voidWriteData(0);
  /* End point */
  voidWriteData(0);
  voidWriteData(159);

  /* RAM write */
  voidWriteCommand(0x2C);


  for(counter = 0 ; counter <= 20480 ; counter++)
  {
    /* Write high byte */
    voidWriteData(Copy_u16Color >> 8);
    /* Write low byte */
    voidWriteData(Copy_u16Color & 0xff);
  }
}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2 , u16 Copy_u16Color)
{
  u16 counter;

  u16 size = (x2 - x1) * (y2 -y1);

  /* Set X Address*/
  voidWriteCommand(0x2A);
  /* Start point */
  voidWriteData(0);
  voidWriteData(x1);
  /* End point */
  voidWriteData(0);
  voidWriteData(x2);

  /* Set Y Address */
  voidWriteCommand(0x2B);
  /* Start point */
  voidWriteData(0);
  voidWriteData(y1);
  /* End point */
  voidWriteData(0);
  voidWriteData(y2);

  /* RAM write */
  voidWriteCommand(0x2C);


  for(counter = 0 ; counter <= size ; counter++)
  {
    /* Write high byte */
    voidWriteData(Copy_u16Color >> 8);
    /* Write low byte */
    voidWriteData(Copy_u16Color & 0xff);
  }
}

static void voidWriteCommand(u8 Copy_u8Command)
{
  u8 Local_u8Temp;
  /* Set A0 pin as LOW */
  MGPIO_voidSetPinValue(TFT_A0_PIN, LOW);
  /* Send command over SPI */
  MSPI1_voidSendReceiveSynch(Copy_u8Command , &Local_u8Temp);

}

static void voidWriteData(u8 Copy_u8Data)
{
  u8 Local_u8Temp;
  /* Set A0 pin as HIGH */
  MGPIO_voidSetPinValue(TFT_A0_PIN , HIGH);
  /* Send command over SPI */
  MSPI1_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp);
}
