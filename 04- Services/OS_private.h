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


/* Static functions */
volatile u16 TickCounts = 0;
static void Scheduler(void)
{
  for(u8 i= 0 ; i<NUM_OF_TASKS ; i++)
  {
    /* To check if its time to call a specific task at certain tick count & first delay check & Task is ready */
    if( ((TickCounts % OS_Tasks[i].state) == Task_Ready ) && ((TickCounts % OS_Tasks[i].priodicity) == 0) && (OS_Tasks[i].firstDelay == TickCounts) )
    {
      /* Call task's function */
      OS_Tasks[i].Fptr();
    }
  }
  TickCounts++;
}


#endif
