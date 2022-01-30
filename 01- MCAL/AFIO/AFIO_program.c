/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 22 August 2019 *******************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/

/* Inclusion part: */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


/* Functions definition part: */
void MAFIO_voidConfigurateEXTILineBit(u8 Copy_u8Line , u8 Copy_u8Bit)
{
  u8  Local_u8RegIndex = 0;
  if (Copy_u8Line < 4)
  {
    AFIO-> EXTICR1 &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO-> EXTICR1 |= ((Copy_u8Bit) << (Copy_u8Line * 4));
  }
  elif (Copy_u8Line < 8)
  {
    Copy_u8Line -= 4;
    AFIO-> EXTICR2 &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO-> EXTICR2 |= ((Copy_u8Bit) << (Copy_u8Line * 4));
  }
  elif (Copy_u8Line < 12)
  {
    Copy_u8Line -= 8;
    AFIO-> EXTICR3 &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO-> EXTICR3 |= ((Copy_u8Bit) << (Copy_u8Line * 4));
  }
  elif (Copy_u8Line < 16)
  {
    Copy_u8Line -= 12;
    AFIO-> EXTICR4 &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO-> EXTICR4 |= ((Copy_u8Bit) << (Copy_u8Line * 4));
  }
  else
    #error"Wrong line entry"
}
