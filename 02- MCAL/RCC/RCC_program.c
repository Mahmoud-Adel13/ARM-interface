/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 12 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

/*Inclusion part */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


/*Function definition part */

void MRCC_voidInitSysClock(void)                                                 /*Sytem-clock-choise in action/ pre-build configuration version*/
{
  #if     CLOCK_TYPE == RCC_HSI
    RCC_CR    = 0x00000081;
    RCC_CFGR  = 0x00000000;
  #elif   CLOCK_TYPE == RCC_HSE_CR
    RCC_CR    = 0x00050000;
    RCC_CFGR  = 0x00000001;
  #elif   CLOCK_TYPE == RCC_HSE_CRY
    RCC_CR    = 0x00010000;
    RCC_CFGR  = 0x00000001;
  #elif   CLOCK_TYPE == RCC_PLL
    CLR_BIT(RCC_CR , 24);                                                       /*Disable RCC_PLL clock*/
    //RCC_CFGR = 0;
    #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2                                 /*#IF block to configurate PLL source */
      SET_BIT   (RCC_CR , 1);                                                   /*Enable RCC_HSI clock*/
      CLR_BIT(RCC_CFGR , 16);
      CLR_BIT(RCC_CFGR , 17);
    #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
      SET_BIT  (RCC_CR , 16);                                                   /*Enable RCC_HSE clock*/
      SET_BIT(RCC_CFGR , 16);
      SET_BIT(RCC_CFGR , 17);
    #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
      SET_BIT  (RCC_CR , 16);                                                   /*Enable RCC_HSE clock*/
      SET_BIT(RCC_CFGR , 16);
      CLR_BIT(RCC_CFGR , 17);
    #else
      #error ("You chose the wrong PLL input clock. ")
    #endif
    RCC_CFGR &= ~(0b1111 << 18);                                                /*configuating CFGR[18:21] bits*/
    RCC_CFGR |= (RCC_PLL_INPUT << 18);
    RCC_CR =   0x01000000;                                                      /*enable RCC_PLL clock*/
    SET_BIT(RCC_CFGR , 0);                                                      /*RCC_PLL chosen system clock*/
    SET_BIT(RCC_CFGR , 1);
  #else
    #error ("You chose the wrong clock type. ")
  #endif
}

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)                      /*peripheral's-Clock-Activation function*/
{
  if(Copy_u8PerId <= 31)                                                        /*input validation*/
  {
    switch (Copy_u8BusId)                                                       /*BUS switching*/
    {
      case AHB  : SET_BIT(RCC_AHBENR  , Copy_u8PerId);  break;                /*Enabling peripheral in AHB */
      case APB1 : SET_BIT(RCC_APB1ENR , Copy_u8PerId);  break;                /*Enabling peripheral in APB1*/
      case APB2 : SET_BIT(RCC_APB2ENR , Copy_u8PerId);  break;                /*Enabling peripheral in APB2*/
      //default   : /*Return Error*/                    break;
    }
  }
  else
  {
    /*Return Error*/
  }
}

void MRCC_voidDisableBusClock(u8 Copy_u8BusId , u8 Copy_u8PerId)                 /*Peripheral's-Clock-Activation function*/
{
  if(Copy_u8PerId <= 31)                                                        /*Input validation*/
  {
    switch (Copy_u8BusId) {
      case AHB  : CLR_BIT(RCC_AHBENR  , Copy_u8PerId);  break;                  /*Disabling peripheral in AHB */
      case APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8PerId);  break;                  /*Disabling peripheral in APB1*/
      case APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8PerId);  break;                  /*Disabling peripheral in APB2*/
      //default   : /*Return Error*/                    break;
    }
  }
  else
  {
    /*Return Error*/
  }
}

void MRCC_voidCssEnable(void)                                                    /*Clock-security-system Activation function*/
{
  switch (RCC_CSS) {
    case RCC_CSS_ON  : SET_BIT(RCC_CR , 19);    break;                          /*Enabling  CSS*/
    case RCC_CSS_OFF : CLR_BIT(RCC_CR , 19);    break;                          /*Disabling CSS*/
    //default : Return Error                    break;
  }
}
