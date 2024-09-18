/************************************************************************************************************
 * @file           : Adc.h
 * @date		   : Aug 26, 2024
 * @author         : Daniel Diaz Platon
 * @brief          : The ADC driver initializes and controls the internal Analogue Digital Converter unit(s) 
 *                   of the microcontroller. It provides services to start and stop a conversion respectively 
 *                   to enable and disable the trigger source of a conversion. Furthermore, it provides 
 *                   services to enable and disable a notification mechanism and routines to query the 
 *                   status and result of a conversion.
 ************************************************************************************************************/

#ifndef ADC_H_
#define ADC_H_


/******************************************************************
 **                         Includes                             **
 *****************************************************************/

#include <Std_Types.h>


/******************************************************************
 **                      DET Error Codes                         **
 *****************************************************************/



/******************************************************************
 **                        Type definitions                      **
 *****************************************************************/

typedef uint8 Adc_ChannelType;                  /* SWS_Adc_00506 */

typedef uint8 Adc_GroupType;                    /* SWS_Adc_00507 */

typedef sint32 Adc_ValueGroupType;               /* SWS_Adc_00508 */

typedef uint16 Adc_PrescaleType;                /* SWS_Adc_00509 */

typedef uint16 Adc_ConversionTimeType;          /* SWS_Adc_00510 */

typedef uint16 Adc_SamplingTimeType;            /* SWS_Adc_00511 */

typedef uint8 Adc_ResolutionType;              /* SWS_Adc_00512 */

typedef enum ETag_Adc_StatusType
{
    ADC_IDLE,
    ADC_BUSY,
    ADC_COMPLETED,
    ADC_STREAM_COMPLETED
} Adc_StatusType;                                /* SWS_Adc_00513 */

