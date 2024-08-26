/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Daniel Diaz Platon
 * @brief          : Main program body
 ******************************************************************************
 */

#include "Std_Types.h"
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Port.h"
#include "Port_Cfg.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "DOIO.h"
#include "indicatorLampFunc.h"


int main(void)
{
	Mcu_Init(&McuDriverConfiguration);
    Mcu_InitClock(clock_cfg);

    /* PORTA */
    Port_Init(&port_driver_cfg[0]);
    /* PORTB */
    Port_Init(&port_driver_cfg[1]);

    while(1)
    {
        // =============== application ================
        DOIO_U.ctrlSW_B = Dio_ReadChannel(CHANEL_ID_3);
    	
    	DOIO_Y.IndicatorLamp_B = DOIO_indicatorLampFunc(DOIO_U.ctrlSW_B);

        if(DOIO_Y.IndicatorLamp_B)
        {
            Dio_WriteChannel(CHANEL_ID_0, STD_HIGH);
        }
        else
        {
            Dio_WriteChannel(CHANEL_ID_0, STD_LOW);
        }
    }
}
