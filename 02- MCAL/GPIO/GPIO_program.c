/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 14 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

/*Including part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


/*Code part: */
void MGPIO_voidSetPinDir(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)       /*Pin-Mode configuration function */
{
  if (Copy_u8Port == GPIO_PORTA)
  {
    if (Copy_u8Pin < 7)
    {
      GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
      GPIOA_CRL |= (Copy_u8Mode) << (Copy_u8Pin * 4);
    }
    else
    {
      GPIOA_CRH &= ~((0b1111) << ((Copy_u8Pin - 8) * 4));
      GPIOA_CRH |= (Copy_u8Mode) << ((Copy_u8Pin - 8) * 4);
    }
    /*Input pull or push configuration */
    if (Copy_u8Mode == INPUT_PUSHPULL_PIN)
    {
      if (INPUT_PUSHPULL == INPUT_PULL)
      {
        CLR_BIT(GPIOA_ODR , Copy_u8Pin);
      }
      else if (INPUT_PUSHPULL == INPUT_PUSH)
      {
        SET_BIT(GPIOA_ODR , Copy_u8Pin);
      }
    }
  }
  /*For Port B: */
  else if (Copy_u8Port == GPIO_PORTB)
  {
    if (Copy_u8Pin < 7)
    {
      GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
      GPIOB_CRL |= (Copy_u8Mode) << (Copy_u8Pin * 4);
    }
    else
    {
      GPIOB_CRH &= ~((0b1111) << ((Copy_u8Pin - 8) * 4));
      GPIOB_CRH |= (Copy_u8Mode) << ((Copy_u8Pin - 8) * 4);
    }
    /*Input pull or push configuration */
    if (Copy_u8Mode == INPUT_PUSHPULL_PIN)
    {
      if (INPUT_PUSHPULL == INPUT_PULL)
      {
        CLR_BIT(GPIOB_ODR , Copy_u8Pin);
      }
      else if (INPUT_PUSHPULL == INPUT_PUSH)
      {
        SET_BIT(GPIOB_ODR , Copy_u8Pin);
      }
    }
  }

  /*For Port C */
  else if (Copy_u8Port == GPIO_PORTC)
  {
    if (Copy_u8Pin < 7)
    {
      GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
      GPIOC_CRL |= (Copy_u8Mode) << (Copy_u8Pin * 4);
    }
    else
    {
      GPIOC_CRH &= ~((0b1111) << ((Copy_u8Pin - 8) * 4));
      GPIOC_CRH |= (Copy_u8Mode) << ((Copy_u8Pin - 8) * 4);
    }
    /*Input pull or push configuration */
    if (Copy_u8Mode == INPUT_PUSHPULL_PIN)
    {
      if (INPUT_PUSHPULL == INPUT_PULL)
      {
        CLR_BIT(GPIOC_ODR , Copy_u8Pin);
      }
      else if (INPUT_PUSHPULL == INPUT_PUSH)
      {
        SET_BIT(GPIOC_ODR , Copy_u8Pin);
      }
    }
  }
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)    /*Set pin-output value function */
{
  if (Copy_u8Port == GPIO_PORTA)
  {
    if (Copy_u8Value == HIGH)
    {
      //SET_BIT(GPIOA_ODR , Copy_u8Pin);
      GPIOA_BSRR = (0x01 << Copy_u8Pin);                                        /*Faster to set pin than using ODR */
    }
    else
    {
      //CLR_BIT(GPIOA_ODR , Copy_u8Pin);
      GPIOA_BRR = (0x01 << Copy_u8Pin);                                         /*Faster to clear pin than using ODR */
    }
  }
  else if (Copy_u8Port == GPIO_PORTB)
  {
    if (Copy_u8Value == HIGH)
    {
      //SET_BIT(GPIOB_ODR , Copy_u8Pin);
      GPIOB_BSRR = (0x01 << Copy_u8Pin);                                        /*Faster to set pin than using ODR */
    }
    else
    {
      //CLR_BIT(GPIOB_ODR , Copy_u8Pin);
      GPIOB_BRR = (0x01 << Copy_u8Pin);                                         /*Faster to clear pin than using ODR */
    }
  }
  else if (Copy_u8Port == GPIO_PORTC)
  {
    if (Copy_u8Value == HIGH)
    {
      //SET_BIT(GPIOC_ODR , Copy_u8Pin);
      GPIOC_BSRR = (0x01 << Copy_u8Pin);                                        /*Faster to set pin than using ODR */
    }
    else
    {
      //CLR_BIT(GPIOC_ODR , Copy_u8Pin);
      GPIOC_BRR = (0x01 << Copy_u8Pin);                                         /*Faster to clear pin than using ODR */
    }
  }
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)                          /*Get pin-input value function */
{
  u8 u8Value = 0;
  if (Copy_u8Port == GPIO_PORTA)
  {
    u8Value = GET_BIT(GPIOA_IDR , Copy_u8Pin);
  }
  else if (Copy_u8Port == GPIO_PORTB)
  {
    u8Value = GET_BIT(GPIOB_IDR , Copy_u8Pin);
  }
  else if (Copy_u8Port == GPIO_PORTC)
  {
    u8Value = GET_BIT(GPIOC_IDR , Copy_u8Pin);
  }
  return u8Value;
}