typedef enum ETag_Adc_TriggerSourceType
{
    ADC_TRIGG_SRC_SW,
    ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;                         /* SWS_Adc_00514 */

typedef enum ETag_Adc_GroupConvModeType
{
    ADC_CONV_MODE_ONESHOT,
    ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;                         /* SWS_Adc_00515 */

typedef uint8 Adc_GroupPriorityType;             /* SWS_Adc_00516 */

typedef uint8 Adc_GroupDefType;                  /* SWS_Adc_00517 */

typedef uint8 Adc_StreamNumSampleType;           /* SWS_Adc_00518 */

typedef enum ETag_Adc_StreamBufferModeType
{
    ADC_STREAM_BUFFER_LINEAR,
    ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;                       /* SWS_Adc_00519 */

typedef enum ETag_Adc_GroupAccessModeType
{
    ADC_ACCESS_MODE_SINGLE,
    ADC_ACCESS_MODE_STREAMING
} Adc_GroupAccessModeType;                          /* SWS_Adc_00528 */

typedef enum ETag_Adc_HwTriggerSignalType
{
    ADC_HW_TRIG_RISING_EDGE,
    ADC_HW_TRIG_FALLING_EDGE,
    ADC_HW_TRIG_BOTH_EDGES
} Adc_HwTriggerSignalType;                          /* SWS_Adc_00520 */

typedef uint16 Adc_HwTriggerTimerType;              /* SWS_Adc_00521 */

typedef enum ETag_Adc_PriorityImplementationType
{
    ADC_PRIORITY_NONE,
    ADC_PRIORITY_HW,
    ADC_PRIORITY_HW_SW
} Adc_PriorityImplementationType;                   /* SWS_Adc_00522 */

typedef enum ETag_Adc_GroupReplacementType
{
    ADC_GROUP_REPL_ABORT_RESTART,
    ADC_GROUP_REPL_SUSPEND_RESUME
} Adc_GroupReplacementType;                         /* SWS_Adc_00523 */

typedef enum ETag_Adc_ChannelRangeSelectType
{
    ADC_RANGE_UNDER_LOW,
    ADC_RANGE_BETWEEN,
    ADC_RANGE_OVER_HIGH,
    ADC_RANGE_ALWAYS,
    ADC_RANGE_NOT_UNDER_LOW,
    ADC_RANGE_NOT_BETWEEN,
    ADC_RANGE_NOT_OVER_HIGH
} Adc_ChannelRangeSelectType;                       /* SWS_Adc_00524 */

typedef enum ETag_Adc_ResultAlignmentType
{
    ADC_ALIGN_LEFT,
    ADC_ALIGN_RIGHT
} Adc_ResultAlignmentType;                          /* SWS_Adc_00525 */

typedef enum
{
    ADC_FULL_POWER
} Adc_PowerStateType;                               /* SWS_Adc_00526 */

typedef enum ETag_Adc_PowerStateRequestResultType
{
    ADC_SERVICE_ACCEPTED,
    ADC_NOT_INIT,
    ADC_SEQUENCE_ERROR,
    ADC_HW_FAILURE,
    ADC_POWER_STATE_NOT_SUPP,
    ADC_TRANS_NOT_POSSIBLE
} Adc_PowerStateRequestResultType;                  /* SWS_Adc_00527 */

/*Data structure required for initializing the ADC unit*/
typedef struct STag_Adc_ConfigType
{
    ADC_TypeDef*    p_adc;                              /* Base address of ADC*/
    uint32          conversionSequence;
    uint32          conversionlenght;
} Adc_ConfigType;                                        /* SWS_Adc_00505 */


/******************************************************************
 **                      FUNCTIONS PROTOTYPES                    **
 ******************************************************************/


void Adc_Init( const Adc_ConfigType* ConfigPtr );                                                           /* SWS_Adc_00365 */

Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, 
                                      const Adc_ValueGroupType* DataBufferPtr );                            /* SWS_Adc_91000 */

void Adc_DeInit( void );                                                                                    /* SWS_Adc_00366 */

void Adc_StartGroupConversion( Adc_GroupType Group );                                                       /* SWS_Adc_00367 */

void Adc_StopGroupConversion( Adc_GroupType Group );                                                        /* SWS_Adc_00368 */

Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, 
                              Adc_ValueGroupType* DataBufferPtr );                                          /* SWS_Adc_00369 */

void Adc_EnableHardwareTrigger( Adc_GroupType Group );                                                      /* SWS_Adc_00370 */

void Adc_DisableHardwareTrigger( Adc_GroupType Group );                                                     /* SWS_Adc_00371 */

void Adc_EnableGroupNotification( Adc_GroupType Group );                                                    /* SWS_Adc_00372 */

void Adc_DisableGroupNotification( Adc_GroupType Group );                                                   /* SWS_Adc_00373 */

Adc_StatusType Adc_GetGroupStatus( Adc_GroupType Group );                                                   /* SWS_Adc_00374 */

Adc_StreamNumSampleType Adc_GetStreamLastPointer( Adc_GroupType Group, 
                                                  Adc_ValueGroupType** PtrToSamplePtr );                    /* SWS_Adc_00375 */

void Adc_GetVersionInfo( Std_VersionInfoType* versioninfo );                                                /* SWS_Adc_00376 */

Std_ReturnType Adc_SetPowerState( Adc_PowerStateRequestResultType* Result );                                /* SWS_Adc_00475 */

Std_ReturnType Adc_GetCurrentPowerState( Adc_PowerStateType* CurrentPowerState, 
                                         Adc_PowerStateRequestResultType* Result );                         /* SWS_Adc_00476 */

Std_ReturnType Adc_GetTargetPowerState( Adc_PowerStateType* TargetPowerState, 
                                        Adc_PowerStateRequestResultType* Result );                          /* SWS_Adc_00477 */

Std_ReturnType Adc_PreparePowerState( Adc_PowerStateType PowerState, 
                                      Adc_PowerStateRequestResultType* Result );                            /* SWS_Adc_00478 */

void Adc_Main_PowerTransitionManager( void );                                                               /* SWS_Adc_00479 */

#endif /* ADC_H_ */
