/*******************************************************************************/
/*Author: Mahmoud Adel Hassan **************************************************/
/*Date: 26 Auguest 2019 ********************************************************/
/*Version: V01 *****************************************************************/
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

#define  STk  ((volatile STK_t*) 0xE000E010)

/* Global variable*/
void (*MSTK_Callback)(void);


#endif
