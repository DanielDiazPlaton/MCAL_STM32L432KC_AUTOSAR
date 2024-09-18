/**********************************************************************************************************
 * @file           : Dio.h
 * @author         : Daniel Diaz Platon
 * @brief          : The DIO Driver abstracts the access to the microcontroller's hardware pins.
 *                   Furthermore, it allows the grouping of those pins. 
 **********************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/******************************************************
 **                     Includes                     **
 ******************************************************/
#include "Std_Types.h"

/******************************************************
 **                DET Error Codes                   **
 ******************************************************/
#define DIO_E_PARAM_INVALID_CHANNEL_ID      0x0A        /* SWS_Dio_00175 */
#define DIO_E_PARAM_INVALID_PORT_ID         0x14        /* SWS_Dio_00177 */
#define DIO_E_PARAM_INVALID_GROUP           0x1F        /* SWS_Dio_00178 */
#define DIO_E_PARAM_POINTER                 0x20        /* SWS_Dio_00188 */

/*******************************************************
 **                 Type definitions                  **
 *******************************************************/
typedef uint32 Dio_ChannelType;                     /* SWS_Dio_00182 */

typedef uint32 Dio_PortType;                        /* SWS_Dio_00183 */

typedef struct {
    uint32          mask;
    uint8           offset;
    Dio_PortType    port;
}Dio_ChannelGroupType;                              /* SWS_Dio_00184 */

typedef uint8 Dio_LevelType;                        /* SWS_Dio_00185 */

typedef uint32 Dio_PortLevelType;                   /* SWS_Dio_00186 */

/******************************************************************
 **                      FUNCTIONS PROTOTYPES                    **
 ******************************************************************/

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );                                                 /* SWS_Dio_00133 */

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );

Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );

void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );

Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );

void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );

void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId );


#endif /* DIO_H_ */
