/*******************************************************************************/
/* Author : Mahmoud Adel *******************************************************/
/* Date : 5 Septemper 2020 *****************************************************/
/* Version : V01         *******************************************************/
/*******************************************************************************/


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


/* Task struct */
typedef struct
{
    u16 priodicity;
    void (*Fptr)(void);
    u8 firstDelay;
    state state;
}Task;

/* Task array "Array of struct" */
#define  NULL     (void*)0
static   Task  OS_Tasks[NUM_OF_TASKS] = {NULL};


/* Static functions prototype */
static void Scheduler(void);


#endif
