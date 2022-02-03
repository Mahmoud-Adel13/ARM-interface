/*******************************************************************************/
/* Author : Mahmoud Adel   *****************************************************/
/* Date : 9 September 2020 *****************************************************/
/* Version : V01           *****************************************************/
/*******************************************************************************/

/* Inclution part */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

/* Functions definitions */
void MDMA_voidChannelInit(void)
{
  /* MEM2MEM mode */
  #if   CCR_MEM2MEM == DISABLED
    CLR_BIT(DMA-> Channel[DMA_channel].CCR , 14);
  #elif CCR_MEM2MEM == ENABLED
    SET_BIT(DMA-> Channel[DMA_channel].CCR , 14);
  #else
    #error "Wrong MEM2MEM mode."
  #endif

  /* priority Level initialization */
  DMA-> Channel[DMA_channel].CCR &=  ~((0b11) << 12);
  DMA-> Channel[DMA_channel].CCR |= ((CCR_PL) << 12);

  /* MSIZE & PSIZE */
  DMA-> Channel[DMA_channel].CCR &=  ~((0b11) << 10);                           /* Clear MSIZE bits */
  DMA-> Channel[DMA_channel].CCR |= ((CCR_MSIZE) << 10);                        /* MSIZE set */
  DMA-> Channel[DMA_channel].CCR &=  ~((0b11) << 8);                            /* Clear MSIZE bits */
  DMA-> Channel[DMA_channel].CCR |= ((CCR_PSIZE) << 8);                         /* PSIZE set */

  /** MINC, PINC, CIRC **/
  /* MINC setting */
  #if   CCR_MINC == DISABLED
    CLR_BIT(DMA-> Channel[DMA_channel].CCR , 7);
  #elif CCR_MINC == ENABLED
    SET_BIT(DMA-> Channel[DMA_channel].CCR , 7);
  #else
    #error "Wrong MINC mode."
  #endif
  /* PINC setting */
  #if   CCR_PINC == DISABLED
    CLR_BIT(DMA-> Channel[DMA_channel].CCR , 6);
  #elif CCR_PINC == ENABLED
    SET_BIT(DMA-> Channel[DMA_channel].CCR , 6);
  #else
    #error "Wrong PINC mode."
  #endif
  /* CIRC setting */
  #if   CCR_CIRC == DISABLED
    CLR_BIT(DMA-> Channel[DMA_channel].CCR , 5);
  #elif CCR_CIRC == ENABLED
    SET_BIT(DMA-> Channel[DMA_channel].CCR , 5);
  #else
    #error "Wrong CIRC mode."
  #endif

  /* Transfer direction setting */
  #if   CCR_MINC == PRE_SRC
    CLR_BIT(DMA-> Channel[DMA_channel].CCR , 4);
  #elif CCR_MINC == MEM_SRC
    SET_BIT(DMA-> Channel[DMA_channel].CCR , 4);
  #else
    #error "Wrong direction mode."
  #endif

  /* Interrupts enable */
  SET_BIT(DMA-> CCR , 1);                                                       /* Transfer complete interrupt */
  SET_BIT(DMA-> CCR , 2);                                                       /* HAlf transfer complete interrupt */
  SET_BIT(DMA-> CCR , 3);                                                       /* Transfer error interrupt */
}

/*void MDMA_voidChannelConfig( )
{

}*/

void MDMA_voidChannelStart(u8 Copy_u8Channel , u32* Copy_Pu32SrcAddress , u32* Copy_Pu32DestAddress , u32 Copy_u32BlockLength)
{
  /* Disable channel */
  CLR_BIT(DMA-> Channel[Copy_u8Channel].CCR , 0);
  /* Channel config */
  DMA-> Channel[Copy_u8Channel].CPAR = Copy_Pu32SrcAddress;
  DMA-> Channel[Copy_u8Channel].CMAR = Copy_Pu32DestAddress;
  DMA-> Channel[Copy_u8Channel].CNDTR = Copy_u32BlockLength;
  /* Enable DMA channel */
  SET_BIT(DMA-> Channel[Copy_u8Channel].CCR , 0);
}

void MDMA_voidClearInterruptFlag(u8 Copy_u8Channel , u8 Copy_u8Flag)
{
  SET_BIT(DMA-> Channel[DMA_channel].IFCR , ( Copy_u8Flag + 3 * (Copy_u8Channel -1) );
}

u8 MDMA_u8GetInterruptFlag(u8 Copy_u8Channel , u8 Copy_u8Flag)
{
  u8 Local_u8Flag = 0;
  Local_u8Flag = GET_BIT(DMA-> Channel[DMA_channel].ISR , ( Copy_u8Flag + 3 * (Copy_u8Channel -1) );
  return Local_u8Flag;
}
