#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <stdio.h>
#include "projectDrivers/L298N.h"

void app_main(void)
{
    initGPIO();
    initPWM();
    initChannel();

    int speed = 100;

    while(1)
    {
        motorBack(speed); // Move
        vTaskDelay(pdMS_TO_TICKS(2000)); // Move for 2 sec
        motorStop (); // Stop
        vTaskDelay(pdMS_TO_TICKS(1000)); // Wait 1 sec
    }
}
