/*******************************************************************************/
/* Author : Mahmoud Adel    ****************************************************/
/* Date : 16 Septemper 2020 ****************************************************/
/* Version : V01            ****************************************************/
/*******************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* Functions prototypes */
void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToSend , u8 *Copy_u8VariableToReceive);
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToSend , void (*CallBack) (u8));


#endif
