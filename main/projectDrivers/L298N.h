// stepper_motor_encoder.h

#ifndef L298N_H
#define L298N_H

#include "esp_log.h"
#include <string.h>
#include "driver/gpio.h"
#include "driver/ledc.h"


#define IN1 GPIO_NUM_32
#define IN2 GPIO_NUM_33 
#define ENA GPIO_NUM_25 // almost all gpio pins are pwm capable 

// Function prototypes
void initGPIO();
void initPWM();
void initChannel();
void motorForward(int speed);
void motorBack(int speed);
void motorStop();

#endif 
