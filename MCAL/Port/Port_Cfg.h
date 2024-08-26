/**
 ******************************************************************************
 * @file           : Port_Cfg.h
 * @author         : Daniel Diaz Platon
 * @brief          : 
 ******************************************************************************
 */

#include "Port.h"

/* USART2 as LIN */
#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#define PIN_LOW                 (0U)
#define PIN_HIGH                (1U)

Port_ConfigType port_driver_cfg[] =
{
    {
        GPIOA,
        0,
        0,
        0,
        GPIO_MODER_MODE8
    },
    {
        GPIOB,
        (GPIO_MODER_MODE3_0),
        0,
        0,
        GPIO_MODER_MODE3
    },
};

#endif /* PORT_CFG_H_ */
