/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 31 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

/* Function definition part: */
/* Initialization function */
void HLEDMRX_voidInit(void)
{
  /* Set row & columns pins as output push pull*/
  GPIO_voidSetPinDir( LEDMRX_ROW0_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW1_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW2_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW3_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW4_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW5_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW6_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_ROW7_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);

  GPIO_voidSetPinDir( LEDMRX_COL0_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL1_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL2_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL3_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL4_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL5_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL6_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
  GPIO_voidSetPinDir( LEDMRX_COL7_PIN , OUTPUT_GP_PUSHPULL_PIN_2MHZ);
}

/* Display function */
void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
  while (1) {
    /* Disable all columns */
    DisableAllCols();
    /* Operation on first column */
    SetRowValues(Copy_u8Data[0]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL0_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on second column */
    SetRowValues(Copy_u8Data[1]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL1_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on third column */
    SetRowValues(Copy_u8Data[2]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL2_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on forth column */
    SetRowValues(Copy_u8Data[3]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL3_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on fifth column */
    SetRowValues(Copy_u8Data[4]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL4_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on sixth column */
    SetRowValues(Copy_u8Data[5]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL5_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on seventh column */
    SetRowValues(Copy_u8Data[6]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL6_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/

    /* Disable all columns */
    DisableAllCols();
    /* Operation on eighth column */
    SetRowValues(Copy_u8Data[7]);                                                 /* Set row-pins values */
    MGPIO_voidSetPinValue(LEDMRX_COL7_PIN , LOW);                                 /* Enable display on column */
    MSTk_voidSetBusyWait(2500);                                                   /* 3rd step: delay for 2.5 ms*/
  }
}

/* Disable all columns function */
static void DisableAllCols(void)
{
  MGPIO_voidSetPinValue(LEDMRX_COL0_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL1_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL2_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL3_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL4_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL5_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL6_PIN , HIGH);
  MGPIO_voidSetPinValue(LEDMRX_COL7_PIN , HIGH);
}

/* Set row-pins values function */
static void SetRowValues(u8 Copy_u8Value)
{
  u8 Local_u8Bit;
  /* Set value of 1st row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 0);
  MGPIO_u8GetPinValue(LEDMRX_ROW0_PIN , Copy_u8Value);

  /* Set value of 2nd row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 1);
  MGPIO_u8GetPinValue(LEDMRX_ROW1_PIN , Copy_u8Value);

  /* Set value of 3rd row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 2);
  MGPIO_u8GetPinValue(LEDMRX_ROW2_PIN , Copy_u8Value);

  /* Set value of 4th row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 3);
  MGPIO_u8GetPinValue(LEDMRX_ROW3_PIN , Copy_u8Value);

  /* Set value of 5th row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 4);
  MGPIO_u8GetPinValue(LEDMRX_ROW4_PIN , Copy_u8Value);

  /* Set value of 6th row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 5);
  MGPIO_u8GetPinValue(LEDMRX_ROW5_PIN , Copy_u8Value);
  /* Set value of 7th row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 6);
  MGPIO_u8GetPinValue(LEDMRX_ROW6_PIN , Copy_u8Value);

  /* Set value of 8th row bit */
  Local_u8Bit = GET_BIT(Copy_u8Value , 7);
  MGPIO_u8GetPinValue(LEDMRX_ROW7_PIN , Copy_u8Value);
}
