/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 2 Sebtenber 2019 *****************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

/* Global variable */
volatile u8  u8StartFlag       = 0;
volatile u32 u32FrameData[50]  = {0};
volatile u8  u8EdgeCounter     = 0;
u8 u8Data = 0;

/* Main code: */
void main(void)
{
  /* RCC Initialization */
  MRCC_voidInitSysClock();                                                      /* HSE crystal = 8 MHZ*/
  MRCC_voidEnableClock(APB2 , GPIO_PORTA);                                      /* Enable GPIOA clock */
  MRCC_voidEnableClock(APB2 , GPIO_PORTB);                                      /* Enable GPIOB clock */
  MRCC_voidEnableClock(APB2 , AFIO);                                            /* Enable AFIO  clock */

  /*  Pin directions */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_0 , INPUT_FLOATING_PIN);            /* A0 as input floating used with sensor */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_1 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);   /* A1 as output 2MHZ "Red" */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_2 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);   /* A2 as output 2MHZ "Green" */
  MGPIO_voidSetPinDir(GPIO_PORTA , GPIO_PIN_3 , OUTPUT_GP_PUSHPULL_PIN_2MHZ);   /* A3 as output 2MHZ "Blue" */

  /* EXTI Initialization */
  MEXTI_viodSetCallBack(voidGetIRFrame);                                        /* Set ISR function as CallBack */
  MEXTI_voidInit();                                                             /* A0 triggering mode as falling edge */
  MEXTI_voidEnableEXTI(LINE0);                                                  /* Enable interrupt on line 0 = A0 */
  MAFIO_voidConfigurateEXTILineBit(LINE0 , PA);                                 /* Enable A0 as EXTI0 on line 0 */

  /* Enable EXTI0 from NVIC*/
  MNVIC_voidEnableInterrupt(EXTI0);

  /* STK initialization */
  MSTK_voidInit();                                                              /* Set SysTich as AHB/8 = 1MHZ */

  while(1)
  {

  }
}


/* ISR function */
void voidGetIRFrame(void)
{
  if (u8StartFlag == 0)
  {
    /* start timer counting */
    MSTK_voidSetIntervalSignal(1000000 , voidTakeAction);
    u8StartFlag = 1;
  }
  else
  {
    /* Frame bit-time storage */
    u32FrameData[u8EdgeCounter] =MSTK_u32FGetElapsedTime();
    /* Restart timer */
    MSTK_voidSetIntervalSignal(1000000 , voidTakeAction);
    /* Edge counter incrementing */
    u8EdgeCounter++;
  }
}


/* Private functions */
void voidTakeAction(void)
{
  u8 u8Data = 0;

  if ((u32FrameData[0] >=10000 )&& (u32FrameData[0] <= 14000))                  /* check start bit */
  {
    for(u8 i=0 ; i<8 ; i++)                                                     /* 8 Data bits check and storage */
    {
      if ((u32FrameData[17+i] >=2000 )&& (u32FrameData[17+i] <= 2300))
      {
        /* its a 1 */
        SET_BIT(u8Data , i);
      }
      else
      {
        /* its a 0 */
        CLR_BIT(u8Data , i);
      }
    }
    voidPress();
  }
  else
  {
    /* Invalid frame */
  }

  /* To be ready for another button press */
  volatile u8  u8StartFlag       = 0;
  volatile u32 u32FrameData[0]   = 0;
  volatile u8  u8EdgeCounter     = 0;
}

void voidPress(void)
{
  switch (u8Data) {
    case 70:  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_0 , HIGH);    break;  /* Red light on */
    case 71:  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_0 , HIGH);    break;  /* Green light on */
    case 72:  MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN_0 , HIGH);    break;  /* Blue light on */
    default:  /* Nothing */                                             break;
  }
}
