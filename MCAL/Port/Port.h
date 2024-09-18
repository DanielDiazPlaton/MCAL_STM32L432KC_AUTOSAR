/********************************************************************************
 * @file           : port.h
 * @author         : Daniel Diaz Platon
 * @brief          : The PORT Driver module shall initialize the whole port 
 *                   structure of the microcontroller. SWS_Port_00001
 *******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/******************************************************
 **                     Includes                     **
 ******************************************************/
#include "Std_Types.h"

/******************************************************
 **                DET Error Codes                   **
 ******************************************************/
#define PORT_E_PARAM_PIN                    0x0A            /* SWS_Port_00051 */
#define PORT_E_DIRECTION_UNCHANGEABLE       0x0B
#define PORT_E_INIT_FAILED                  0x0C
#define PORT_E_PARAM_INVALID_MODE           0x0D
#define PORT_E_MODE_UNCHANGEABLE            0x0E
#define PORT_E_UNINIT                       0x0F
#define PORT_E_PARAM_POINTER                0x10

/*******************************************************
 **                 Type definitions                  **
 *******************************************************/

typedef struct {
    GPIO_TypeDef*   port;                // Configure port (RCC_AHBEN1_PORT_A)
    uint32          moder;           // Input/Output or alternative function
    //uint32          initValue;           //Default Output
    //uint32          mode;                // ON, OFF interact with BSRR
    //uint32          pupd;                // choose pull up, pull down
    uint32          altFunc1;             // Set function mode
    uint32          altFunc2;             // Set function mode
    uint32          clear;
}Port_ConfigType;                   /* SWS_Port_00228, SWS_Port_00073 */

typedef uint32 Port_PinType;        /* SWS_Port_00229, SWS_Port_00013, SWS_Port_00219 */

typedef enum {
    PORT_PIN_IN,
    PORT_PIN_OUT
}Port_PinDirectionType;             /* SWS_Port_00230, SWS_Port_00046, SWS_Port_00220 */

typedef uint32 Port_PinModeType;    /* SWS_Port_00231, SWS_Port_00124, SWS_Port_00212, SWS_Port_00221 */

#define PORT_A_PIN_0            (0U)          /* ADC1/5    */
#define PORT_A_PIN_1            (1U)
#define PORT_A_PIN_2            (2U)          /* LIN       */
#define PORT_A_PIN_3            (3U)          /* LIN       */
#define PORT_A_PIN_4            (4U)          /* SPI1_SSEL */
#define PORT_A_PIN_5            (5U)          /* SPI1_SCLK */
#define PORT_A_PIN_6            (6U)          /* SPI1_MISO */
#define PORT_A_PIN_7            (7U)          /* SPI1_MOSI */
#define PORT_A_PIN_8            (8U)          /* PWM1/1    */ /* button */
#define PORT_A_PIN_9            (9U)          /* UART1_TX  */
#define PORT_A_PIN_10           (10U)         /* UART1_RX  */
#define PORT_A_PIN_11           (11U)         /* CAN_RD    */
#define PORT_A_PIN_12           (12U)         /* CAN_TD    */

#define PORT_B_PIN_0            (13U)         /* ADC1/15   */
#define PORT_B_PIN_1            (14U)         /* PWM1/3N   */
#define PORT_B_PIN_2            (15U)
#define PORT_B_PIN_3            (16U)         /* I/O       */   /* LED3 */
#define PORT_B_PIN_4            (17U)         /* I/O       */
#define PORT_B_PIN_5            (18U)         /* I/O       */
#define PORT_B_PIN_6            (19U)         /* I2C_SCL   */
#define PORT_B_PIN_7            (20U)         /* I2C_SDA   */
#define PORT_B_PIN_8            (21U)


/*******************************************************
 **                      FUNCTIONS                    **
 *******************************************************/

void Port_Init( const Port_ConfigType* ConfigPtr );

#ifndef PORTSETPINDIRECTIONAPI
void Port_SetPinDirection( GPIO_TypeDef* port, Port_PinType Pin, Port_PinDirectionType Direction );  /* SWS_Port_00086 */
#endif

void Port_RefreshPortDirection( void );

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );

#endif /* PORT_H_ */
