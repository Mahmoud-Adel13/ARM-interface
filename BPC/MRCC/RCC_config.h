/*******************************************************************************/
/* Author: Mahmoud Adel                                                        */
/* Date: 12 Augest 2020                                                        */
/* Version: V01                                                                */

#ifndef RCC_config_H
#define RCC_config_H

/*System clock configuration: */
/*Options:    1. RCC_HSI    2. RCC_HSE_CR   3. RCC_HSE_CRY    4. RCC_PLL */
#define   CLOCK_TYPE        RCC_HSE_CRY

/*Clock security sytem configuration: */
/*Options:    1. RCC_CSS_ON   2.RCC_CSS_OFF */
#define   RCC_CSS           RCC_CSS_ON

/*RCC_HSI_Trim_step configuration: */
/*RCC_HSI_Trim options:   ZERO,ONE,TWO,THREE,...,SIXTEEN    ***each stepsNO is multiplied by 40 KHZ***/
#define   RCC_HSI_TRIM_STEP      ZERO
/*RCC_HSI_Trim type configuration: */
#define   RCC_HSI_TRIM           PLUS_TRIM

/*RCC_PLL_INPUT configuration: */
/*              options: RCC_PLL_IN_HSI_DIV_2
                         RCC_PLL_IN_HSE_DIV_2
                         RCC_PLL_IN_HSE       */
#define   RCC_PLL_INPUT          RCC_PLL_IN_HSI_DIV_2



/*RCC_PLL_MUL_VAL configuration: */
/*                options: MUL_X_2
                          MUL_X_3
                          MUL_X_4
                          MUL_X_5
                          MUL_X_6
                          MUL_X_7
                          MUL_X_8
                          MUL_X_9
                          MUL_X_10
                          MUL_X_11
                          MUL_X_12
                          MUL_X_13
                          MUL_X_14
                          MUL_X_15
                          MUL_X_16
                          MUL_X_16 */
#define   RCC_PLL_Mul_val        MUL_X_2


#endif
