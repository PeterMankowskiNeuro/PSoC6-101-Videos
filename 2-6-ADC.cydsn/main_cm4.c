/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "Thermistor.h"
#include <stdio.h>

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_1_Start();
    printf("Started\r\n");
    ADC_1_Start();
    ADC_1_StartConvert();

    for(;;)
    {
        float v1,v2;
        int16_t countThermistor, countReference;

        Cy_SAR_IsEndConversion(SAR,CY_SAR_WAIT_FOR_RESULT);
    
        /* Read the ADC count values */
        countReference  = Cy_SAR_GetResult16(SAR,0);
        countThermistor = Cy_SAR_GetResult16(SAR,1);
   
        v1 = Cy_SAR_CountsTo_Volts(SAR,0,countReference);
        v2 = Cy_SAR_CountsTo_Volts(SAR,1,countThermistor);
 
        uint32 resT = Thermistor_GetResistance(countReference, countThermistor);
        float temperature = (float)Thermistor_GetTemperature(resT) / 100.0 ;
 
        printf("V1 = %fv V2=%fv Vtot =%fv T=%fC T=%fF\r\n",v1,v2,v1+v2,temperature,9.0/5.0*temperature + 32.0);
        CyDelay(200);
    }
}

/* [] END OF FILE */
