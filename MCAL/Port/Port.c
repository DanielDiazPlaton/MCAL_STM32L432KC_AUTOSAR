/**
 ******************************************************************************
 * @file           : port.c
 * @author         : Daniel Diaz Platon
 * @brief          : The PORT Driver module shall initialize the whole port 
 *                   structure of the microcontroller. SWS_Port_00001
 ******************************************************************************
 */

/******************************************************
 **                     Includes                     **
 ******************************************************/
#include "Port.h"



/*******************************************************
 **                      FUNCTIONS                    **
 *******************************************************/

/**
 * @brief The function Port_Init shall initialize ALL ports and port pins with the configuration set pointed to by the parameter
 *        SWS_Port_00140, SWS_Port_00041
 * 
 * @param ConfigPtr 
 */
void Port_Init( const Port_ConfigType* ConfigPtr )
{
		ConfigPtr->port->MODER  &= ~(ConfigPtr->clear);  // clearing the port moder
		ConfigPtr->port->MODER  |= ConfigPtr->moder; // setting INPUT/OUTPUT mode

		ConfigPtr->port->AFR[0] &= ~(ConfigPtr->clear);
		ConfigPtr->port->AFR[1] &= ~(ConfigPtr->clear);

		ConfigPtr->port->AFR[0] |= ConfigPtr->altFunc1;
		ConfigPtr->port->AFR[1] |= ConfigPtr->altFunc2;

		//ConfigPtr->port->PUPDR &= ~(ConfigPtr->clear); // clearing the port moder
		//ConfigPtr->port->PUPDR |= ConfigPtr->pupd; // setting PU mode

}

// \param Pin , the argument to this parameter will be PORT_MODERx_Pos
void Port_SetPinDirection( GPIO_TypeDef* port, Port_PinType Pin, Port_PinDirectionType Direction )
{
	
}

void Port_RefreshPortDirection( void ){

}

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

}