void MGPIO_voidSetPortDir(u8 Copy_u8Port , u8 Copy_u8Position , u32 Copy_u32Mode)  /*Port-Mode configuration function */
{
  if (Copy_u8Port == GPIO_PORTA)
  {
    if (Copy_u8Position == LOW)
    {
      GPIOA_CRL = Copy_u32Mode;
    }
    else if (Copy_u8Position == HIGH)
    {
      GPIOA_CRH = Copy_u32Mode;
    }
  }
  else if (Copy_u8Port == GPIO_PORTB)
  {
    if (Copy_u8Position == LOW)
    {
      GPIOB_CRL = Copy_u32Mode;
    }
    else if (Copy_u8Position == HIGH)
    {
      GPIOB_CRH = Copy_u32Mode;
    }
  }
  else if (Copy_u8Port == GPIO_PORTC)
  {
    if (Copy_u8Position == LOW)
    {
      GPIOC_CRL = Copy_u32Mode;
    }
    else if (Copy_u8Position == HIGH)
    {
      GPIOC_CRH = Copy_u32Mode;
    }
  }
}

void MGPIO_voidSetPortValue(u8 Copy_u8Port , u32 Copy_u32Value )                /*Set Port-output value function */
{
  /*For Port A */
  if (Copy_u8Port == GPIO_PORTA)
  {
    if (Copy_u32Value == HIGH)
    {
      GPIOA_BSRR = 0x1111;
    }
    else if (Copy_u32Value == LOW)
    {
      GPIOA_BRR = 0x1111;
    }
    else
    {
      GPIOA_ODR = Copy_u32Value;
    }
  }
  /*For Port B */
  else if (Copy_u8Port == GPIO_PORTB)
  {
    if (Copy_u32Value == HIGH)
    {
      GPIOB_BSRR = 0x1111;
    }
    else if (Copy_u32Value == LOW)
    {
      GPIOB_BRR = 0x1111;
    }
    else
    {
      GPIOB_ODR = Copy_u32Value;
    }
  }
  /*For Port C */
  else if (Copy_u8Port == GPIO_PORTC)
  {
    if (Copy_u32Value == HIGH)
    {
      GPIOC_BSRR = 0x1111;
    }
    else if (Copy_u32Value == LOW)
    {
      GPIOC_BRR = 0x1111;
    }
    else
    {
      GPIOC_ODR = Copy_u32Value;
    }
  }
}

u32 MGPIO_u32GetPortValue(u8 Copy_u8Port)                                       /*Get Port-input value function */
{
  u32 u32PortValue;
  /*For Port A */
  if (Copy_u8Port == GPIO_PORTA)
  {
    u32PortValue = GPIOA_IDR;
  }
  /*For Port B */
  else if (Copy_u8Port == GPIO_PORTB)
  {
    u32PortValue = GPIOB_IDR;
  }
  /*For Port C */
  else if (Copy_u8Port == GPIO_PORTC)
  {
    u32PortValue = GPIOC_IDR;
  }
  return u32PortValue;
}
