#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO 2 
#define BLINK_PERIOD_MS 1000 

void app_main(void)
{
    gpio_pad_select_gpio(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    int led_state = 0;
    while (1)
    {
        led_state = !led_state; 
        gpio_set_level(LED_GPIO, led_state); 

        printf("LED state: %d\n", led_state);

        vTaskDelay(BLINK_PERIOD_MS / portTICK_PERIOD_MS); 
    }
}
