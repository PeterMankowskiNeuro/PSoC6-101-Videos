#ifndef GLOBAL_H
#define GLOBAL_H
#include "FreeRTOS.h"
#include "semphr.h"
#include "event_groups.h"
    
#define PWM_EVENT_I2C (1<<0)
#define PWM_EVENT_BLE (1<<1)
#define PWM_EVENT_ALL (PWM_EVENT_I2C | PWM_EVENT_BLE)    

extern TaskHandle_t bleTaskHandle;

extern QueueHandle_t pwmQueue;
extern SemaphoreHandle_t updateEZI2CSemaphore;
extern EventGroupHandle_t pwmEventGroup;
extern SemaphoreHandle_t updateEZI2CSemaphore;;
    
#endif