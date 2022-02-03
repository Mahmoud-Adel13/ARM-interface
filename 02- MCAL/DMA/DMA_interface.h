/*******************************************************************************/
/* Author : Mahmoud Adel   *****************************************************/
/* Date : 9 September 2020 *****************************************************/
/* Version : V01           *****************************************************/
/*******************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


/* Functions prototypes */
void MDMA_voidChannelInit (void);
void MDMA_voidChannelStart(u8 Copy_u8Channel , u32* Copy_Pu32SrcAddress , u32* Copy_Pu32DestAddress , u32 Copy_u32BlockLength);
//void MDMA_voidChannelConfig( );
void MDMA_voidClearInterruptFlag(u8 Copy_u8Channel , u8 Copy_u8Flag);
u8   MDMA_u8GetInterruptFlag    (u8 Copy_u8Channel , u8 Copy_u8Flag);



#endif
