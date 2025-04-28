#include "projectDrivers/L298N.h"

void initGPIO()
{
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL<<IN1) | (1ULL<<IN2),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };

    gpio_config(&io_conf);

}

void initPWM()
{
    // PWM setup for ENA
    ledc_timer_config_t motor_timer = {
        .duty_resolution = LEDC_TIMER_10_BIT,
        .freq_hz = 1000,                     // 1 kHz PWM frequency
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };

    ledc_timer_config(&motor_timer);
}

void initChannel()
{
    ledc_channel_config_t motor_channel = {
        .channel    = LEDC_CHANNEL_0,
        .duty       = 0,
        .gpio_num   = ENA,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_sel  = LEDC_TIMER_0
    };

    ledc_channel_config(&motor_channel);

}

void motorForward(int speed)
{
    int dutyCycle = (speed * 1023) / 100;

    // motor forward
    gpio_set_level(IN1, 1);
    gpio_set_level(IN2, 0);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, dutyCycle);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

    // // motor backward
    // gpio_set_level(IN1, 0);
    // gpio_set_level(IN2, 1);
    // dutyCycle = (speed * 1023) / 100;
    // ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, dutyCycle);
    // ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
   
}

void motorBack(int speed)
{
    int dutyCycle = (speed * 1023) / 100;
    gpio_set_level(IN1, 0);
    gpio_set_level(IN2, 1);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, dutyCycle);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

}


void motorStop()
{
    gpio_set_level(IN1, 0);
    gpio_set_level(IN2, 0);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 0);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

}