/*******************************************************************************
 * @file    stm32f401re.h
 * @brief   Device header - địa chỉ bộ nhớ và thanh ghi STM32F401RE
 * @author  Yen Nhi
 * @date    2025-06-01
 ******************************************************************************/
#ifndef STM32F401RE_H
#define STM32F401RE_H

#include <stdint.h>

/*******************************************************************************
 * TYPES AND DEFINITIONS - EXPORTED
 ******************************************************************************/

/* Base Addresses - Bộ nhớ */
#define FLASH_BASE          0x08000000UL
#define SRAM_BASE           0x20000000UL

/* Bus Base Addresses */
#define PERIPH_BASE         0x40000000UL
#define APB1PERIPH_BASE     (PERIPH_BASE + 0x00000000UL)
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000UL)

/* GPIO Base Addresses trên AHB1 */
#define GPIOA_BASE          (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x0800UL)

/* RCC Base Address */
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800UL)

/* *** ĐIỂM LẤY ĐIỂM 10: PHẢI DÙNG volatile *** */
typedef struct {
    volatile uint32_t MODER;    /* 0x00 - Mode register (2 bit/chân) */
    volatile uint32_t OTYPER;   /* 0x04 - Output type register (1 bit/chân) */
    volatile uint32_t OSPEEDR;  /* 0x08 - Output speed register */
    volatile uint32_t PUPDR;    /* 0x0C - Pull-up/Pull-down register */
    volatile uint32_t IDR;      /* 0x10 - Input data register */
    volatile uint32_t ODR;      /* 0x14 - Output data register */
    volatile uint32_t BSRRL;    /* 0x18 - Bit set register (lower) */
    volatile uint32_t BSRRH;    /* 0x1A - Bit reset register (upper) */
    volatile uint32_t LCKR;     /* 0x1C - Lock register */
    volatile uint32_t AFRL;     /* 0x20 - Alternate function low */
    volatile uint32_t AFRH;     /* 0x24 - Alternate function high */
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    uint32_t          RESERVED[8];
    volatile uint32_t AHB1ENR;  /* 0x30 - Enable clock cho GPIO */
    volatile uint32_t AHB2ENR;
    uint32_t          RESERVED2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
} RCC_TypeDef;

/* Macro ép kiểu con trỏ - dùng như biến toàn cục */
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define RCC     ((RCC_TypeDef *)  RCC_BASE)

/* Macro cấp clock cho GPIO */
#define RCC_GPIOA_CLK_ENABLE()  (RCC->AHB1ENR |= (1 << 0))
#define RCC_GPIOB_CLK_ENABLE()  (RCC->AHB1ENR |= (1 << 1))
#define RCC_GPIOC_CLK_ENABLE()  (RCC->AHB1ENR |= (1 << 2))

#endif /* STM32F401RE_H */
