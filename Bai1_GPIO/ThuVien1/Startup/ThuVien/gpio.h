/*******************************************************************************
 * @file    stm32f401re_gpio.h
 * @brief   GPIO peripheral driver - header file
 ******************************************************************************/
#ifndef STM32F401RE_GPIO_H
#define STM32F401RE_GPIO_H

#include "stm32re.h"

/*******************************************************************************
 * TYPES AND DEFINITIONS - EXPORTED
 ******************************************************************************/

typedef enum {
    GPIO_Pin_0  = 0x0001,
    GPIO_Pin_1  = 0x0002,
    GPIO_Pin_5  = 0x0020,
    GPIO_Pin_13 = 0x2000,
    GPIO_Pin_All = 0xFFFF
} GPIO_Pin_TypeDef;

typedef enum {
    GPIO_Mode_IN  = 0x00,   /* Input */
    GPIO_Mode_OUT = 0x01,   /* Output */
    GPIO_Mode_AF  = 0x02,   /* Alternate Function */
    GPIO_Mode_AN  = 0x03    /* Analog */
} GPIOMode_TypeDef;

typedef enum {
    GPIO_Speed_2MHz  = 0x00,
    GPIO_Speed_25MHz = 0x01,
    GPIO_Speed_50MHz = 0x02,
    GPIO_Speed_100MHz= 0x03
} GPIOSpeed_TypeDef;

typedef enum {
    GPIO_OType_PP = 0x00,   /* Push-pull */
    GPIO_OType_OD = 0x01    /* Open-drain */
} GPIOOType_TypeDef;

typedef enum {
    GPIO_PuPd_NOPULL = 0x00,
    GPIO_PuPd_UP     = 0x01,
    GPIO_PuPd_DOWN   = 0x02
} GPIOPuPd_TypeDef;

typedef enum {
    Bit_RESET = 0,
    Bit_SET   = 1
} BitAction;

/* Struct khởi tạo GPIO */
typedef struct {
    GPIO_Pin_TypeDef  GPIO_Pin;
    GPIOMode_TypeDef  GPIO_Mode;
    GPIOSpeed_TypeDef GPIO_Speed;
    GPIOOType_TypeDef GPIO_OType;
    GPIOPuPd_TypeDef  GPIO_PuPd;
} GPIO_InitTypeDef;

/*******************************************************************************
 * FUNCTIONS - EXPORTED
 ******************************************************************************/
void      GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
void      GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void      GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
BitAction GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
BitAction GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif /* STM32F401RE_GPIO_H */
