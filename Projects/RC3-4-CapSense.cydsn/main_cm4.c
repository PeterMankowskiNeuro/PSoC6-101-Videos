 #include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "bleTask.h"
#include "uartTask.h"
#include "capsenseTask.h"


/*****************************************************************************\
 * Function:   main
 * Input:      void
 * Returns:    int (this function acutally never returns...)
 * Description: Starts the system ... initalizes the BLE task.. then starts the RTOS
 *   
 *    
\*****************************************************************************/
int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_Start();
    setvbuf(stdin,0,_IONBF,0);
    xTaskCreate(bleTask,"bleTask",8*1024,0,2,0);
    xTaskCreate(uartTask,"uartTask",1024,0,1,0);
    xTaskCreate(capsenseTask,"capsenseTask",1024,0,1,0);
    vTaskStartScheduler();
}
