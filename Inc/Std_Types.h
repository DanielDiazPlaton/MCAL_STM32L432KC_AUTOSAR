/*
 *  File: Std_Types.h
 *
 *  Created on: Jan 5, 2023
 *  Author: Daniel Diaz Platon
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#include "stm32l432xx.h"
#include "Platform_types.h"

#define  E_OK             0x00U
#define  E_NOT_OK         0x01U

#define STD_LOW           0x00U
#define STD_HIGH          0x01U

#define STD_IDLE          0x00U
#define STD_ACTIVE        0x01U

#define STD_OFF           0x00U
#define STD_ON            0x01U

typedef uint8           Std_ReturnType;

typedef struct {
    // nothing
}Std_VersionInfoType;


#endif /* STD_TYPES_H_ */
