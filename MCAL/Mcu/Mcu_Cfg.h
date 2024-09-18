/*************************************************************************************************************************************************
 * @file           : Mcu_Cfg.h
 * @author         : Daniel Diaz Platon
 * @brief          : 
 *************************************************************************************************************************************************/

#ifndef MCU_CFG_H_
#define MCU_CFG_H_

#include "Mcu.h"

const uint8 gpios_clocks = (RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN | RCC_AHB2ENR_GPIOHEN);

Mcu_ConfigType McuDriverConfiguration =
{
    /* Gpio enable */
    gpios_clocks,       /* from 0 to 15*/
    1u,                 /* 1 = en adc, 0 = dis adc*/
};

Mcu_ClockType clock_cfg = 
{
    0,
};

#endif /* MCU_CFG_H_ */
