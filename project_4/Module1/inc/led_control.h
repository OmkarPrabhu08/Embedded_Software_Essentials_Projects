/*
 * led_control.h
 *
 *  Created on: 03-May-2017
 *      Author: Omkar
 */
#include "MKL25Z4.h"
#include <stdint.h>
#ifndef INCLUDES_LED_CONTROL_H_
#define INCLUDES_LED_CONTROL_H_
#define SIM_SOPT2_MCGFLLCLK_MASK 0x1000000u

typedef enum{
GREEN_ON,
GREEN_OFF,
BLUE_ON,
BLUE_OFF,
RED_ON,
RED_OFF,
GREEN_BR,
BLUE_BR,
RED_BR,
SYSRESET,
EPOCH

} Cmds;
typedef struct{
Cmds command;
int8_t length;
int8_t *data;
int8_t checksum;
}CI_Msg;
void red_on(CI_Msg *Command);
void red_off(CI_Msg *Command);
void green_on(CI_Msg *Command);
void green_off(CI_Msg *Command);
void blue_on(CI_Msg *Command);
void blue_off(CI_Msg *Command);
void red_brightness(CI_Msg *Command);
void green_brightness(CI_Msg *Command);
void blue_brightness(CI_Msg *Command);




#endif /* INCLUDES_LED_CONTROL_H_ */
