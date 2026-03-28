#include "stm32re.h"
#include "gpio.h"

void delay(volatile uint32_t count) {
    while (count--);
}

int main(void)
{
    /* Bước 1: Khai báo biến struct */
    GPIO_InitTypeDef GPIO_InitStruct;

    /* Bước 2: Cấp clock cho GPIOA */
    RCC_GPIOA_CLK_ENABLE();

    /* Bước 3: Cấu hình tham số */
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_5;        /* PA5 = LED on Nucleo */
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

    /* Bước 4: Áp dụng cấu hình */
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Vòng lặp chính */
    while (1) {
        GPIO_SetBits(GPIOA, GPIO_Pin_5);    /* LED sáng */
        delay(500000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);  /* LED tắt */
        delay(500000);
    }
}
