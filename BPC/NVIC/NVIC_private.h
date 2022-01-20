/*******************************************************************************/
/* Auther: Mahmoud Adel ********************************************************/
/* Date : 18 August 2019 *******************************************************/
/* Version: V01 ****************************************************************/
/*******************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
0xE000E100
/*Register definitions: */
#define       NVIC_ISER0        *((u32*)0xE000E100)                             /*Register to enable external interrupts from 0  to 31 */
#define       NVIC_ISER1        *((u32*)0xE000E104)                             /*Register to enable external interrupts from 32 to 63 */
#define       NVIC_ICER0        *((u32*)0xE000E180)                             /*Register to disable external interrupts from 0  to 31 */
#define       NVIC_ICER1        *((u32*)0xE000E184)                             /*Register to disable external interrupts from 32 to 63 */
#define       NVIC_ISPR0        *((u32*)0xE000E200)                             /*Register to set external interrupts pending flags from 0 to 31 */
#define       NVIC_ISPR1        *((u32*)0xE000E204)                             /*Register to set external interrupts pending flags from 32 to 63 */
#define       NVIC_ICPR0        *((u32*)0xE000E280)                             /*Register to clear external interrupts pending flags from 0 to 31 */
#define       NVIC_ICPR1        *((u32*)0xE000E284)                             /*Register to clear external interrupts pending flags from 32 to 63 */
#define       NVIC_IABR0        *((volatile u32*)0xE000E300)
#define       NVIC_IABR1        *((volatile u32*)0xE000E304)






#endif
