/*
 * File:   init_config.c
 * Author: sharan
 *
 * Created on 6 March, 2023, 11:32 PM
 */


#include "main.h"

void init_config(void) {
    TRISD = 0x00;
    PORTD = 0x00;
    TRISB = TRISB | 0x01;
}