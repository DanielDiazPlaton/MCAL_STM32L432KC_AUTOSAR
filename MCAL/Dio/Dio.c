/****************************************************************************************************
 * @file           : Dio.c
 * @author         : Daniel Diaz Platon
 * @brief          : The DIO Driver abstracts the access to the microcontroller's hardware pins.
 *                   Furthermore, it allows the grouping of those pins.
 ***************************************************************************************************/
#include "Dio_Cfg.h"
#include "Dio.h"


Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId ){

    Dio_LevelType Dio_Return = STD_LOW;

    switch (ChannelId)
    {
    case DIO_CHANNEL_ID_8:
        if(GPIOA->IDR & GPIO_IDR_ID8)
        {
            Dio_Return = STD_HIGH;
        }
        else
        {
            Dio_Return = STD_LOW;
        }
        break;
    case PORT_B_PIN_3:
        if(GPIOB->IDR & GPIO_IDR_ID3)
        {
            Dio_Return = STD_HIGH;
        }
        else
        {
            Dio_Return = STD_LOW;
        }
        break;
    case PORT_B_PIN_4:
        if(GPIOB->IDR & GPIO_IDR_ID4)
        {
            Dio_Return = STD_HIGH;
        }
        else
        {
            Dio_Return = STD_LOW;
        }
        break;
    case PORT_B_PIN_5:
        if(GPIOB->IDR & GPIO_IDR_ID5)
        {
            Dio_Return = STD_HIGH;
        }
        else
        {
            Dio_Return = STD_LOW;
        }
        break;
    
    default:
        break;
    }

    return Dio_Return;
}

/**
 * @brief 
 * 
 * @param ChannelId which is the number of pin
 * @param Level to set LOW or HIGH the output pin
 */
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    switch (ChannelId)
    {
    case DIO_CHANNEL_ID_16:
        if(STD_HIGH == Level)
        {
            GPIOB->ODR |= GPIO_BRR_BR3;
        }
        else
        {
            GPIOB->ODR &= ~GPIO_BRR_BR3;
        }
        break;
    case PORT_B_PIN_4:
        if(STD_HIGH == Level)
        {
            GPIOB->ODR |= GPIO_BRR_BR4;
        }
        else
        {
            GPIOB->ODR &= ~GPIO_BRR_BR4;
        }
        break;
    case PORT_B_PIN_5:
        if(STD_HIGH == Level)
        {
            GPIOB->ODR |= GPIO_BRR_BR5;
        }
        else
        {
            GPIOB->ODR &= ~GPIO_BRR_BR5;
        }
        break;
    
    default:
        break;
    }
}

Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId ){

    // Dio_PortLevelType PortLevel_Return;

    // return PortLevel_Return;
    return 0;
}

void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level ){
    
}

Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr ){
    return 0U;
}

void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level ){
    
}

void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo ){
    
}

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId ){
    return 0U;
}




