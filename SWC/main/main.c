/********************************************************************************
 * @file           : main.c
 * @author         : Daniel Diaz Platon
 * @brief          : Main program body
 *******************************************************************************/

#include "Std_Types.h"
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Port.h"
#include "Port_Cfg.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Adc.h"
#include "Adc_cfg.h"
#include "DOIO.h"
#include "indicatorLampFunc.h"
#include "PCCI.h"
#include "calculatePercentFunc.h"

int main(void)
{
	Mcu_Init(&McuDriverConfiguration);
    Mcu_InitClock(clock_cfg);

    /* PORTA */
    Port_Init(&port_driver_cfg[0]);
    /* PORTB */
    Port_Init(&port_driver_cfg[1]);

    Adc_Init(&adc_cfg[0]);

    Adc_StartGroupConversion(adc_group);

    while(1)
    {
        /* =============== DIO Module Test ================ */
        DOIO_U.ctrlSW_B = Dio_ReadChannel(CHANEL_ID_3);
    	DOIO_Y.IndicatorLamp_B = DOIO_indicatorLampFunc(DOIO_U.ctrlSW_B);

        /* To check DIO module */
        if(DOIO_Y.IndicatorLamp_B)
        {
            Dio_WriteChannel(DIO_CHANNEL_ID_16, STD_HIGH);
        }
        else
        {
            Dio_WriteChannel(DIO_CHANNEL_ID_16, STD_LOW);
        }

        /* =============== DIO Module Test ================ */

        Adc_ReadGroup(adc_group, &adc_bfr_group);
        PCCI_U.percRawVal_U16 = adc_bfr_group;
        PCCI_Y.indicatorLamp_B = PCCI_calculatePercentFunc(PCCI_U.percRawVal_U16);

        /* To check ADC module*/
        if(PCCI_Y.indicatorLamp_B)
        {
            Dio_WriteChannel(DIO_CHANNEL_ID_18, STD_HIGH);
        }
        else
        {
            Dio_WriteChannel(DIO_CHANNEL_ID_18, STD_LOW);
        }
    }
}
