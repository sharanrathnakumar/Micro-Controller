/*
 * File:   init_config.c
 * Author: sharan
 *
 * Created on 8 March, 2023, 6:28 PM
 */


#include <xc.h>

void init_config(void) {
    
    TRISD = 0x00;
    PORTD = 0X00;
}
