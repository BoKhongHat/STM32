#include <stdint.h>
#include "stm32f401re_gpio.h"
#include "stm32f401re_rcc.h"

//Define Logic GPIO_PIN-
#define GPIO_PIN_SET            1
#define GPIO_PIN_RESET          0
#define GPIO_PIN_LOW            0
#define GPIO_PIN_HIGH           1

//Define GPIO_PIN
#define BUZZER_GPIO_PORT        GPIOC
#define BUZZER_GPIO_PIN         GPIO_Pin_9
#define BUZZER_PIN9             9
#define BUZZERControl_SetClock  RCC_AHB1Periph_GPIOC

#define BUTTON_GPIO_PORT        GPIOB
#define BUTTON_GPIO_PIN         GPIO_Pin_4
#define BUTTON_B5_PIN           4
#define BUTTONControl_SetClock  RCC_AHB1Periph_GPIOB

//Ham tao tre de chong rung khi nhan nut
void Delay(uint32_t time)
{
    for (uint32_t i = 0; i < time; i++);
}

static
void Buzzer_Init(void)
{
    //Declare type variable GPIO Struc---
    GPIO_InitTypeDef GPIO_InitStructure;

    //Enable Clock GPIOC-
    RCC_AHB1PeriphClockCmd(BUZZERControl_SetClock, ENABLE);

    //Choose Pin Buzzer---
    GPIO_InitStructure.GPIO_Pin = BUZZER_GPIO_PIN;

    //Choose Pin Buzzer as Out----
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;

    //Choose Speed Pin----
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    //Select type---
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

    //Select status--
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    //The function initializes all of the above values--
    GPIO_Init(BUZZER_GPIO_PORT, &GPIO_InitStructure);
}

static
void Button_Init(void)
{
    //Declare type variable GPIO Struc-
    GPIO_InitTypeDef GPIO_InitStructure;

    //Enable Clock GPIOB--
    RCC_AHB1PeriphClockCmd(BUTTONControl_SetClock, ENABLE);

    //Choose Pin BUTTON---
    GPIO_InitStructure.GPIO_Pin = BUTTON_GPIO_PIN;

    //Choose Pin Button as Input-
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;

    //Choose Speed Pin-----
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    //Select status--
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    //The function initializes all of the above values....
    GPIO_Init(BUTTON_GPIO_PORT, &GPIO_InitStructure);
}

static
void BuzzerControl_SetStatus(GPIO_TypeDef *GPIOx, uint8_t GPIO_PIN, uint8_t Status)
{
    //Set bit in BSRR Registers--
    if (Status == GPIO_PIN_SET)
    {
        GPIOx->BSRRL |= 1 << GPIO_PIN;
    }

    //Reset bit in BSRR Registers-
    if (Status == GPIO_PIN_RESET)
    {
        GPIOx->BSRRH |= 1 << GPIO_PIN;
    }
}

static
uint8_t ButtonRead_Status(GPIO_TypeDef *GPIOx, uint32_t GPIO_PIN)
{
    uint32_t Read_Pin;

    //Read bit in IDR Registers---
    Read_Pin = (GPIOx->IDR) >> GPIO_PIN;
    Read_Pin = Read_Pin & 0x01;

    return Read_Pin;
}

int main(void)
{
    uint8_t current_buzzer_status = GPIO_PIN_RESET;

    Buzzer_Init();
    Button_Init();

    // Dam bao Buzzer tat luc moi khoi dong
    BuzzerControl_SetStatus(BUZZER_GPIO_PORT, BUZZER_PIN9, GPIO_PIN_RESET);

    while(1)
    {
        // Nhan nut B5 (Pull Up) nen khi nhan mang muc logic 0
if (ButtonRead_Status(BUTTON_GPIO_PORT, BUTTON_B5_PIN) == 0)
        {
            // Tao va su dung them ham Delay de chong rung khi nhan nut
            Delay(50000);

            if (ButtonRead_Status(BUTTON_GPIO_PORT, BUTTON_B5_PIN) == 0)
            {
                // Thuc hien thuat toan dao trang thai Buzzer khi duoc an nut
                if (current_buzzer_status == GPIO_PIN_RESET)
                {
                    current_buzzer_status = GPIO_PIN_SET;
                    BuzzerControl_SetStatus(BUZZER_GPIO_PORT, BUZZER_PIN9, GPIO_PIN_SET);
                }
                else
                {
                    current_buzzer_status = GPIO_PIN_RESET;
                    BuzzerControl_SetStatus(BUZZER_GPIO_PORT, BUZZER_PIN9, GPIO_PIN_RESET);
                }

                // Cho cho den khi nha nut an
                while (ButtonRead_Status(BUTTON_GPIO_PORT, BUTTON_B5_PIN) == 0);
                Delay(50000);
            }
        }
    }
}
