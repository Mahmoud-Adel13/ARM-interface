/*******************************************************************************/
/*Author: Mahmoud Adel Hassan **************************************************/
/*Date: 14 Auguest 2019 ********************************************************/
/*Version: V02 *****************************************************************/
/*******************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*GPIO Port options: */
#define     GPIO_PORTA       0
#define     GPIO_PORTB       1
#define     GPIO_PORTC       2

/*GPIO Pins options: */
#define     GPIO_PIN_0       0
#define     GPIO_PIN_1       1
#define     GPIO_PIN_2       2
#define     GPIO_PIN_3       3
#define     GPIO_PIN_4       4
#define     GPIO_PIN_5       5
#define     GPIO_PIN_6       6
#define     GPIO_PIN_7       7
#define     GPIO_PIN_8       8
#define     GPIO_PIN_9       9
#define     GPIO_PIN_10      10
#define     GPIO_PIN_11      11
#define     GPIO_PIN_12      12
#define     GPIO_PIN_13      13
#define     GPIO_PIN_14      14
#define     GPIO_PIN_15      15

/*GPIO_PIN value options: */
#define     LOW              0
#define     HIGH             1

/*Input push pull options */
#define INPUT_PUSH    0
#define INPUT_PULL    1


/*GPIO_PIN configuration options: */
/*1. Input options: */
#define     INPUT_ANALOG_PIN        0b0000
#define     INPUT_FLOATING_PIN      0b0100
#define     INPUT_PUSHPULL_PIN      0b1000
/*2. Output options: */
#define     OUTPUT_GP_PUSHPULL_PIN_10MHZ       0b0001
#define     OUTPUT_GP_OPENDRAIN_PIN_10MHZ      0b0101
#define     OUTPUT_AF_PUSHPULL_PIN_10MHZ       0b1001
#define     OUTPUT_AF_OPENDRAIN_PIN_10MHZ      0b1101

#define     OUTPUT_GP_PUSHPULL_PIN_2MHZ        0b0010
#define     OUTPUT_GP_OPENDRAIN_PIN_2MHZ       0b0110
#define     OUTPUT_AF_PUSHPULL_PIN_2MHZ        0b1010
#define     OUTPUT_AF_OPENDRAIN_PIN_2MHZ       0b1110

#define     OUTPUT_GP_PUSHPULL_PIN_50MHZ       0b0011
#define     OUTPUT_GP_OPENDRAIN_PIN_50MHZ      0b0111
#define     OUTPUT_AF_PUSHPULL_PIN_50MHZ       0b1011
#define     OUTPUT_AF_OPENDRAIN_PIN_50MHZ      0b1111




/*functions prototypes: */
void MGPIO_voidInit(u8 Copy_u8Port);                                            /*GPIO peripheral Enable */
void MGPIO_voidSetPinDir(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);      /*Pin-Mode configuration function */
void MGPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);   /*Set pin-output value function */
void MGPIO_voidGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);                     /*Get pin-input value function */
void MGPIO_voidSetPortDir(u8 Copy_u8Port , u8 Copy_u8Position , u32 Copy_u32Mode); /*Port-Mode configuration function */
void MGPIO_voidSetPortValue(u8 Copy_u8Port , u32 Copy_u32Value );               /*Set Port-output value function */
u32 MGPIO_u32GetPortValue(u8 Copy_u8Port);                                      /*Get Port-input value function */


#endif
