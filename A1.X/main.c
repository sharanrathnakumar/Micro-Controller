/*
 * File:   main.c
 * Author: sharan
 *
 * Created on 8 March, 2023, 6:27 PM
 */


#include <xc.h>
#include "main.h"
#pragma config WDTE=OFF
void main(void) 
{
    init_config();
    LED_ARRAY=OFF;
    int count=0; unsigned long int wait=0;    
    while(1)
    {
        if(wait++ == 100000)
        {
            if(count>=0 && count<=7)
            {
                LED_ARRAY= (LED_ARRAY << 1)|0x01;
            }
            else if(count>=8 && count<=15)
            {
                LED_ARRAY=LED_ARRAY << 1;
                
            }
            else if(count>=16 && count<=23)
            {
                LED_ARRAY = (LED_ARRAY >> 1)|0x80;
               
            }
            else if(count>=24 && count<=31) 
            {
                LED_ARRAY =LED_ARRAY>>1;
            }
            else
            {
                count=0;
            }
            count++;
            wait=0;
        }        
    }
    
}
