#ifndef UARTTASK_H
#define UARTTASK_H
    #include "FreeRTOS.h"
    #include "semphr.h"
    void uartTask(void *arg);
    extern SemaphoreHandle_t uartSemaphore;
#endif