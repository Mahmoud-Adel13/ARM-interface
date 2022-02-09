/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 21 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

/* Functions prototype */
void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16 *Copy_u16Image);
void HTFT_voidFillColor(u16 Copy_u16Color);
void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2 , u16 Copy_u16Color);

#endif
