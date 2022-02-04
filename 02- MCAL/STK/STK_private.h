/*******************************************************************************/
/* Author: Mahmoud Adel  *******************************************************/
/* Date: 26 August 2020  *******************************************************/
/* Version: V01          *******************************************************/
/*******************************************************************************/

#ifndef MSTK_PRIVATE_H
#define MSTK_PRIVATE_H

/* Register definitions: */
typedef struct{
  volatile u32   CTRL;
  volatile u32   LOAD;
  volatile u32   VALUE;
  volatile u32   CALIB;
}STK_t;

#define  STK  ((volatile STK_t*) 0xE000E010)

/* Global variable*/
void (*MSTK_Callback)(void);


#endif
