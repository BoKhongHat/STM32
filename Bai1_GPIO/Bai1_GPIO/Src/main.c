#include <stdint.h>
#include <stm32f401re_gpio.h>
#include <stm32f401re_rcc.h>

#define LOW                         0
#define BTN_PRESS                   LOW

//Define Logic GPIO_PIN
#define GPIO_PIN_SET                1
#define GPIO_PIN_RESET              0
#define GPIO_PIN_LOW                0
#define GPIO_PIN_HIGH               1

//Define GPIO_PIN
#define LED_GPIO_PORT               GPIOA
#define LED_GPIO_PIN                GPIO_Pin_5
#define LED_PIN5                    5
#define LEDControl_SetClock         RCC_AHB1Periph_GPIOA

#define BUTTON_GPIO_PORT            GPIOC
#define BUTTON_GPIO_PIN             GPIO_Pin_13
#define BUTTON_PIN13                13
#define BUTTONControl_SetClock      RCC_AHB1Periph_GPIOC

// Đã thêm volatile để không bị tối ưu hóa mất hàm delay
void delay() {
    for (volatile uint32_t i = 0; i < 500000; i++);
}

static void Led_init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(LEDControl_SetClock, ENABLE);
    GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

    // Sửa lại thành DOWN cho khớp với comment của bạn
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
}

static void Button_Init (void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    // Đã tách dòng lệnh này ra khỏi comment
    RCC_AHB1PeriphClockCmd (BUTTONControl_SetClock, ENABLE);

    GPIO_InitStructure.GPIO_Pin = BUTTON_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_Init(BUTTON_GPIO_PORT, &GPIO_InitStructure);
}

static void LedControl_SetStatus (GPIO_TypeDef * GPIOx, uint8_t GPIO_PIN, uint8_t Status) {
    if (Status == GPIO_PIN_SET) {
        GPIOx->BSRRL |= 1 << GPIO_PIN;
    }
    if (Status == GPIO_PIN_RESET) {
        GPIOx->BSRRH |= 1 << GPIO_PIN;
    }
}

static uint8_t ButtonRead_Status (GPIO_TypeDef * GPIOx, uint32_t GPIO_PIN) {
    uint32_t Read_Pin;
    Read_Pin = (GPIOx->IDR) >> GPIO_PIN;
    Read_Pin = Read_Pin & 0x01;
    return Read_Pin;
}

int main(void)
{
    // Sử dụng biến lưu trạng thái hiện tại thay vì cộng dồn số
    uint8_t current_led_status = GPIO_PIN_LOW;

    Led_init();
    Button_Init();

    // Đảm bảo LED tắt ban đầu (truyền số 5 thay vì mặt nạ bit)
    LedControl_SetStatus(LED_GPIO_PORT, LED_PIN5, GPIO_PIN_LOW);

    while (1) {
        // Truyền BUTTON_PIN13 (số 13) thay vì BUTTON_GPIO_PIN
        if (ButtonRead_Status(BUTTON_GPIO_PORT, BUTTON_PIN13) == BTN_PRESS) {

            delay(); // Chống rung lần 1

            if (ButtonRead_Status(BUTTON_GPIO_PORT, BUTTON_PIN13) == BTN_PRESS) {

                // Đảo trạng thái
                current_led_status = !current_led_status;

                // Cập nhật trạng thái ra LED
                if (current_led_status == GPIO_PIN_HIGH) {
                    LedControl_SetStatus(LED_GPIO_PORT, LED_PIN5, GPIO_PIN_HIGH);
                } else {
                    LedControl_SetStatus(LED_GPIO_PORT, LED_PIN5, GPIO_PIN_LOW);
                }

                // Chờ cho đến khi nhả nút
                while (ButtonRead_Status(BUTTON_GPIO_PORT, BUTTON_PIN13) == BTN_PRESS);
            }
        }
    }
    return 0;
}

